// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __SERVER_H_NIJIE_2013_1119__
#define __SERVER_H_NIJIE_2013_1119__

#include "ifnet.h"

class Server : public FxSession
{
public:
	Server();
	virtual ~Server();

	virtual void        OnConnect(void);
	virtual void        OnClose(void);
	virtual void        OnError(UINT32 dwErrorNo);
	virtual void        OnRecv(const char* pBuf, UINT32 dwLen);
	virtual void        Release(void);
	virtual char*       GetRecvBuf();
	virtual UINT32      GetRecvSize();

private:
};

#endif	// __SERVER_H_NIJIE_2013_1119__
