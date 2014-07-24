// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __SERVERMGR_H_NIJIE_2013_1119__
#define __SERVERMGR_H_NIJIE_2013_1119__

#include "ifnet.h"
#include "server.h"

class ServerMgr : public IFxSessionFactory
{
public:
	ServerMgr();
	virtual ~ServerMgr();

	bool				init();
	static ServerMgr&	Instance();

	virtual FxSession*  CreateSession();
	void				releaseSession(Server* pServer);

private:

};

#endif	// __SERVERMGR_H_NIJIE_2013_1119__
