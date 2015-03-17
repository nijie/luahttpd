#include "httpask.h"
#include "../script/luascript.h"

HttpAsk::HttpAsk()
	: LuaAsk(LUA_ASK_HTTP)
{

}

HttpAsk::~HttpAsk()
{

}

void HttpAsk::OnResponse()
{
	if (getCallBack() == 0)
	{
		return;
	}

	// ½Å±¾»Øµ÷
	HttpHandler* pHttp = getHandler();
	if (NULL == pHttp)
	{
		return;
	}

	LuaScript::Instance().callBackFunc(*pHttp, *this);
}

void HttpAsk::Release()
{
	delete this;
}

void HttpAsk::setSN(unsigned int dwSN)
{
	Request::SetSN(dwSN);
}

unsigned int HttpAsk::getSN()
{
	return Request::GetSN();
}

void HttpAsk::setRequestType(int type)
{
	Request::SetRequestType((ERequestType)type);
}

int HttpAsk::getRequestType()
{
	return Request::GetRequestType();
}

void HttpAsk::setUrl(const char* pszUrl, int eType)
{
	if (pszUrl == NULL)
	{
		return;
	}
	Request::SetUrl(pszUrl, (ERequestType)eType);
}

void HttpAsk::setUrl(const char* pszUrl)
{
	if (pszUrl == NULL)
	{
		return;
	}
	Request::SetUrl(pszUrl);
}

void HttpAsk::setPostStr(const char* pszPost)
{
	if (pszPost == NULL)
	{
		return;
	}
	Request::SetPostStr(pszPost);
}

void HttpAsk::setDelay(unsigned int dwDelay)
{
	Request::SetDelay(dwDelay);
}

unsigned int HttpAsk::getDelay()
{
	return Request::GetDelay();
}

const char* HttpAsk::getResponse()
{
	string& strResponse = Request::GetResponse();
	return strResponse.c_str();
}

const char* HttpAsk::getUrl()
{
	string& strUrl = Request::GetUrl();
	return strUrl.c_str();
}

const char* HttpAsk::getPostStr()
{
	string& strPost = Request::GetPostStr();
	return strPost.c_str();
}

bool HttpAsk::isOK()
{
	return Request::IsSuccess();
}
