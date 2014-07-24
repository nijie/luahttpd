// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "servermgr.h"

ServerMgr::ServerMgr()
{

}

ServerMgr::~ServerMgr()
{

}

bool ServerMgr::init()
{
	return true;
}

ServerMgr& ServerMgr::Instance()
{
	static ServerMgr o;
	return o;
}

FxSession* ServerMgr::CreateSession()
{
	return new Server;
}

void ServerMgr::releaseSession(Server* pServer)
{
	if (NULL == pServer)
	{
		return;
	}

	delete pServer;
}

