// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "stdafx.h"
#include "httpresponse.h"
#include "httpparser.h"
#include <time.h>

HttpResponse::HttpResponse()
{

}

HttpResponse::~HttpResponse()
{

}

bool HttpResponse::init(HttpParser& http)
{
	m_arValues[HTTP_RESPONSE_HTTP] = http.get(HTTP_HEAD_HTTP);
	m_arValues[HTTP_RESPONSE_CODE] = "200 OK";
	m_arValues[HTTP_RESPONSE_SERVER] = "LHTTPD/";
	m_arValues[HTTP_RESPONSE_SERVER] += LHTTPD_VERSION;
	m_arValues[HTTP_RESPONSE_SERVER] += " (Win64)";
	m_arValues[HTTP_RESPONSE_X_POWERED] = "Lua/5.2";
	m_arValues[HTTP_RESPONSE_KEEP_ALIVE] = "timeout=5, max=100";
	m_arValues[HTTP_RESPONSE_CONNECTION] = http.get(HTTP_HEAD_CONNECTION);
	m_arValues[HTTP_RESPONSE_TRANSFER_ENCODING] = "chunked";
	m_arValues[HTTP_RESPONSE_CONTENT_TYPE] = "text/html";

	return true;
}

void HttpResponse::set(int type, string& str)
{
	if (type < 0 || type >= HTTP_RESPONSE_SIZE)
	{
		return;
	}

	m_arValues[type] = str;
}

void HttpResponse::getText(string& str)
{
	for (int i = 0; i < HTTP_RESPONSE_SIZE; ++i)
	{
		if (i != HTTP_RESPONSE_HTTP)
		{
			if (!m_arValues[i].empty())
			{
				str += s_arKeys[i] + m_arValues[i] + "\r\n";
			}
		}
		else
		{
			str += s_arKeys[i] + m_arValues[i];
		}
	}
}

void HttpResponse::reset()
{
	// 因为要重用，所以用完之后需要重置
	for (int i = 0; i < HTTP_RESPONSE_SIZE; ++i)
	{
		m_arValues[i].clear();
	}
}

void HttpResponse::appendResponse(const char* pdata)
{
	if (NULL == pdata)
	{
		return;
	}
	m_arValues[HTTP_RESPONSE_DATA].append(pdata);
}

