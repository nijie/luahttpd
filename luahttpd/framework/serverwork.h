// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __SERVERWORK_H_NIJIE_2013_0819__
#define __SERVERWORK_H_NIJIE_2013_0819__

#include <ifnet.h>
#include <ifhttp.h>
#include "../ask/dbask.h"
#include <map>

using namespace std;

class ServerWork 
{
public:
	ServerWork();
	~ServerWork();

	static ServerWork&	Instance();

	bool				init();
	void				uninit();
	void				run();

	bool				addDBQuery(IQuery* pQuery);
	bool				addHttpRequest(Request* pRequest);
	SDBMysqlSN*			getBaseMysqlSN(const char* dbname);

private:
	bool				__initModule();
	void				__uninitModule();
	bool				__start();

private:
	IFxNet*				m_pNet;
	IDBModule*			m_pDB;
	IHttp*				m_pHttp;

	map<string, SDBMysqlSN>	m_mapMysqlSN;
};

#endif	// __SERVERWORK_H_NIJIE_2013_0819__
