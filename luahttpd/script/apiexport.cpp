// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "../http/coder.h"
#include "../http/httphandler.h"
#include "json.h"
#include "../ask/dbask.h"
#include "../ask/httpask.h"
#include "../ask/serverask.h"

#include "tolua++.h"
#include <string>

using namespace std;

// table -> json
bool table2json(lua_State* tolua_S, Json::Value& val)
{
	if (!lua_istable(tolua_S, -1))
	{
		return false;
	}
	
	lua_pushnil(tolua_S);
	char szValue[4096];
	while(lua_next(tolua_S, -2))
	{
		// key
		// 注意：c中实现lua table的遍历时，如果取table的key，并调用了lua_tostring,会使key转换成string，不能使用与接下来的遍历。所以需要把key再push一个。
		lua_pushvalue(tolua_S, -2);
		const char*	pSrc = ((const char*)  lua_tostring(tolua_S, -1));
		_snprintf_s(szValue, 4095, "%s", pSrc);
		lua_pop(tolua_S, 1);

		if (lua_istable(tolua_S, -1))
		{
			Json::Value item;
			if (table2json(tolua_S, item))
			{
				val[szValue] = item;
			}
			else
			{
				lua_pop(tolua_S, 2);
				return false;
			}
		}
		else
		{
			const char*	pVal = ((const char*)  lua_tostring(tolua_S, -1));
			val[szValue] = pVal;
		}
		lua_pop(tolua_S, 1);
	}

	return true;
}

static int tolua_luaexport_JsonEncode00(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_istable(tolua_S,1,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
	{
		tolua_error(tolua_S,"#ferror in function 'JsonEncode'.",&tolua_err);
		return 0;
	}
	else
	{
		Json::Value root;
		if (!table2json(tolua_S, root))
		{
			return 0;
		}

		string& str = root.toStyledString();

		tolua_pushstring(tolua_S,(const char*)str.c_str());
	}
	return 1;
}

// json -> table
bool json2table(lua_State* tolua_S, Json::Value& val)
{
	if (!lua_istable(tolua_S, -1))
	{
		return false;
	}

	if (val.type() != Json::objectValue)
	{
		return false;
	}

	for (Json::Value::iterator it = val.begin(); it != val.end(); ++it)
	{
		Json::Value& k = it.key();
		Json::Value& v = (*it);
		string& strK = k.asString();

		if (v.type() == Json::objectValue)
		{
			lua_newtable(tolua_S);
			if (!json2table(tolua_S, v))
			{
				lua_pop(tolua_S, 1);
				return false;
			}
		}
		else
		{
			string& strV = v.asString();
			tolua_pushstring(tolua_S, strV.c_str());
		}
		lua_setfield(tolua_S, -2, strK.c_str());
	}

	return true;
}

static int tolua_luaexport_JsonDecode00(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isstring(tolua_S,1,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
	{
		tolua_error(tolua_S,"#ferror in function 'JsonDecode'.",&tolua_err);
		return 0;
	}
	else
	{
		Json::Value root;
		Json::Reader reader;
	
		string strSrc = ((const char*)  tolua_tostring(tolua_S,1,0));

		if (!reader.parse(strSrc, root))
		{
			tolua_error(tolua_S,"#ferror in function 'JsonDecode'.",&tolua_err);
			return 0;
		}

		lua_newtable(tolua_S);

		if (root.type() == Json::objectValue)
		{
			if (!json2table(tolua_S, root))
			{
				return 0;
			}
		}
		else
		{
			string& str = root.asString();
			tolua_pushstring(tolua_S, str.c_str());
			lua_rawseti(tolua_S, -2, 1);
		}
	}
	return 1;
}

// AddAsk 支持两种参数列表
// 1. AddAsk(http, ask, callback)	// 支持回调，等待回调继续处理
// 2. AddAsk(http, ask)				// 没有回调，处理完就ok了
static int tolua_luaexport_AddAsk00(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S,1,"HttpHandler",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'JsonDecode'.",&tolua_err);
		return 0;
	}
	else
	{
		HttpHandler* http = (HttpHandler*)tolua_tousertype(tolua_S,1,0);
		LuaAsk* ask = NULL;
		if (tolua_isusertype(tolua_S,2,"DBAsk",0,&tolua_err))
		{
			ask = (DBAsk*)tolua_tousertype(tolua_S,2,0);
		}
		else if (tolua_isusertype(tolua_S,2,"HttpAsk",0,&tolua_err))
		{
			ask = (HttpAsk*)tolua_tousertype(tolua_S,2,0);
		}
		else if (tolua_isusertype(tolua_S,2,"ServerAsk",0,&tolua_err))
		{
			ask = (ServerAsk*)tolua_tousertype(tolua_S,2,0);
		}
		else
		{
			ask = (LuaAsk*)tolua_tousertype(tolua_S,2,0);
		}
		
		int nFuncId = 0;
		if (lua_isfunction(tolua_S, 3))
		{// 2. AddAsk(http, ask)				// 没有回调，处理完就ok了
			lua_pushvalue(tolua_S, 3);
			nFuncId = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
		}

		if (!http->addAsk(ask, nFuncId))
		{
			return 0;
		}
	}
	return 1;
}

TOLUA_API int tolua_apiexport_open (lua_State* tolua_S)
{
	tolua_beginmodule(tolua_S,NULL);
	tolua_function(tolua_S,"JsonEncode",tolua_luaexport_JsonEncode00);
	tolua_function(tolua_S,"JsonDecode",tolua_luaexport_JsonDecode00);
	tolua_function(tolua_S,"AddAsk",tolua_luaexport_AddAsk00);
	tolua_endmodule(tolua_S);
	return 1;
}
