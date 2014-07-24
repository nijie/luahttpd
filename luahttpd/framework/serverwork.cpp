// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "serverwork.h"
#include "stdafx.h"
#include "ifnet.h"
#include "config.h"
#include "exelogger.h"
#include "../net/clientmgr.h"
#include "../net/servermgr.h"
#include "../http/httpparser.h"
#include "../script/luascript.h"
#include "utility.h"
#include "../session/sessionmgr.h"
#include "version.h"

#define UPDATE_SESSION_TIME (5 * 60) // 5分钟

ServerWork::ServerWork()
{
	m_pNet = NULL;
	m_pDB = NULL;
}

ServerWork::~ServerWork()
{

}

ServerWork& ServerWork::Instance()
{
	static ServerWork o;
	return o;
}

bool ServerWork::init()
{
	if (!Config::Instance().init())
	{
		SYS_CRITICAL("Config Load Error!");
		return false;
	}

	if (!HttpParser::Init())
	{
		SYS_CRITICAL("HttpParser Init Failed!");
		return false;
	}

	if (!ClientMgr::Instance().init())
	{
		SYS_CRITICAL("ClientMgr Init Failed!");
		return false;
	}

	if (!ServerMgr::Instance().init())
	{
		SYS_CRITICAL("ServerMgr Init Failed!");
		return false;
	}

	if (!SessionMgr::Instance().init())
	{
		SYS_CRITICAL("ServerMgr Init Failed!");
		return false;
	}

	if (!LuaScript::Instance().init())
	{
		SYS_CRITICAL("LuaScript Init Failed!");
		return false;
	}

	if (!__initModule())
	{
		SYS_CRITICAL("net module init Error!");
		return false;
	}

	return true;
}

void ServerWork::uninit()
{
	__uninitModule();
}

void ServerWork::run()
{
	SYS_CRITICAL("--------------- Server [%s] Starting ---------------", LUAHTTPD_VERSION);
	printf("--------------- Server [v%s] Starting ---------------\r\n", LUAHTTPD_VERSION);
	if (!__start())
	{
		return;
	}

	SYS_CRITICAL("--------------- Server Start ! ---------------");
	printf("--------------- Server Start ! ---------------\r\n");

	unsigned int now = GetCurTime();
	unsigned int last = now;
	while (true)
	{
		if (!m_pNet->Run(1000))
		{
			FxSleep(1);
		}

		if (!m_pDB->Run(1000))
		{
			FxSleep(1);
		}

		now = GetCurTime();

		if (now - last >= UPDATE_SESSION_TIME)
		{
			SessionMgr::Instance().update(UPDATE_SESSION_TIME);
			last = now;
		}
	}
}

bool ServerWork::__start()
{
	if (NULL == m_pNet)
	{
		SYS_CRITICAL("FxNet is NULL");
		return false;
	}

	if (NULL == m_pDB)
	{
		SYS_CRITICAL("FxDB is NULL");
		return false;
	}

	vector<SHttpConfig>& httpConfig = Config::Instance().getHttpConfig();
	int nCount = (int)httpConfig.size();
	for (int i = 0; i < nCount; i++)
	{
		SHttpConfig& http = httpConfig[i];
		m_pNet->Listen(&ClientMgr::Instance(), http.uIP, http.wPort, http.uRecvBuf, http.uSendBuf, false, 32); 
	}

	vector<SSvrConfig>& svrConfig = Config::Instance().getSvrConfig();
	nCount = (int)svrConfig.size();
	for (int i = 0; i < nCount; i++)
	{
		SSvrConfig& svr = svrConfig[i];
		m_pNet->Listen(&ServerMgr::Instance(), svr.uIP, svr.wPort, svr.uRecvBuf, svr.uSendBuf);
	}

	m_mapMysqlSN.clear();
	vector<SDBMysqlInfo>& mysqlConfig = Config::Instance().getMySqlConfig();
	nCount = (int)mysqlConfig.size();
	int mysqlsn = 0;
	for (int i = 0; i < nCount; i++)
	{
		SDBMysqlInfo& info = mysqlConfig[i];
		if (info.wCount == 0)
		{
			SYS_CRITICAL("open dbname [%s] failed, count = 0", info.sInfo.m_stAccount.m_szDBName);
			return false;
		}
		if (m_mapMysqlSN.find(info.sInfo.m_stAccount.m_szDBName) != m_mapMysqlSN.end())
		{// 已经有了。不能加载相同的数据库
			SYS_CRITICAL("open dbname [%s] again!", info.sInfo.m_stAccount.m_szDBName);
			return false;
		}

		SDBMysqlSN sn = {0};
		sn.nBaseSN = mysqlsn;
		sn.wCount = info.wCount;
		m_mapMysqlSN[info.sInfo.m_stAccount.m_szDBName] = sn;
		for (UINT16 j = 0; j < info.wCount; j++)
		{
			info.sInfo.m_dwDBId = mysqlsn++;
			if(!m_pDB->Open(info.sInfo))
			{
				SYS_CRITICAL("open dbname [%s] failed!", info.sInfo.m_stAccount.m_szDBName);
				return false;
			}
		}
	}

	return true;
}

bool ServerWork::__initModule()
{
	// net module
	m_pNet = FxNetGetModule();
	if(m_pNet == NULL)
	{
		SYS_CRITICAL("FxNetGetModule failed!");
		return false;
	}

	if (!m_pNet->SetNetOpt(ENET_MAX_CONNECTION, Config::Instance().getMaxCount() + 32))
	{
		SYS_CRITICAL("NetModule Set ENET_MAX_CONNECTION 8000 failed!");
		return false;
	}

	if (!m_pNet->SetNetOpt(ENET_MAX_TOTALEVENT, 32 * 1024 * 1024))
	{
		SYS_CRITICAL("NetModule Set ENET_MAX_TOTALEVENT 32 * 1024 * 1024 failed!");
		return false;
	}

	if (!m_pNet->Init())
	{
		SYS_CRITICAL("NetModule Init failed!\n");
		return false;
	}

	// mysql DB module
	m_pDB = FxDBGetModule();
	if (NULL == m_pDB)
	{
		SYS_CRITICAL("FxDBGetModule failed!");
		return false;
	}

	return true;
}

void ServerWork::__uninitModule()
{
	if (NULL != m_pNet)
	{
		m_pNet->Release();
		m_pNet = NULL;
	}

	if (NULL != m_pDB)
	{
		m_pDB->Release();
		m_pDB = NULL;
	}
}

bool ServerWork::addDBQuery(IQuery* pQuery)
{
	if (NULL == pQuery)
	{
		return false;
	}

	if (NULL == m_pDB)
	{
		return false;
	}

	return m_pDB->AddQuery(pQuery);
}

SDBMysqlSN* ServerWork::getBaseMysqlSN(const char* dbname)
{
	if (NULL == dbname)
	{
		return NULL;
	}

	map<string, SDBMysqlSN>::iterator it = m_mapMysqlSN.find(dbname);
	if (it == m_mapMysqlSN.end())
	{
		return NULL;
	}

	return &(it->second);
}
