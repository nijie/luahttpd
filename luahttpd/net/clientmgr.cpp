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

	m_index = 0;
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

	pClient->setId(++m_index);
	m_mapClient[m_index] = pClient;

	if (m_index >= 0xff0000)
	{
		m_index = 0;
	}
	
	return pClient;
}

void ClientMgr::releaseSession(Client* pClient)
{
	if (NULL == pClient)
	{
		return;
	}

	UINT32 id = pClient->getId();
	if (id != 0)
	{
		m_mapClient.erase(id);
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

void ClientMgr::update()
{
	unordered_map<unsigned int, Client*>::iterator it = m_mapClient.begin();
	for (; it != m_mapClient.end(); ++it)
	{
		Client* client = it->second;
		if (NULL == client)
		{
			continue;
		}
		
		if (0 != client->getTick())
		{
			client->decTick();
		}
		else
		{
			client->Close();
		}
	}
}
