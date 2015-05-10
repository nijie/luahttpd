// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __CONFIG_H_NIJIE_2013_1119__
#define __CONFIG_H_NIJIE_2013_1119__

#include "markupstl.h"
#include <vector>
#include <string>
#include "fxtype.h"
#include "fxdb.h"

using namespace std;

#define MAX_CLIENT_PACKET_LEN (8 * 1024)

struct SHttpConfig 
{
	UINT32		uIP;
	UINT16		wPort;
	UINT32		uRecvBuf;
	UINT32		uSendBuf;
};

struct SSvrConfig 
{
	UINT32		uIP;
	UINT16		wPort;
	UINT32		uRecvBuf;
	UINT32		uSendBuf;
};

struct SDBMysqlInfo 
{
	UINT16		wCount;
	SDBConnInfo	sInfo;
};

class Config
{
public:
	Config();
	~Config();

	static Config&		Instance();
	bool				init();

	vector<SHttpConfig>&getHttpConfig();
	vector<SSvrConfig>&	getSvrConfig();
	vector<SDBMysqlInfo>& getMySqlConfig();
	UINT32				getMaxCount();
	string&				getDir();
	string&				getSessionDir();
	string&				getFDBDir();

private:
	UINT32				m_uCount;
	vector<SHttpConfig>	m_vecHttp;
	vector<SSvrConfig>	m_vecSvr;
	vector<SDBMysqlInfo>m_vecMysql;
	string				m_strDir;
	string				m_sessionDir;
	string				m_fdbDir;
};

#endif	// __CONFIG_H_NIJIE_2013_1119__
