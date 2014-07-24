// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
/*
** Lua binding: luaexport
** Generated automatically by tolua++-1.0.92 on 06/25/14 18:17:32.
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

/* function to release collected object via destructor */
#ifdef __cplusplus

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
	tolua_usertype(tolua_S,"Session");
	tolua_usertype(tolua_S,"HttpHandler");
	tolua_usertype(tolua_S,"DBAsk");
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

/* method:	gets of class 	HttpHandler */
#ifndef TOLUA_DISABLE_tolua_luaexport_HttpHandler_gets00
static int	tolua_luaexport_HttpHandler_gets00(lua_State* tolua_S)
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
		tolua_error(tolua_S,"invalid 'self' in function 'gets'", NULL);
#endif
		{
			const char*	tolua_ret = (const char*) 	self->gets(key);
			tolua_pushstring(tolua_S,(const char*)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'gets'.",&tolua_err);
	return 0;
#endif
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
   tolua_function(tolua_S,"gets",tolua_luaexport_HttpHandler_gets00);
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
   tolua_function(tolua_S,"count",tolua_luaexport_DBAsk_count00);
   tolua_function(tolua_S,"begin",tolua_luaexport_DBAsk_begin00);
   tolua_function(tolua_S,"next",tolua_luaexport_DBAsk_next00);
   tolua_function(tolua_S,"get",tolua_luaexport_DBAsk_get00);
   tolua_function(tolua_S,"getSize",tolua_luaexport_DBAsk_getSize00);
  tolua_endmodule(tolua_S);
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

