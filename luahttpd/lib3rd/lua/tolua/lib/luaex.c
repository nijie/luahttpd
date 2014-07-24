#include "tolua++.h"

TOLUA_API void lua_setfenv (lua_State* L, int index)
{
	lua_setuservalue(L, index);
}

TOLUA_API void lua_getfenv (lua_State* L, int index)
{
	lua_getuservalue(L, index);
}