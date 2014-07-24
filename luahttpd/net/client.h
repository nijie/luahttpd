// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __CLIENT_H_NIJIE_2013_1119__
#define __CLIENT_H_NIJIE_2013_1119__

#include "ifnet.h"

class HttpHandler;

class Client : public FxSession
{
public:
	Client();
	virtual ~Client();

	bool				init();
	void				reset();

	virtual void        OnConnect(void);
	virtual void        OnClose(void);
	virtual void        OnError(UINT32 dwErrorNo);
	virtual void        OnRecv(const char* pBuf, UINT32 dwLen);
	virtual void        Release(void);
	virtual char*       GetRecvBuf();
	virtual UINT32      GetRecvSize();

private:
	HttpHandler*		m_handler;
};

#endif	// __CLIENT_H_NIJIE_2013_1119__
