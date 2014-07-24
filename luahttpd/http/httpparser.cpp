// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "httpparser.h"

MatchTree* HttpParser::ms_pMatchTree = NULL;
FN_HTTP_HEAD_PARSE HttpParser::ms_arFuns[HTTP_HEAD_SIZE] = {0};
HttpParser::HttpParser()
{

}

HttpParser::~HttpParser()
{

}

bool HttpParser::Init()
{
	ms_pMatchTree = new MatchTree(0);
	ms_arFuns[HTTP_HEAD_URL] = NULL;
	
	ms_pMatchTree->add("GET ", HTTP_HEAD_GET);
	ms_arFuns[HTTP_HEAD_GET] = ParseHttpHeadSpace;

	ms_pMatchTree->add("POST ", HTTP_HEAD_POST);
	ms_arFuns[HTTP_HEAD_POST] = ParseHttpHeadSpace;
	
	ms_pMatchTree->add("HTTP", HTTP_HEAD_HTTP);
	ms_arFuns[HTTP_HEAD_HTTP] = ParseHttpHeadLRN;

	ms_pMatchTree->add("Accept:", HTTP_HEAD_ACCEPT);
	ms_arFuns[HTTP_HEAD_ACCEPT] = ParseHttpHeadLRN;
	
	ms_pMatchTree->add("Accept-Charset:", HTTP_HEAD_ACCEPT_CHARSET);
	ms_arFuns[HTTP_HEAD_ACCEPT_CHARSET] = ParseHttpHeadLRN;
	
	ms_pMatchTree->add("Accept-Encoding:", HTTP_HEAD_ACCEPT_ENCODING);
	ms_arFuns[HTTP_HEAD_ACCEPT_ENCODING] = ParseHttpHeadLRN;
	
 	ms_pMatchTree->add("Accept-Language:", HTTP_HEAD_ACCEPT_LANGUAGE);
	ms_arFuns[HTTP_HEAD_ACCEPT_LANGUAGE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Accept-Ranges:", HTTP_HEAD_ACCEPT_RANGES);
	ms_arFuns[HTTP_HEAD_ACCEPT_RANGES] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Authorization:", HTTP_HEAD_AUTHORIZATION);
	ms_arFuns[HTTP_HEAD_AUTHORIZATION] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Cache-Control:", HTTP_HEAD_CACHE_CONTROL);
	ms_arFuns[HTTP_HEAD_CACHE_CONTROL] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Connection:", HTTP_HEAD_CONNECTION);
	ms_arFuns[HTTP_HEAD_CONNECTION] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Cookie:", HTTP_HEAD_COOKIE);
	ms_arFuns[HTTP_HEAD_COOKIE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Content-Length:", HTTP_HEAD_CONTENT_LENGTH);
	ms_arFuns[HTTP_HEAD_CONTENT_LENGTH] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Content-Type:", HTTP_HEAD_CONTENT_TYPE);
	ms_arFuns[HTTP_HEAD_CONTENT_TYPE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Date:", HTTP_HEAD_DATE);
	ms_arFuns[HTTP_HEAD_DATE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Expect:", HTTP_HEAD_EXPECT);
	ms_arFuns[HTTP_HEAD_EXPECT] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("From:", HTTP_HEAD_FROM);
	ms_arFuns[HTTP_HEAD_FROM] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Host:", HTTP_HEAD_HOST);
	ms_arFuns[HTTP_HEAD_HOST] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("If-Match:", HTTP_HEAD_IF_MATCH);
	ms_arFuns[HTTP_HEAD_IF_MATCH] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("If-Modified-Since:", HTTP_HEAD_IF_MODIFIED_SINCE);
	ms_arFuns[HTTP_HEAD_IF_MODIFIED_SINCE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("If-None-Match:", HTTP_HEAD_IF_NONE_MATCH);
	ms_arFuns[HTTP_HEAD_IF_NONE_MATCH] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("If-Range:", HTTP_HEAD_RANGE);
	ms_arFuns[HTTP_HEAD_RANGE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("If-Unmodified-Since:", HTTP_HEAD_IF_UNMODIFIED_SINCE);
	ms_arFuns[HTTP_HEAD_IF_UNMODIFIED_SINCE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Max-Forwards:", HTTP_HEAD_MAX_FORWARDS);
	ms_arFuns[HTTP_HEAD_MAX_FORWARDS] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Pragma:", HTTP_HEAD_PRAGMA);
	ms_arFuns[HTTP_HEAD_PRAGMA] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Proxy-Authorization:", HTTP_HEAD_PROXY_AUTHORIZATION);
	ms_arFuns[HTTP_HEAD_PROXY_AUTHORIZATION] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Range:", HTTP_HEAD_RANGE);
	ms_arFuns[HTTP_HEAD_RANGE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Referer:", HTTP_HEAD_REFERER);
	ms_arFuns[HTTP_HEAD_REFERER] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("TE:", HTTP_HEAD_TE);
	ms_arFuns[HTTP_HEAD_TE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Upgrade:", HTTP_HEAD_UPGRADE);
	ms_arFuns[HTTP_HEAD_UPGRADE] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("User-Agent:", HTTP_HEAD_USER_AGENT);
	ms_arFuns[HTTP_HEAD_USER_AGENT] = ParseHttpHeadLRN;

 	ms_pMatchTree->add("Via:", HTTP_HEAD_VIA);
	ms_arFuns[HTTP_HEAD_VIA] = ParseHttpHeadLRN;

	ms_pMatchTree->add("Warning", HTTP_HEAD_WARNING);
	ms_arFuns[HTTP_HEAD_WARNING] = ParseHttpHeadLRN;

	ms_pMatchTree->add("\r\n", HTTP_HEAD_POST_DATA);
	ms_arFuns[HTTP_HEAD_POST_DATA] = ParseHttpHeadLRN;
	return true;
}

int HttpParser::ParseHttpHeadSpace(string& strVal, const char* pszBuf)
{
	if (NULL == pszBuf)
	{
		return 0;
	}

	int nCur = 0;
	char ch = 0;
	for (nCur = 0; (ch = *(pszBuf + nCur)) != 0; ++nCur)	
	{
		if (ch == ' ')
		{
			break;
		}
		strVal.push_back(ch);
	}
	return ++nCur;
}

int HttpParser::ParseHttpHeadLRN(string& strVal, const char* pszBuf)
{
	if (NULL == pszBuf)
	{
		return 0;
	}

	char ch = 0;
	int nCur = 0;
	for (nCur = 0; (ch = *(pszBuf + nCur)) != 0; ++nCur)
	{
		if (ch == ' ')
		{
			continue;
		}

		if (ch == '\r')
		{
			char ch2 = *(pszBuf + nCur + 1);
			if (ch2 == '\n')
			{
				++nCur;
			}
			break;
		}

		strVal.push_back(ch);
	}
	return ++nCur;
}

bool HttpParser::parse(const char* pszBuf)
{
	if (NULL == ms_pMatchTree)
	{
		return false;
	}

	const char* pszCur = pszBuf;
	while (*pszCur != 0)
	{
		MTYPE type = ms_pMatchTree->find(pszCur);
		if (type == NO_MATCH_CHAR)
		{
			break;
		}

		if (ms_arFuns[type] != NULL)
		{
			int nDiff = ms_arFuns[type](m_arValue[type], pszCur);
			if (type == HTTP_HEAD_POST || type == HTTP_HEAD_GET)
			{
				m_arValue[HTTP_HEAD_URL] = m_arValue[type];
			}

			pszCur += nDiff;
		}
	}

	return true;
}

void HttpParser::debugOut()
{
	for (int i = 0; i < HTTP_HEAD_SIZE; ++i)
	{
		printf("%d\t\t%s\r\n", i, m_arValue[i].c_str());
	}
}

string& HttpParser::get(int type)
{
	if (type < 0 || type >= HTTP_HEAD_SIZE)
	{
		static string str("");
		return str;
	}

	return m_arValue[type];
}

void HttpParser::reset()
{
	// 因为要重复利用，所以用完后要重置
	for (int i = 0; i < HTTP_HEAD_SIZE; ++i)
	{
		m_arValue[i].clear();
	}
}
