/*
** Lua binding: luaexport
** Generated automatically by tolua++-1.0.92 on 03/17/15 20:40:25.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luaexport_open (lua_State* tolua_S);

#include "../http/httphandler.h"
#include "../http/coder.h"
#include "../session/session.h"
#include "../ask/dbask.h"
#include "../ask/httpask.h"
#include "exelogger.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_HttpAsk (lua_State* tolua_S)
{
	HttpAsk* self = (HttpAsk*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_DBAsk (lua_State* tolua_S)
{
	DBAsk* self = (DBAsk*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"HttpAsk");
	tolua_usertype(tolua_S,"DBAsk");
	tolua_usertype(tolua_S,"HttpHandler");
	tolua_usertype(tolua_S,"Session");
}

/* method:	get of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_get00
static int	tolua_luaexport_HttpHandler_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		int	type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->get(type);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	get of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_get01
static int	tolua_luaexport_HttpHandler_get01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		const char*	key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->get(key);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
tolua_lerror:
	return tolua_luaexport_HttpHandler_get00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setValue of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_setValue00
static int	tolua_luaexport_HttpHandler_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pKey = ((const char*)  tolua_tostring(tolua_S,2,0));
		const char*	pVal = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setValue'", NULL);
#endif
		{
			self->setValue(pKey,pVal);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getValue of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_getValue00
static int	tolua_luaexport_HttpHandler_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pKey = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->getValue(pKey);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setResponse of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_setResponse00
static int	tolua_luaexport_HttpHandler_setResponse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		int	type = ((int)  tolua_tonumber(tolua_S,2,0));
		const char*	pBuf = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setResponse'", NULL);
#endif
		{
			self->setResponse(type,pBuf);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setResponse'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setCookie of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_setCookie00
static int	tolua_luaexport_HttpHandler_setCookie00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		const char*	key = ((const char*)  tolua_tostring(tolua_S,2,0));
		const char*	val = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setCookie'", NULL);
#endif
		{
			self->setCookie(key,val);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setCookie'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getCookie of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_getCookie00
static int	tolua_luaexport_HttpHandler_getCookie00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
		const char*	key = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getCookie'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->getCookie(key);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getCookie'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getSession of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_getSession00
static int	tolua_luaexport_HttpHandler_getSession00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpHandler*	self = (HttpHandler*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getSession'", NULL);
#endif
		{
			Session*	tolua_ret = (Session*) 	self->getSession();
			tolua_pushusertype(tolua_S,(void*)tolua_ret,"Session");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getSession'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getDestroyTime of class 	Session */
