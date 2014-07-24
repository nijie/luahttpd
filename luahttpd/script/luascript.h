// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __LUASCRIPT_H_NIJIE_2012_1015__
#define __LUASCRIPT_H_NIJIE_2012_1015__

#include "lua.hpp"
#include "inlsys.h"

#include <string>

using namespace std;

class HttpHandler;
class LuaAsk;

class LuaScript
{
public:
	LuaScript();
	~LuaScript();

	static LuaScript&	Instance();

	// 初始化
	bool				init();
	// 反初始化
	void				uninit();

	bool				callFunc(HttpHandler& handler);

	bool				callBackFunc(HttpHandler& handler, LuaAsk& ask, bool bRet);

private:
	// 报告错误
	void                __report(int status);
	// 遍历目录文件
	bool				__travel(const char* pszPath);
	// 加载模块
	bool				__loadModule(const char* pszName);

private:
	lua_State*          m_luaState;                     // Lua状态
	hash_map<string, int> m_mapFunc;
};

#endif	// __LUASCRIPT_H_NIJIE_2012_1015__

