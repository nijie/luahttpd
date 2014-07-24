// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "server.h"
#include "servermgr.h"

Server::Server()
{

}

Server::~Server()
{

}

void Server::OnConnect(void)
{

}

void Server::OnClose(void)
{

}

void Server::OnError(UINT32 dwErrorNo)
{

}

void Server::OnRecv(const char* pBuf, UINT32 dwLen)
{

}

void Server::Release(void)
{
	ServerMgr::Instance().releaseSession(this);
}

char* Server::GetRecvBuf()
{
	static char s_buff[4096];
	return s_buff;
}

UINT32 Server::GetRecvSize()
{
	return 4096;
}
