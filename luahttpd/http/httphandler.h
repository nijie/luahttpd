// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __HTTPHANDLER__H_NIJIE_2014_0528__
#define __HTTPHANDLER__H_NIJIE_2014_0528__

#include "httpparser.h"
#include "httpresponse.h"

#include "inlsys.h"

class Session;
class LuaAsk;
class Client;

class HttpHandler
{
public:
	HttpHandler();
	~HttpHandler();

	bool			init(Client* pClient, const char* pBuf);
	void			reset();

	// export start
	const char*		get(int type);
	const char*		get(const char* key);

	void			setValue(const char* pKey, const char* pVal);
	const char*		getValue(const char* pKey);

	void			setResponse(int type, const char* pBuf);

	void			setCookie(const char* key, const char* val);
	const char*		getCookie(const char* key);

	Session*		getSession();
	// export end

	void			appendResponse(const char* pbuf);
	bool			addAsk(LuaAsk* ask, int nCallbackId = 0);
	string&			getCmd();
	void			doing();
	void			getResponse(string& str);
	void			getCookie(string& str);
	int				getCallbackCount();
	void			incCallbackCount();
	void			decCallbackCount();
	
	void			response();

private:
	HttpParser		m_parse;
	HttpResponse	m_response;
	string			m_strCmd;		// «Î«Ûµƒ√¸¡Ó
	hash_map<string, string> m_mapRequest;
	hash_map<string, string> m_mapCookie;
	hash_map<string, string> m_mapValue;
	int				m_nCallBackCount;
	Session*		m_pSession;
	Client*			m_pClient;
};

#endif	// __HTTPHANDLER__H_NIJIE_2014_0528__
