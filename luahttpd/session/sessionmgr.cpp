// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "sessionmgr.h"
#include "config.h"
#include "exelogger.h"
#include <time.h>
#include "../crypto/keymaker.h"
#include "utility.h"

#define MAX_SESSIONID_DIFF 256
#define DEFAULT_SESSION_TIME (24 * 60 * 60)

SessionMgr::SessionMgr()
{
	m_mapSession.set_empty_key(0);
	m_mapSession.set_deleted_key(-1);
	m_db = NULL;
}

SessionMgr::~SessionMgr()
{

}

SessionMgr& SessionMgr::Instance()
{
	static SessionMgr o;
	return o;
}

bool SessionMgr::init()
{
	string& strSessionDir = Config::Instance().getSessionDir();

	leveldb::Options options;
	options.create_if_missing = true;
	options.write_buffer_size = 64 * 1024* 1024;
	string dbname = "session";
	leveldb::Status status = leveldb::DB::Open(options, strSessionDir + dbname, &m_db);
	if (!status.ok())
	{
		SYS_CRITICAL("Open Session DB failed!");
		leveldb::RepairDB(strSessionDir + dbname, options);
		return false;
	}
	
	if (!m_poolSession.Init(4096, 4096, true))
	{
		return false;
	}

	string strData;
	leveldb::Status ret = m_db->Get(m_readOpt, "sessionId", &strData);
	if (!ret.ok())
	{
		m_uCurSId = 1;
	}
	else
	{
		m_uCurSId = *(UINT32*)strData.c_str() + MAX_SESSIONID_DIFF;
	}
	m_uOldSId = m_uCurSId;

	return true;
}

void SessionMgr::uninit()
{
	if (m_db)
	{
		delete m_db;
		m_db = NULL;
	}
}

Session* SessionMgr::createSession()
{
	Session* pSession = m_poolSession.FetchObj();
	if (NULL == pSession)
	{
		return NULL;
	}

	SKeyInfo key;
	key.nKey[0] = GetCurTime();
	key.nKey[1] = m_uCurSId;

	if (!pSession->init(key.qKey))
	{
		releaseSession(pSession);
		return NULL;
	}

	pSession->setDestroyTime(key.nKey[0] + DEFAULT_SESSION_TIME);

	m_mapSession[key.nKey[1]] = pSession;

	++m_uCurSId;
	if (0 == m_uCurSId || -1 == m_uCurSId)
	{
		m_uCurSId = 1;
	}

	UINT32 uDiff = (m_uCurSId > m_uOldSId) ? (m_uCurSId - m_uOldSId) : (0xffffffff - m_uOldSId + m_uCurSId);
	if (uDiff >= MAX_SESSIONID_DIFF)
	{
		string strData;
		strData.append((char*)&m_uCurSId, sizeof(m_uCurSId));
		leveldb::Status ret = m_db->Put(m_writeOpt, "sessionId", strData);
		m_uOldSId = m_uCurSId;
	}

	return pSession;
}

Session* SessionMgr::createSession(UINT64 sid)
{
	Session* pSession = m_poolSession.FetchObj();
	if (NULL == pSession)
	{
		return NULL;
	}

	SKeyInfo key;
	key.qKey = sid;

	if (!pSession->init(key.qKey))
	{
		releaseSession(pSession);
		return false;
	}

	m_mapSession[key.nKey[1]] = pSession;

	return pSession;
}

Session* SessionMgr::findSession(UINT64 sid)
{
	if (0 == sid)
	{
		return NULL;
	}

	SKeyInfo key;
	key.qKey = sid;

	Session* pSession = NULL;

	// find from memory
	google::dense_hash_map<unsigned int, Session*>::iterator it = m_mapSession.find(key.nKey[1]);
	if (it != m_mapSession.end())
	{
		pSession = it->second;
		if (NULL != pSession)
		{
			if (sid == pSession->getSId())
			{
				return pSession;
			}
			pSession = NULL;
		}
	}

	if (NULL == pSession)
	{// find from localdb
		string strData;
		leveldb::Status ret = m_db->Get(m_readOpt, key.nKey[1], &strData);
		if (ret.ok())
		{
			UINT32 len = (UINT32)strData.size();
			if (len >= sizeof(SSessionTime))
			{
				SSessionTime* pTime = (SSessionTime*)strData.c_str();
				if (pTime->uCreateTime == key.nKey[0])
				{// load session
					pSession = createSession(sid);
					if (NULL == pSession)
					{
						return NULL;
					}

					if (!pSession->loadData(strData.c_str(), len))
					{
						releaseSession(pSession);
						return NULL;
					}
					
					return pSession;
				}
			}
		}
	}

	return NULL;
}

void SessionMgr::releaseSession(Session* pSession)
{
	unsigned __int64 sid = pSession->getSId();

	SKeyInfo key;
	key.qKey = sid;
	if (key.nKey[1] != 0)
	{
		m_mapSession.erase(key.nKey[1]);
	}

	m_poolSession.ReleaseObj(pSession);
}

void SessionMgr::update(unsigned int interval)
{
	google::dense_hash_map<unsigned int, Session*>::iterator it = m_mapSession.begin();
	while (it != m_mapSession.end())
	{
		Session* pSession = it->second;
		if (NULL == pSession)
		{
			m_mapSession.erase(it++);
			continue;
		}

		if (pSession->canClear(interval))
		{
			m_poolSession.ReleaseObj(pSession);

			m_mapSession.erase(it++);
			continue;
		}

		++it;
	}
}

void SessionMgr::save(Session* pSession)
{
	if (NULL == pSession)
	{
		return;
	}

	unsigned __int64 sid = pSession->getSId();
	if (0 == sid)
	{
		return;
	}

	SKeyInfo key;
	key.qKey = sid;

	unsigned int now = GetCurTime();
	if (now >= pSession->getDestroyTime())
	{
		m_db->Delete(m_writeOpt, key.nKey[1]);
		return;
	}

	string& str = pSession->getData();
	if (str.empty())
	{
		return;
	}

	static char szSaveBuff[1024 * 32];
	SSessionTime* pTime = (SSessionTime*)szSaveBuff;
	pTime->uCreateTime = key.nKey[0];
	pTime->uDestroyTime = pSession->getDestroyTime();
	
	memcpy(szSaveBuff + sizeof(SSessionTime), str.c_str(), str.size());

	string strData;
	strData.append(szSaveBuff, sizeof(SSessionTime) + str.size());
	leveldb::Status ret = m_db->Put(m_writeOpt, key.nKey[1], strData);
	if (!ret.ok())
	{
		SYS_CRITICAL("save session failed, sid = %llu", sid);
	}
}