#ifndef TOLUA_DISABLE_tolua_luaexport_Session_getDestroyTime00
static int	tolua_luaexport_Session_getDestroyTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"Session",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		Session*	self = (Session*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getDestroyTime'", NULL);
#endif
		{
			unsigned	int	tolua_ret = (unsigned	int) 	self->getDestroyTime();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getDestroyTime'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setKeepTime of class 	Session */
#ifndef TOLUA_DISABLE_tolua_luaexport_Session_setKeepTime00
static int	tolua_luaexport_Session_setKeepTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"Session",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		Session*	self = (Session*) 	tolua_tousertype(tolua_S,1,0);
		unsigned	int	uTime = ((unsigned	int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setKeepTime'", NULL);
#endif
		{
			self->setKeepTime(uTime);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setKeepTime'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	set of class 	Session */
#ifndef TOLUA_DISABLE_tolua_luaexport_Session_set00
static int	tolua_luaexport_Session_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"Session",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		Session*	self = (Session*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pKey = ((const char*)  tolua_tostring(tolua_S,2,0));
		const char*	pVal = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->set(pKey,pVal);
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	get of class 	Session */
#ifndef TOLUA_DISABLE_tolua_luaexport_Session_get00
static int	tolua_luaexport_Session_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"Session",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		Session*	self = (Session*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pKey = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->get(pKey);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getId of class 	Session */
#ifndef TOLUA_DISABLE_tolua_luaexport_Session_getId00
static int	tolua_luaexport_Session_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"Session",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		Session*	self = (Session*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
		{
			unsigned	int	tolua_ret = (unsigned	int) 	self->getId();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	new of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_new00
static int	tolua_luaexport_DBAsk_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		{
			DBAsk*	tolua_ret = (DBAsk*) 	Mtolua_new((DBAsk)());
			tolua_pushusertype(tolua_S,(void*)tolua_ret,"DBAsk");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_new00_local
static int	tolua_luaexport_DBAsk_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		{
			DBAsk*	tolua_ret = (DBAsk*) 	Mtolua_new((DBAsk)());
			tolua_pushusertype(tolua_S,(void*)tolua_ret,"DBAsk");
			tolua_register_gc(tolua_S,lua_gettop(tolua_S));
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	delete of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_delete00
static int	tolua_luaexport_DBAsk_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
	Mtolua_delete(self);
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setSN of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_setSN00
static int	tolua_luaexport_DBAsk_setSN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
		int	sn = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setSN'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->setSN(sn);
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setSN'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setSQL of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_setSQL00
static int	tolua_luaexport_DBAsk_setSQL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pDBName = ((const char*)  tolua_tostring(tolua_S,2,0));
		const char*	pSql = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setSQL'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->setSQL(pDBName,pSql);
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setSQL'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	isOK of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_isOK00
static int	tolua_luaexport_DBAsk_isOK00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'isOK'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->isOK();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'isOK'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	count of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_count00
static int	tolua_luaexport_DBAsk_count00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'count'", NULL);
#endif
		{
			unsigned	int	tolua_ret = (unsigned	int) 	self->count();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'count'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	begin of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_begin00
static int	tolua_luaexport_DBAsk_begin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'begin'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->begin();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'begin'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	next of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_next00
static int	tolua_luaexport_DBAsk_next00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'next'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->next();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'next'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	get of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_get00
static int	tolua_luaexport_DBAsk_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
		unsigned	int	dwIndex = ((unsigned	int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->get(dwIndex);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getSize of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_getSize00
static int	tolua_luaexport_DBAsk_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
		unsigned	int	dwIndex = ((unsigned	int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getSize'", NULL);
#endif
		{
			int	tolua_ret = (int) 	self->getSize(dwIndex);
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getInsertId of class 	DBAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_DBAsk_getInsertId00
static int	tolua_luaexport_DBAsk_getInsertId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"DBAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		DBAsk*	self = (DBAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getInsertId'", NULL);
#endif
		{
			unsigned	int	tolua_ret = (unsigned	int) 	self->getInsertId();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getInsertId'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	new of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_new00
static int	tolua_luaexport_HttpAsk_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		{
			HttpAsk*	tolua_ret = (HttpAsk*) 	Mtolua_new((HttpAsk)());
			tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpAsk");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_new00_local
static int	tolua_luaexport_HttpAsk_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		{
			HttpAsk*	tolua_ret = (HttpAsk*) 	Mtolua_new((HttpAsk)());
			tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpAsk");
			tolua_register_gc(tolua_S,lua_gettop(tolua_S));
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	delete of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_delete00
static int	tolua_luaexport_HttpAsk_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
	Mtolua_delete(self);
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setSN of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_setSN00
static int	tolua_luaexport_HttpAsk_setSN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
		unsigned	int	dwSN = ((unsigned	int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setSN'", NULL);
#endif
		{
			self->setSN(dwSN);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setSN'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getSN of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_getSN00
static int	tolua_luaexport_HttpAsk_getSN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getSN'", NULL);
#endif
		{
			unsigned	int	tolua_ret = (unsigned	int) 	self->getSN();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getSN'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setRequestType of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_setRequestType00
static int	tolua_luaexport_HttpAsk_setRequestType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
		int	type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setRequestType'", NULL);
#endif
		{
			self->setRequestType(type);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setRequestType'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getRequestType of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_getRequestType00
static int	tolua_luaexport_HttpAsk_getRequestType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getRequestType'", NULL);
#endif
		{
			int	tolua_ret = (int) 	self->getRequestType();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getRequestType'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setUrl of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_setUrl00
static int	tolua_luaexport_HttpAsk_setUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnumber(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pszUrl = ((const char*)  tolua_tostring(tolua_S,2,0));
		int	eType = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setUrl'", NULL);
#endif
		{
			self->setUrl(pszUrl,eType);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setUrl'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setUrl of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_setUrl01
static int	tolua_luaexport_HttpAsk_setUrl01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pszUrl = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setUrl'", NULL);
#endif
		{
			self->setUrl(pszUrl);
		}
	}
	return 0;
tolua_lerror:
	return tolua_luaexport_HttpAsk_setUrl00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setPostStr of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_setPostStr00
static int	tolua_luaexport_HttpAsk_setPostStr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
		const char*	pszPost = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setPostStr'", NULL);
#endif
		{
			self->setPostStr(pszPost);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setPostStr'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	setDelay of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_setDelay00
static int	tolua_luaexport_HttpAsk_setDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
		unsigned	int	dwDelay = ((unsigned	int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'setDelay'", NULL);
#endif
		{
			self->setDelay(dwDelay);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setDelay'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getDelay of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_getDelay00
static int	tolua_luaexport_HttpAsk_getDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getDelay'", NULL);
#endif
		{
			unsigned	int	tolua_ret = (unsigned	int) 	self->getDelay();
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getDelay'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getResponse of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_getResponse00
static int	tolua_luaexport_HttpAsk_getResponse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getResponse'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->getResponse();
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getResponse'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getUrl of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_getUrl00
static int	tolua_luaexport_HttpAsk_getUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getUrl'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->getUrl();
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getUrl'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	getPostStr of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_getPostStr00
static int	tolua_luaexport_HttpAsk_getPostStr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'getPostStr'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->getPostStr();
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'getPostStr'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method:	isOK of class 	HttpAsk */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpAsk_isOK00
static int	tolua_luaexport_HttpAsk_isOK00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"HttpAsk",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		HttpAsk*	self = (HttpAsk*) 	tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
	if (!self)
		tolua_error(tolua_S,"invalid 'self' in function 'isOK'", NULL);
#endif
		{
			bool	tolua_ret = (bool) 	self->isOK();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'isOK'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function:	flog */
#ifndef TOLUA_DISABLE_tolua_luaexport_flog00
static int	tolua_luaexport_flog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isstring(tolua_S,1,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		const char*	txt = ((const char*)  tolua_tostring(tolua_S,1,0));
		{
			flog(txt);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'flog'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function:	atoi */
#ifndef TOLUA_DISABLE_tolua_luaexport_atoi00
static int	tolua_luaexport_atoi00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isstring(tolua_S,1,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		const char*	a = ((const char*)  tolua_tostring(tolua_S,1,0));
		{
			int	tolua_ret = (int) 	atoi(a);
			tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'atoi'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function:	Base64Encode */
#ifndef TOLUA_DISABLE_tolua_luaexport_Base64Encode00
static int	tolua_luaexport_Base64Encode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isstring(tolua_S,1,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		const char*	pSrc = ((const char*)  tolua_tostring(tolua_S,1,0));
		{
			const char*	tolua_ret = (const char*) 	Base64Encode(pSrc);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'Base64Encode'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function:	Base64Decode */
#ifndef TOLUA_DISABLE_tolua_luaexport_Base64Decode00
static int	tolua_luaexport_Base64Decode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isstring(tolua_S,1,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
	)
		goto tolua_lerror;
	else
#endif
	{
		const char*	pDst = ((const char*)  tolua_tostring(tolua_S,1,0));
		{
			const char*	tolua_ret = (const char*) 	Base64Decode(pDst);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'Base64Decode'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_luaexport_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"HTTP_HEAD_URL",HTTP_HEAD_URL);
  tolua_constant(tolua_S,"HTTP_HEAD_GET",HTTP_HEAD_GET);
  tolua_constant(tolua_S,"HTTP_HEAD_POST",HTTP_HEAD_POST);
  tolua_constant(tolua_S,"HTTP_HEAD_HTTP",HTTP_HEAD_HTTP);
  tolua_constant(tolua_S,"HTTP_HEAD_ACCEPT",HTTP_HEAD_ACCEPT);
  tolua_constant(tolua_S,"HTTP_HEAD_ACCEPT_CHARSET",HTTP_HEAD_ACCEPT_CHARSET);
  tolua_constant(tolua_S,"HTTP_HEAD_ACCEPT_ENCODING",HTTP_HEAD_ACCEPT_ENCODING);
  tolua_constant(tolua_S,"HTTP_HEAD_ACCEPT_LANGUAGE",HTTP_HEAD_ACCEPT_LANGUAGE);
  tolua_constant(tolua_S,"HTTP_HEAD_ACCEPT_RANGES",HTTP_HEAD_ACCEPT_RANGES);
  tolua_constant(tolua_S,"HTTP_HEAD_AUTHORIZATION",HTTP_HEAD_AUTHORIZATION);
  tolua_constant(tolua_S,"HTTP_HEAD_CACHE_CONTROL",HTTP_HEAD_CACHE_CONTROL);
  tolua_constant(tolua_S,"HTTP_HEAD_CONNECTION",HTTP_HEAD_CONNECTION);
  tolua_constant(tolua_S,"HTTP_HEAD_COOKIE",HTTP_HEAD_COOKIE);
  tolua_constant(tolua_S,"HTTP_HEAD_CONTENT_LENGTH",HTTP_HEAD_CONTENT_LENGTH);
  tolua_constant(tolua_S,"HTTP_HEAD_CONTENT_TYPE",HTTP_HEAD_CONTENT_TYPE);
  tolua_constant(tolua_S,"HTTP_HEAD_DATE",HTTP_HEAD_DATE);
  tolua_constant(tolua_S,"HTTP_HEAD_EXPECT",HTTP_HEAD_EXPECT);
  tolua_constant(tolua_S,"HTTP_HEAD_FROM",HTTP_HEAD_FROM);
  tolua_constant(tolua_S,"HTTP_HEAD_HOST",HTTP_HEAD_HOST);
  tolua_constant(tolua_S,"HTTP_HEAD_IF_MATCH",HTTP_HEAD_IF_MATCH);
  tolua_constant(tolua_S,"HTTP_HEAD_IF_MODIFIED_SINCE",HTTP_HEAD_IF_MODIFIED_SINCE);
  tolua_constant(tolua_S,"HTTP_HEAD_IF_NONE_MATCH",HTTP_HEAD_IF_NONE_MATCH);
  tolua_constant(tolua_S,"HTTP_HEAD_IF_RANGE",HTTP_HEAD_IF_RANGE);
  tolua_constant(tolua_S,"HTTP_HEAD_IF_UNMODIFIED_SINCE",HTTP_HEAD_IF_UNMODIFIED_SINCE);
  tolua_constant(tolua_S,"HTTP_HEAD_MAX_FORWARDS",HTTP_HEAD_MAX_FORWARDS);
  tolua_constant(tolua_S,"HTTP_HEAD_PRAGMA",HTTP_HEAD_PRAGMA);
  tolua_constant(tolua_S,"HTTP_HEAD_PROXY_AUTHORIZATION",HTTP_HEAD_PROXY_AUTHORIZATION);
  tolua_constant(tolua_S,"HTTP_HEAD_RANGE",HTTP_HEAD_RANGE);
  tolua_constant(tolua_S,"HTTP_HEAD_REFERER",HTTP_HEAD_REFERER);
  tolua_constant(tolua_S,"HTTP_HEAD_TE",HTTP_HEAD_TE);
  tolua_constant(tolua_S,"HTTP_HEAD_UPGRADE",HTTP_HEAD_UPGRADE);
  tolua_constant(tolua_S,"HTTP_HEAD_USER_AGENT",HTTP_HEAD_USER_AGENT);
  tolua_constant(tolua_S,"HTTP_HEAD_VIA",HTTP_HEAD_VIA);
  tolua_constant(tolua_S,"HTTP_HEAD_WARNING",HTTP_HEAD_WARNING);
  tolua_constant(tolua_S,"HTTP_HEAD_POST_DATA",HTTP_HEAD_POST_DATA);
  tolua_constant(tolua_S,"HTTP_HEAD_SIZE",HTTP_HEAD_SIZE);
  tolua_cclass(tolua_S,"HttpHandler","HttpHandler","",NULL);
  tolua_beginmodule(tolua_S,"HttpHandler");
   tolua_function(tolua_S,"get",tolua_luaexport_HttpHandler_get00);
   tolua_function(tolua_S,"get",tolua_luaexport_HttpHandler_get01);
   tolua_function(tolua_S,"setValue",tolua_luaexport_HttpHandler_setValue00);
   tolua_function(tolua_S,"getValue",tolua_luaexport_HttpHandler_getValue00);
   tolua_function(tolua_S,"setResponse",tolua_luaexport_HttpHandler_setResponse00);
   tolua_function(tolua_S,"setCookie",tolua_luaexport_HttpHandler_setCookie00);
   tolua_function(tolua_S,"getCookie",tolua_luaexport_HttpHandler_getCookie00);
   tolua_function(tolua_S,"getSession",tolua_luaexport_HttpHandler_getSession00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Session","Session","",NULL);
  tolua_beginmodule(tolua_S,"Session");
   tolua_function(tolua_S,"getDestroyTime",tolua_luaexport_Session_getDestroyTime00);
   tolua_function(tolua_S,"setKeepTime",tolua_luaexport_Session_setKeepTime00);
   tolua_function(tolua_S,"set",tolua_luaexport_Session_set00);
   tolua_function(tolua_S,"get",tolua_luaexport_Session_get00);
   tolua_function(tolua_S,"getId",tolua_luaexport_Session_getId00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"DBAsk","DBAsk","",tolua_collect_DBAsk);
  #else
  tolua_cclass(tolua_S,"DBAsk","DBAsk","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"DBAsk");
   tolua_function(tolua_S,"new",tolua_luaexport_DBAsk_new00);
   tolua_function(tolua_S,"new_local",tolua_luaexport_DBAsk_new00_local);
   tolua_function(tolua_S,".call",tolua_luaexport_DBAsk_new00_local);
   tolua_function(tolua_S,"delete",tolua_luaexport_DBAsk_delete00);
   tolua_function(tolua_S,"setSN",tolua_luaexport_DBAsk_setSN00);
   tolua_function(tolua_S,"setSQL",tolua_luaexport_DBAsk_setSQL00);
   tolua_function(tolua_S,"isOK",tolua_luaexport_DBAsk_isOK00);
   tolua_function(tolua_S,"count",tolua_luaexport_DBAsk_count00);
   tolua_function(tolua_S,"begin",tolua_luaexport_DBAsk_begin00);
   tolua_function(tolua_S,"next",tolua_luaexport_DBAsk_next00);
   tolua_function(tolua_S,"get",tolua_luaexport_DBAsk_get00);
   tolua_function(tolua_S,"getSize",tolua_luaexport_DBAsk_getSize00);
   tolua_function(tolua_S,"getInsertId",tolua_luaexport_DBAsk_getInsertId00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HttpAsk","HttpAsk","",tolua_collect_HttpAsk);
  #else
  tolua_cclass(tolua_S,"HttpAsk","HttpAsk","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HttpAsk");
   tolua_function(tolua_S,"new",tolua_luaexport_HttpAsk_new00);
   tolua_function(tolua_S,"new_local",tolua_luaexport_HttpAsk_new00_local);
   tolua_function(tolua_S,".call",tolua_luaexport_HttpAsk_new00_local);
   tolua_function(tolua_S,"delete",tolua_luaexport_HttpAsk_delete00);
   tolua_function(tolua_S,"setSN",tolua_luaexport_HttpAsk_setSN00);
   tolua_function(tolua_S,"getSN",tolua_luaexport_HttpAsk_getSN00);
   tolua_function(tolua_S,"setRequestType",tolua_luaexport_HttpAsk_setRequestType00);
   tolua_function(tolua_S,"getRequestType",tolua_luaexport_HttpAsk_getRequestType00);
   tolua_function(tolua_S,"setUrl",tolua_luaexport_HttpAsk_setUrl00);
   tolua_function(tolua_S,"setUrl",tolua_luaexport_HttpAsk_setUrl01);
   tolua_function(tolua_S,"setPostStr",tolua_luaexport_HttpAsk_setPostStr00);
   tolua_function(tolua_S,"setDelay",tolua_luaexport_HttpAsk_setDelay00);
   tolua_function(tolua_S,"getDelay",tolua_luaexport_HttpAsk_getDelay00);
   tolua_function(tolua_S,"getResponse",tolua_luaexport_HttpAsk_getResponse00);
   tolua_function(tolua_S,"getUrl",tolua_luaexport_HttpAsk_getUrl00);
   tolua_function(tolua_S,"getPostStr",tolua_luaexport_HttpAsk_getPostStr00);
   tolua_function(tolua_S,"isOK",tolua_luaexport_HttpAsk_isOK00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"flog",tolua_luaexport_flog00);
  tolua_function(tolua_S,"atoi",tolua_luaexport_atoi00);
  tolua_function(tolua_S,"Base64Encode",tolua_luaexport_Base64Encode00);
  tolua_function(tolua_S,"Base64Decode",tolua_luaexport_Base64Decode00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
	TOLUA_API int luaopen_luaexport (lua_State* tolua_S) {
 return tolua_luaexport_open(tolua_S);
};
#endif

