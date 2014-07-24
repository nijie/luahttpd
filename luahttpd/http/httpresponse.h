// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __HTTPRESPONSE_H_NIJIE_2013_1121__
#define __HTTPRESPONSE_H_NIJIE_2013_1121__

#include <string>

using namespace std;

class HttpParser;

enum EHttpResponsesType
{
	HTTP_RESPONSE_HTTP = 0,
	HTTP_RESPONSE_CODE,
	HTTP_RESPONSE_ACCEPT_RANGES,// 表明服务器是否支持指定范围请求及哪种类型的分段请求 Accept-Ranges: bytes 
	HTTP_RESPONSE_AGE,			// 从原始服务器到代理缓存形成的估算时间（以秒计，非负） Age: 12 
	HTTP_RESPONSE_ALLOW,		// 对某网络资源的有效的请求行为，不允许则返回405 Allow: GET, HEAD 
	HTTP_RESPONSE_CACHE_CONTROL,// 告诉所有的缓存机制是否可以缓存及哪种类型 Cache-Control: no-cache 
	HTTP_RESPONSE_CONTENT_ENCODING,	// web服务器支持的返回内容压缩编码类型。 Content-Encoding: gzip 
	HTTP_RESPONSE_CONTENT_LANGUAGE,	// 响应体的语言 Content-Language: en,zh 
	HTTP_RESPONSE_CONTENT_LENGTH,	// 响应体的长度 Content-Length: 348 
	HTTP_RESPONSE_CONTENT_LOCATION,	// 请求资源可替代的备用的另一地址 Content-Location: /index.htm 
	HTTP_RESPONSE_CONTENT_MD5,		// 返回资源的MD5校验值 Content-MD5: Q2hlY2sgSW50ZWdyaXR5IQ== 
	HTTP_RESPONSE_CONTENT_RANGE,	// 在整个返回体中本部分的字节位置 Content-Range: bytes 21010-47021/47022 
	HTTP_RESPONSE_CONTENT_TYPE,		// 返回内容的MIME类型 Content-Type: text/html; charset=utf-8 
	HTTP_RESPONSE_CONNECTION,
	HTTP_RESPONSE_DATE,			// 原始服务器消息发出的时间 Date: Tue, 15 Nov 2010 08:12:31 GMT 
	HTTP_RESPONSE_ETAG,			// 请求变量的实体标签的当前值 ETag: “737060cd8c284d8af7ad3082f209582d” 
	HTTP_RESPONSE_EXPIRES,		// 响应过期的日期和时间 Expires: Thu, 01 Dec 2010 16:00:00 GMT 
	HTTP_RESPONSE_LAST_MODIFIED,// 请求资源的最后修改时间 Last-Modified: Tue, 15 Nov 2010 12:45:26 GMT 
	HTTP_RESPONSE_LOCATION,		// 用来重定向接收方到非请求URL的位置来完成请求或标识新的资源 Location: http://www.zcmhi.com/archives/94.html 
	HTTP_RESPONSE_PRAGMA,		// 包括实现特定的指令，它可应用到响应链上的任何接收方 Pragma: no-cache 
	HTTP_RESPONSE_PROXY_AUTHENTICATE,	// 它指出认证方案和可应用到代理的该URL上的参数 Proxy-Authenticate: Basic 
	HTTP_RESPONSE_REFRESH,		// 应用于重定向或一个新的资源被创造，在5秒之后重定向（由网景提出，被大部分浏览器支持） Refresh: 5; url=http://www.zcmhi.com/archives/94.html
	HTTP_RESPONSE_RETRY_AFTER,	// 如果实体暂时不可取，通知客户端在指定时间之后再次尝试 Retry-After: 120 
	HTTP_RESPONSE_SERVER,		// Web服务器软件名称 Server: Apache/1.3.27 (Unix) (Red-Hat/Linux) 
	HTTP_RESPONSE_SET_COOKIE,	// 设置Http Cookie Set-Cookie: UserID=JohnDoe; Max-Age=3600; Version=1 
	HTTP_RESPONSE_TRAILER,		// 指出头域在分块传输编码的尾部存在 Trailer: Max-Forwards 
	HTTP_RESPONSE_TRANSFER_ENCODING,// 文件传输编码 Transfer-Encoding:chunked 
	HTTP_RESPONSE_VARY,			// 告诉下游代理是使用缓存响应还是从原始服务器请求 Vary: * 
	HTTP_RESPONSE_VIA,			// 告知代理客户端响应是通过哪里发送的 Via: 1.0 fred, 1.1 nowhere.com (Apache/1.1) 
	HTTP_RESPONSE_WARNING,		// 警告实体可能存在的问题 Warning: 199 Miscellaneous warning 
	HTTP_RESPONSE_X_POWERED,
	HTTP_RESPONSE_KEEP_ALIVE,
	HTTP_RESPONSE_WWW_AUTHENTICATE,	// 表明客户端请求实体应该使用的授权方案 WWW-Authenticate: Basic 
	HTTP_RESPONSE_DATA,			// 返回的html信息
	HTTP_RESPONSE_SIZE,
};

static string s_arKeys[HTTP_RESPONSE_SIZE] = {
	"HTTP ",
	" ",
	"Accept-Ranges: ",
	"Age: ",
	"Allow: ",
	"Cache-Control: ",
	"Content-Encoding: ",
	"Content-Language: ",
	"Content-Length: ",
	"Content-Location: ",
	"Content-MD5: ",
	"Content-Range: ",
	"Content-Type: ",
	"Connection: ",
	"Date: ",
	"ETag: ",
	"Expires: ",
	"Last-Modified: ",
	"Location: ",
	"Pragma: ",
	"Proxy-Authenticate: ",
	"Refresh: ",
	"Retry-After: ",
	"Server: ",
	"Set-Cookie: ",
	"Trailer: ",
	"Transfer-Encoding: ",
	"Vary: ",
	"Via: ",
	"Warning: ",
	"X-Powered-By: ",
	"Keep-Alive: ",
	"WWW-Authenticate: ",
	"\r\n",
};

class HttpResponse
{
public:
	HttpResponse();
	~HttpResponse();

	bool		init(HttpParser& http);
	void		reset();
	void		set(int type, string& str);
	void		appendResponse(const char* pdata);

	void		getText(string& str);

private:
	string		m_arValues[HTTP_RESPONSE_SIZE];
};

#endif	// __HTTPRESPONSE_H_NIJIE_2013_1121__
