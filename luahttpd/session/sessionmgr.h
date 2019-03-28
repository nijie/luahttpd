// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __SESSIONMGR_H_NIJIE_2014_0603__
#define __SESSIONMGR_H_NIJIE_2014_0603__

#include "session.h"
#include "dynamicpoolex.h"
#include "leveldb.h"
#include <tr1/unordered_map>

using namespace std::tr1;

class SessionMgr
{
public:
	SessionMgr();
	~SessionMgr();

	static SessionMgr& Instance();

	bool			init();
	void			uninit();

	Session*		createSession();
	Session*		createSession(UINT64 sid);
	Session*		findSession(UINT64 sid);
	void			releaseSession(Session* pSession);

	void			update(unsigned int interval);
	void			save(Session* pSession);

private:
	unordered_map<unsigned int, Session*> m_mapSession;
	TDynamicPoolEx<Session>	m_poolSession;
	leveldb::DB*			m_db;
	leveldb::ReadOptions	m_readOpt;
	leveldb::WriteOptions	m_writeOpt;

	unsigned int			m_uCurSId;
	unsigned int			m_uOldSId;
};

#endif	// __SESSIONMGR_H_NIJIE_2014_0603__
