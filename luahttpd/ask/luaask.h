// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __LUA_ASK_H_NIJIE_2014_0624__
#define __LUA_ASK_H_NIJIE_2014_0624__

#include <string>

enum ELuaAsk
{
	LUA_ASK_MYSQL,
	LUA_ASK_HTTP,
	LUA_ASK_SERVER,
};

class HttpHandler;

class LuaAsk
{
public:
	LuaAsk(unsigned char type)
	{
		m_type = type;
		m_callback = 0;
		m_handler = NULL;
	}

	virtual ~LuaAsk(){}

	unsigned char getType()
	{
		return m_type;
	}

	void setHandler(HttpHandler* pHttp)
	{
		m_handler = pHttp;
	}

	HttpHandler* getHandler()
	{
		return m_handler;
	}

	bool isOK()
	{
		return true;
	}

	void setCallBack(int callback)
	{
		m_callback = callback;
	}

	int getCallBack()
	{
		return m_callback;
	}

private:
	unsigned char	m_type;
	int				m_callback;
	HttpHandler*	m_handler;
};

#endif	// __LUA_ASK_H_NIJIE_2014_0624__
