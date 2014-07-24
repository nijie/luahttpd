// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "clientmgr.h"
#include "../framework/config.h"

ClientMgr::ClientMgr()
{

}

ClientMgr::~ClientMgr()
{

}

bool ClientMgr::init()
{
	UINT32 uMaxCount = Config::Instance().getMaxCount();
	if (!m_poolClient.Init(uMaxCount / 2, uMaxCount / 4))
	{
		return false;
	}

	if (!m_poolHttp.Init(uMaxCount / 2, uMaxCount / 4))
	{
		return false;
	}

	return true;
}

ClientMgr& ClientMgr::Instance()
{
	static ClientMgr o;
	return o;
}

FxSession* ClientMgr::CreateSession()
{
	Client* pClient = m_poolClient.FetchObj();
	if (NULL == pClient)
	{
		return NULL;
	}

	if (!pClient->init())
	{
		releaseSession(pClient);
		return NULL;
	}

	return pClient;
}

void ClientMgr::releaseSession(Client* pClient)
{
	if (NULL == pClient)
	{
		return;
	}

	pClient->reset();
	m_poolClient.ReleaseObj(pClient);
}

HttpHandler* ClientMgr::CreateHttpHandler()
{
	HttpHandler* pHttp = m_poolHttp.FetchObj();
	return pHttp;
}

void ClientMgr::releaseHttpHandler(HttpHandler* pHttp)
{
	if (NULL == pHttp)
	{
		return;
	}

	pHttp->reset();
	m_poolHttp.ReleaseObj(pHttp);
}
