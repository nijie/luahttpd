// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __HTTPPARSER_H_NIJIE_2013_1120__
#define __HTTPPARSER_H_NIJIE_2013_1120__

#include "match.h"
#include <string>

using namespace std;

enum EHttpRequestType
{
	HTTP_HEAD_URL = 0,
	HTTP_HEAD_GET,
	HTTP_HEAD_POST,
	HTTP_HEAD_HTTP,
	HTTP_HEAD_ACCEPT,
	HTTP_HEAD_ACCEPT_CHARSET,
	HTTP_HEAD_ACCEPT_ENCODING,
	HTTP_HEAD_ACCEPT_LANGUAGE,	// 浏览器可接受的语言 Accept-Language: en,zh 
	HTTP_HEAD_ACCEPT_RANGES,	// 可以请求网页实体的一个或者多个子范围字段 Accept-Ranges: bytes 
	HTTP_HEAD_AUTHORIZATION,	// HTTP授权的授权证书 Authorization: Basic QWxhZGRpbjpvcGVuIHNlc2FtZQ== 
	HTTP_HEAD_CACHE_CONTROL,	// 指定请求和响应遵循的缓存机制 Cache-Control: no-cache 
	HTTP_HEAD_CONNECTION,		// 表示是否需要持久连接。（HTTP 1.1默认进行持久连接） Connection: close 
	HTTP_HEAD_COOKIE,			//  HTTP请求发送时，会把保存在该请求域名下的所有cookie值一起发送给web服务器。 Cookie: $Version=1; Skin=new; 
	HTTP_HEAD_CONTENT_LENGTH,	// 请求的内容长度 Content-Length: 348 
	HTTP_HEAD_CONTENT_TYPE,		// 请求的与实体对应的MIME信息 Content-Type: application/x-www-form-urlencoded 
	HTTP_HEAD_DATE,				// 请求发送的日期和时间 Date: Tue, 15 Nov 2010 08:12:31 GMT 
	HTTP_HEAD_EXPECT,			// 请求的特定的服务器行为 Expect: 100-continue 
	HTTP_HEAD_FROM,				// 发出请求的用户的Email From: user@email.com 
	HTTP_HEAD_HOST,				// 指定请求的服务器的域名和端口号 Host: www.zcmhi.com 
	HTTP_HEAD_IF_MATCH,			//	只有请求内容与实体相匹配才有效 If-Match: “737060cd8c284d8af7ad3082f209582d” 
	HTTP_HEAD_IF_MODIFIED_SINCE,// 如果请求的部分在指定时间之后被修改则请求成功，未被修改则返回304代码 If-Modified-Since: Sat, 29 Oct 2010 19:43:31 GMT 
	HTTP_HEAD_IF_NONE_MATCH,	// 如果内容未改变返回304代码，参数为服务器先前发送的Etag，与服务器回应的Etag比较判断是否改变 If-None-Match: “737060cd8c284d8af7ad3082f209582d” 
	HTTP_HEAD_IF_RANGE,			// 如果实体未改变，服务器发送客户端丢失的部分，否则发送整个实体。参数也为Etag If-Range: “737060cd8c284d8af7ad3082f209582d” 
	HTTP_HEAD_IF_UNMODIFIED_SINCE,// 只在实体在指定时间之后未被修改才请求成功 If-Unmodified-Since: Sat, 29 Oct 2010 19:43:31 GMT 
	HTTP_HEAD_MAX_FORWARDS,		// 限制信息通过代理和网关传送的时间 Max-Forwards: 10 
	HTTP_HEAD_PRAGMA,			// 用来包含实现特定的指令 Pragma: no-cache 
	HTTP_HEAD_PROXY_AUTHORIZATION,// 连接到代理的授权证书 Proxy-Authorization: Basic QWxhZGRpbjpvcGVuIHNlc2FtZQ== 
	HTTP_HEAD_RANGE,			// 只请求实体的一部分，指定范围 Range: bytes=500-999 
	HTTP_HEAD_REFERER,			// 先前网页的地址，当前请求网页紧随其后,即来路 Referer: http://www.zcmhi.com/archives/71.html 
	HTTP_HEAD_TE,				// 客户端愿意接受的传输编码，并通知服务器接受接受尾加头信息 TE: trailers,deflate;q=0.5 
	HTTP_HEAD_UPGRADE,			// 向服务器指定某种传输协议以便服务器进行转换（如果支持） Upgrade: HTTP/2.0, SHTTP/1.3, IRC/6.9, RTA/x11 
	HTTP_HEAD_USER_AGENT,		// User-Agent的内容包含发出请求的用户信息 User-Agent: Mozilla/5.0 (Linux; X11) 
	HTTP_HEAD_VIA,				// 通知中间网关或代理服务器地址，通信协议 Via: 1.0 fred, 1.1 nowhere.com (Apache/1.1) 
	HTTP_HEAD_WARNING,			// 关于消息实体的警告信息 Warn: 199 Miscellaneous warning 
	HTTP_HEAD_POST_DATA,		// Post data

	HTTP_HEAD_SIZE,
};

typedef int (*FN_HTTP_HEAD_PARSE)(string& strVal, const char* pszBuf);

class HttpParser
{
public:
	HttpParser();
	~HttpParser();

	static bool		Init();
	
	static int		ParseHttpHeadSpace(string& strVal, const char* pszBuf);
	static int		ParseHttpHeadLRN(string& strVal, const char* pszBuf);

	bool			parse(const char* pszBuf);
	void			reset();

	string&			get(int type);

	void			debugOut();

private:
	static MatchTree*	ms_pMatchTree;
	static FN_HTTP_HEAD_PARSE ms_arFuns[HTTP_HEAD_SIZE];

	string			m_arValue[HTTP_HEAD_SIZE];
};

#endif	// __HTTPPARSER_H_NIJIE_2013_1120__
