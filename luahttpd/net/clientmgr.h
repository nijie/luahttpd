// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __CLIENTMGR_H_NIJIE_2013_1119__
#define __CLIENTMGR_H_NIJIE_2013_1119__

#include "dynamicpoolex.h"
#include "client.h"
#include "ifnet.h"
#include "../http/httphandler.h"
#include <tr1/unordered_map>

using namespace std::tr1;

class ClientMgr : public IFxSessionFactory
{
public:
	ClientMgr();
	virtual ~ClientMgr();

	bool				init();
	static ClientMgr&	Instance();

	virtual FxSession*  CreateSession();
	void				releaseSession(Client* pClient);

	HttpHandler*		CreateHttpHandler();
	void				releaseHttpHandler(HttpHandler* pHttp);
	
	void				update();
	
private:
	unsigned int		m_index;
	TDynamicPoolEx<Client>	m_poolClient;
	TDynamicPoolEx<HttpHandler>	m_poolHttp;
	unordered_map<unsigned int, Client*> m_mapClient;
};

#endif	// __CLIENTMGR_H_NIJIE_2013_1119__
