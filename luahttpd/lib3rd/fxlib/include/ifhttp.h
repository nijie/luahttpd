//  Created by Nijie on 2011/08/26.
//  Copyright (c) 2011 Nijie. All rights reserved.
//

#ifndef __FIHTTP_H_NJ_2011_0826__
#define __FIHTTP_H_NJ_2011_0826__

#include "version.h"
#include <string>

using namespace std;

class Request;
typedef void (*OnCallBack)(Request* request);

enum ERequestType
{
	RequestType_Get		= 0,
	RequestType_Post	= 1,
	RequestType_File	= 2,
	RequestType_Https	= 3,
};

class Request
{
public:
	Request();
	virtual ~Request();
	virtual	void	OnResponse() = 0;
	virtual	void	Release() = 0;

	void			Reset();
	void			SetSN(unsigned int dwSN);
	unsigned int	GetSN();
	void			SetRequestType(ERequestType eType);
	unsigned char	GetRequestType();
	void			SetUrl(const char* pszUrl, ERequestType eType = RequestType_Get);
	void			SetPostStr(const char* pszPost);
	void			SetDelay(unsigned int dwDelay);
	unsigned int	GetDelay();
	void			AppendResponse(const char* pszResponse, size_t size);
	string&			GetResponse();
	string&			GetUrl();
	string&			GetPostStr();
	void			SetSuccess(bool bSuccess);
	bool			IsSuccess();
	
private:
	unsigned char	m_byType;
	bool			m_bSuccess;
	unsigned int	m_dwSN;
	unsigned int	m_dwDelay;
	string			m_strUrl;
	string			m_strPost;
	string			m_strResponse;
};

class IHttp
{
public:
	virtual bool	Init() = 0;
	virtual bool	Run(int nCount = 0) = 0;	// ∑µªÿ «∑Ò√¶
	virtual bool	AddRequest(Request* poRequest) = 0;
	virtual bool	Release() = 0;
	virtual void	Clear() = 0;
	virtual bool	IsBusy() = 0;
};

IHttp* CreateHTTPModule();

#endif	// __FIHTTP_H_NJ_2011_0826__
