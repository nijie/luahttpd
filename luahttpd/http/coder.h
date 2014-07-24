// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __CODER_H_NIJIE_2014_0529__
#define __CODER_H_NIJIE_2014_0529__

// Json 模块有c模式lua实现
// extern int	JsonEncode(lua_State* tolua_S);	// table -> json
// extern int	JsonDecode(lua_State* tolua_S);	// json -> table

extern const char* Base64Encode(const char* pSrc);	// src -> base64
extern const char* Base64Decode(const char* pDst);	// base64 -> src

#endif	// __CODER_H_NIJIE_2014_0529__
