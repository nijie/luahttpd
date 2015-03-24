// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include <WinSock2.h>
#include "config.h"
#include "exelogger.h"
#include "utility.h"

#define SVR_CONFIG "svrconf.xml"

Config::Config()
{

}

Config::~Config()
{

}

Config& Config::Instance()
{
	static Config o;
	return o;
}

bool Config::init()
{
	CMarkupSTL oXml;
	string strValue;
	if (!oXml.Load(SVR_CONFIG))
	{
		SYS_CRITICAL("Load %s Error", SVR_CONFIG);
		return false;
	}
	oXml.ResetMainPos();
	if (!oXml.FindElem("config"))
	{
		SYS_CRITICAL("Can not Find Config in ConfigServer");
		return false;
	}
	if (!oXml.IntoElem())
	{
		SYS_CRITICAL("Can not into elem");
		return false;
	}

	if (!oXml.FindElem("http"))
	{
		SYS_CRITICAL("Can not Find http in ConfigServer");
		return false;
	}

	strValue = oXml.GetAttrib("count");
	m_uCount = atoi(strValue.c_str());
	m_strDir = oXml.GetAttrib("dir");

	m_sessionDir = oXml.GetAttrib("session");
	if (!m_sessionDir.empty())
	{
		m_sessionDir += "/";
	}
	else
	{
		m_sessionDir = "session/";
	}

	m_fdbDir = oXml.GetAttrib("fdb");
	if (!m_fdbDir.empty())
	{
		m_fdbDir += "/";
	}
	else
	{
		m_fdbDir = "fdb/";
	}

	if (!oXml.IntoElem())
	{
		SYS_CRITICAL("Can not into elem");
		return false;
	}

	while(oXml.FindElem("item"))
	{
		SHttpConfig http = {0};
		strValue = oXml.GetAttrib("ip");
		http.uIP = inet_addr(strValue.c_str());

		strValue = oXml.GetAttrib("port");
		http.wPort = atoi(strValue.c_str());

		strValue = oXml.GetAttrib("recvbuf");
		http.uRecvBuf = atoi(strValue.c_str());
		if (MAX_CLIENT_PACKET_LEN < http.uRecvBuf)
		{
			http.uRecvBuf = MAX_CLIENT_PACKET_LEN;
		}

		strValue = oXml.GetAttrib("sendbuf");
		http.uSendBuf = atoi(strValue.c_str());

		m_vecHttp.push_back(http);
	}
	oXml.OutOfElem();

	if (oXml.FindElem("db"))
	{
		strValue = oXml.GetAttrib("type");
		if (strValue == "mysql")
		{
			if (!oXml.IntoElem())
			{
				SYS_CRITICAL("Can not into elem");
				return false;
			}

			while(oXml.FindElem("item"))
			{
				SDBMysqlInfo info = {0};
				strValue = oXml.GetAttrib("ip");
				copystr(info.sInfo.m_stAccount.m_szHostName, strValue.c_str());

				strValue = oXml.GetAttrib("port");
				info.sInfo.m_stAccount.m_wConnPort = atoi(strValue.c_str());

				strValue = oXml.GetAttrib("user");
				copystr(info.sInfo.m_stAccount.m_szLoginName, strValue.c_str());

				strValue = oXml.GetAttrib("pwd");
				copystr(info.sInfo.m_stAccount.m_szLoginPwd, strValue.c_str());

				strValue = oXml.GetAttrib("dbname");
				copystr(info.sInfo.m_stAccount.m_szDBName, strValue.c_str());

				strValue = oXml.GetAttrib("char");
				copystr(info.sInfo.m_stAccount.m_szCharactSet, strValue.c_str());

				strValue = oXml.GetAttrib("count");
				info.wCount = atoi(strValue.c_str());

				if (info.wCount == 0)
				{
					info.wCount = 1;
				}

				m_vecMysql.push_back(info);
			}
			oXml.OutOfElem();
		}
	}

	if (!oXml.FindElem("server"))
	{
		SYS_CRITICAL("Can not Find server in ConfigServer");
		return false;
	}

	if (!oXml.IntoElem())
	{
		SYS_CRITICAL("Can not into elem");
		return false;
	}

	while(oXml.FindElem("item"))
	{
		SSvrConfig svr = {0};
		strValue = oXml.GetAttrib("ip");
		svr.uIP = inet_addr(strValue.c_str());

		strValue = oXml.GetAttrib("port");
		svr.wPort = atoi(strValue.c_str());

		strValue = oXml.GetAttrib("recvbuf");
		svr.uRecvBuf = atoi(strValue.c_str());

		strValue = oXml.GetAttrib("sendbuf");
		svr.uSendBuf = atoi(strValue.c_str());

		m_vecSvr.push_back(svr);
	}
	oXml.OutOfElem();
	return true;
}

vector<SHttpConfig>& Config::getHttpConfig()
{
	return m_vecHttp;
}

vector<SSvrConfig>& Config::getSvrConfig()
{
	return m_vecSvr;
}

UINT32 Config::getMaxCount()
{
	return m_uCount;
}

string& Config::getDir()
{
	return m_strDir;
}

string& Config::getSessionDir()
{
	return m_sessionDir;
}

vector<SDBMysqlInfo>& Config::getMySqlConfig()
{
	return m_vecMysql;
}

string& Config::getFDBDir()
{
	return m_fdbDir;
}
