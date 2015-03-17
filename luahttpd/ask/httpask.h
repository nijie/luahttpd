#ifndef __HTTPASK_H_NIJIE_2015_0317__
#define __HTTPASK_H_NIJIE_2015_0317__

#include "luaask.h"
#include "ifhttp.h"

class HttpAsk : public Request, public LuaAsk
{
public:
	HttpAsk();
	virtual ~HttpAsk();

	virtual	void		OnResponse();
	virtual	void		Release();

	// lua export start
	void				setSN(unsigned int dwSN);
	unsigned int		getSN();
	void				setRequestType(int type);
	int					getRequestType();
	void				setUrl(const char* pszUrl, int eType);
	void				setUrl(const char* pszUrl);
	void				setPostStr(const char* pszPost);
	void				setDelay(unsigned int dwDelay);
	unsigned int		getDelay();
	const char*			getResponse();
	const char*			getUrl();
	const char*			getPostStr();
	bool				isOK();
	// lua export end
};

#endif	// __HTTPASK_H_NIJIE_2015_0317__
