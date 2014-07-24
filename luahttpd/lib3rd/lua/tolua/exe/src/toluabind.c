/*
** Lua binding: tolua
** Generated automatically by tolua++-1.0.92 on Sun Feb 15 22:29:47 2009.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_tolua_open (lua_State* tolua_S);


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_tolua_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
if string.find(_VERSION, \"5%.0\") then\n\
	error(\"error VERSION \".._VERSION)\n\
	return\n\
end\n\
\n\
-- \"loadfile\"\n\
local function pp_dofile(path)\n\
\n\
	local loaded = false\n\
	local getfile = function()\n\
\n\
		if loaded then\n\
			return\n\
		else\n\
			local file,err = io.open(path)\n\
			if not file then\n\
				error(\"error loading file \"..path..\": \"..err)\n\
			end\n\
			local ret = file:read(\"*a\")\n\
			file:close()\n\
\n\
			ret = string.gsub(ret, \"%.%.%.%s*%)\", \"...) local arg = {n=select('#', ...), ...};\")\n\
\n\
			loaded = true\n\
			return ret\n\
		end\n\
	end\n\
\n\
	local f = load(getfile, path)\n\
	if not f then\n\
	\n\
		error(\"error loading file \"..path)\n\
	end\n\
	return f()\n\
end\n\
\n\
old_dofile = dofile\n\
dofile = pp_dofile\n\
\n\
\n\
-- string.gsub\n\
--[[\n\
local ogsub = string.gsub\n\
local function compgsub(a,b,c,d)\n\
  if type(c) == \"function\" then\n\
    local oc = c\n\
    c = function (...) return oc(...) or '' end\n\
  end\n\
  return ogsub(a,b,c,d)\n\
end\n\
string.repl = ogsub\n\
--]]\n\
\n\
--string.gsub = compgsub\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/compat-5.1.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-------------------------------------------------------------------\n\
-- Real globals\n\
-- _ALERT\n\
-- _ERRORMESSAGE\n\
-- _VERSION\n\
-- _G\n\
-- assert\n\
-- error\n\
-- metatable\n\
-- next\n\
-- print\n\
-- require\n\
-- tonumber\n\
-- tostring\n\
-- type\n\
-- unpack\n\
\n\
-------------------------------------------------------------------\n\
-- collectgarbage\n\
-- gcinfo\n\
\n\
-- globals\n\
\n\
-- call   -> protect(f, err)\n\
-- loadfile\n\
-- loadstring\n\
\n\
-- rawget\n\
-- rawset\n\
\n\
-- getargs = Main.getargs ??\n\
\n\
rawtype = type\n\
\n\
function do_ (f, err)\n\
  if not f then print(err); return end\n\
  local a,b = pcall(f)\n\
  if not a then print(b); return nil\n\
  else return b or true\n\
  end\n\
end\n\
\n\
function dostring(s) return do_(loadstring(s)) end\n\
-- function dofile(s) return do_(loadfile(s)) end\n\
\n\
-------------------------------------------------------------------\n\
-- Table library\n\
local tab = table\n\
tinsert = tab.insert\n\
tremove = tab.remove\n\
sort = tab.sort\n\
unpack = tab.unpack\n\
\n\
-------------------------------------------------------------------\n\
-- Debug library\n\
local dbg = debug\n\
getinfo = dbg.getinfo\n\
getlocal = dbg.getlocal\n\
setcallhook = function () error\"`setcallhook' is deprecated\" end\n\
setlinehook = function () error\"`setlinehook' is deprecated\" end\n\
setlocal = dbg.setlocal\n\
\n\
-------------------------------------------------------------------\n\
-- math library\n\
local math = math\n\
abs = math.abs\n\
acos = function (x) return math.deg(math.acos(x)) end\n\
asin = function (x) return math.deg(math.asin(x)) end\n\
atan = function (x) return math.deg(math.atan(x)) end\n\
atan2 = function (x,y) return math.deg(math.atan2(x,y)) end\n\
ceil = math.ceil\n\
cos = function (x) return math.cos(math.rad(x)) end\n\
deg = math.deg\n\
exp = math.exp\n\
floor = math.floor\n\
frexp = math.frexp\n\
ldexp = math.ldexp\n\
log = math.log\n\
log10 = math.log10\n\
max = math.max\n\
min = math.min\n\
mod = math.mod\n\
PI = math.pi\n\
--??? pow = math.pow  \n\
rad = math.rad\n\
random = math.random\n\
randomseed = math.randomseed\n\
sin = function (x) return math.sin(math.rad(x)) end\n\
sqrt = math.sqrt\n\
tan = function (x) return math.tan(math.rad(x)) end\n\
\n\
-------------------------------------------------------------------\n\
-- string library\n\
local str = string\n\
strbyte = str.byte\n\
strchar = str.char\n\
strfind = str.find\n\
format = str.format\n\
gsub = str.gsub\n\
strlen = str.len\n\
strlower = str.lower\n\
strrep = str.rep\n\
strsub = str.sub\n\
strupper = str.upper\n\
\n\
-------------------------------------------------------------------\n\
-- os library\n\
clock = os.clock\n\
date = os.date\n\
difftime = os.difftime\n\
execute = os.execute --?\n\
exit = os.exit\n\
getenv = os.getenv\n\
remove = os.remove\n\
rename = os.rename\n\
setlocale = os.setlocale\n\
time = os.time\n\
tmpname = os.tmpname\n\
\n\
-------------------------------------------------------------------\n\
-- compatibility only\n\
getglobal = function (n) return _G[n] end\n\
setglobal = function (n,v) _G[n] = v end\n\
\n\
-------------------------------------------------------------------\n\
\n\
local io, tab = io, table\n\
\n\
-- IO library (files)\n\
_STDIN = io.stdin\n\
_STDERR = io.stderr\n\
_STDOUT = io.stdout\n\
_INPUT = io.stdin\n\
_OUTPUT = io.stdout\n\
seek = io.stdin.seek   -- sick ;-)\n\
tmpfile = io.tmpfile\n\
closefile = io.close\n\
openfile = io.open\n\
\n\
function flush (f)\n\
  if f then f:flush()\n\
  else _OUTPUT:flush()\n\
  end\n\
end\n\
\n\
function readfrom (name)\n\
  if name == nil then\n\
    local f, err, cod = io.close(_INPUT)\n\
    _INPUT = io.stdin\n\
    return f, err, cod\n\
  else\n\
    local f, err, cod = io.open(name, \"r\")\n\
    _INPUT = f or _INPUT\n\
    return f, err, cod\n\
  end\n\
end\n\
\n\
function writeto (name)\n\
  if name == nil then\n\
    local f, err, cod = io.close(_OUTPUT)\n\
    _OUTPUT = io.stdout\n\
    return f, err, cod\n\
  else\n\
    local f, err, cod = io.open(name, \"w\")\n\
    _OUTPUT = f or _OUTPUT\n\
    return f, err, cod\n\
  end\n\
end\n\
\n\
function appendto (name)\n\
  local f, err, cod = io.open(name, \"a\")\n\
  _OUTPUT = f or _OUTPUT\n\
  return f, err, cod\n\
end\n\
\n\
function read (...)\n\
local arg = {...}\n\
local f = _INPUT\n\
if rawtype(arg[1]) == 'userdata' then\n\
f = tab.remove(arg, 1)\n\
end\n\
return f:read(unpack(arg))\n\
end\n\
\n\
function write (...)\n\
local arg = {...}\n\
local f = _OUTPUT\n\
if rawtype(arg[1]) == 'userdata' then\n\
f = tab.remove(arg, 1)\n\
end\n\
return f:write(unpack(arg))\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/compat.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: basic utility functions\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- Last update: Apr 2003\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Basic C types and their corresponding Lua types\n\
-- All occurrences of \"char*\" will be replaced by \"_cstring\",\n\
-- and all occurrences of \"void*\" will be replaced by \"_userdata\"\n\
_basic = {\n\
 ['void'] = '',\n\
 ['char'] = 'number',\n\
 ['int'] = 'number',\n\
 ['short'] = 'number',\n\
 ['long'] = 'number',\n\
 ['unsigned'] = 'number',\n\
 ['float'] = 'number',\n\
 ['double'] = 'number',\n\
 ['_cstring'] = 'string',\n\
 ['_userdata'] = 'userdata',\n\
 ['char*'] = 'string',\n\
 ['void*'] = 'userdata',\n\
 ['bool'] = 'boolean',\n\
 ['lua_Object'] = 'value',\n\
 ['LUA_VALUE'] = 'value',    -- for compatibility with tolua 4.0\n\
 ['lua_State*'] = 'state',\n\
 ['_lstate'] = 'state',\n\
 ['lua_Function'] = 'value',\n\
}\n\
\n\
_basic_ctype = {\n\
 number = \"lua_Number\",\n\
 string = \"const char*\",\n\
 userdata = \"void*\",\n\
 boolean = \"bool\",\n\
 value = \"int\",\n\
 state = \"lua_State*\",\n\
}\n\
\n\
-- functions the are used to do a 'raw push' of basic types\n\
_basic_raw_push = {}\n\
\n\
-- List of user defined types\n\
-- Each type corresponds to a variable name that stores its tag value.\n\
_usertype = {}\n\
\n\
-- List of types that have to be collected\n\
_collect = {}\n\
\n\
-- List of types\n\
_global_types = {n=0}\n\
_global_types_hash = {}\n\
\n\
-- list of classes\n\
_global_classes = {}\n\
\n\
-- List of enum constants\n\
_global_enums = {}\n\
\n\
-- List of auto renaming\n\
_renaming = {}\n\
function appendrenaming (s)\n\
 local b,e,old,new = strfind(s,\"%s*(.-)%s*@%s*(.-)%s*$\")\n\
	if not b then\n\
	 error(\"#Invalid renaming syntax; it should be of the form: pattern@pattern\")\n\
	end\n\
	tinsert(_renaming,{old=old, new=new})\n\
end\n\
\n\
function applyrenaming (s)\n\
	for i=1,#_renaming do\n\
	 local m,n = gsub(s,_renaming[i].old,_renaming[i].new)\n\
		if n ~= 0 then\n\
		 return m\n\
		end\n\
	end\n\
	return nil\n\
end\n\
\n\
-- Error handler\n\
function tolua_error (s,f)\n\
if _curr_code then\n\
	print(\"***curr code for error is \"..tostring(_curr_code))\n\
	print(debug.traceback())\n\
end\n\
 local out = _OUTPUT\n\
 _OUTPUT = _STDERR\n\
 if strsub(s,1,1) == '#' then\n\
  write(\"\\n** tolua: \"..strsub(s,2)..\".\\n\\n\")\n\
  if _curr_code then\n\
   local _,_,s = strfind(_curr_code,\"^%s*(.-\\n)\") -- extract first line\n\
   if s==nil then s = _curr_code end\n\
   s = gsub(s,\"_userdata\",\"void*\") -- return with 'void*'\n\
   s = gsub(s,\"_cstring\",\"char*\")  -- return with 'char*'\n\
   s = gsub(s,\"_lstate\",\"lua_State*\")  -- return with 'lua_State*'\n\
   write(\"Code being processed:\\n\"..s..\"\\n\")\n\
  end\n\
 else\n\
 if not f then f = \"(f is nil)\" end\n\
  print(\"\\n** tolua internal error: \"..f..s..\".\\n\\n\")\n\
  return\n\
 end\n\
 _OUTPUT = out\n\
end\n\
\n\
function warning (msg)\n\
 if flags.q then return end\n\
 local out = _OUTPUT\n\
 _OUTPUT = _STDERR\n\
 write(\"\\n** tolua warning: \"..msg..\".\\n\\n\")\n\
 _OUTPUT = out\n\
end\n\
\n\
-- register an user defined type: returns full type\n\
function regtype (t)\n\
	--if isbasic(t) then\n\
	--	return t\n\
	--end\n\
	local ft = findtype(t)\n\
\n\
	if not _usertype[ft] then\n\
		return appendusertype(t)\n\
	end\n\
	return ft\n\
end\n\
\n\
-- return type name: returns full type\n\
function typevar(type)\n\
	if type == '' or type == 'void' then\n\
		return type\n\
	else\n\
		local ft = findtype(type)\n\
		if ft then\n\
			return ft\n\
		end\n\
		_usertype[type] = type\n\
		return type\n\
	end\n\
end\n\
\n\
-- check if basic type\n\
function isbasic (type)\n\
 local t = gsub(type,'const ','')\n\
 local m,t = applytypedef('', t)\n\
 local b = _basic[t]\n\
 if b then\n\
  return b,_basic_ctype[b]\n\
 end\n\
 return nil\n\
end\n\
\n\
-- split string using a token\n\
function split (s,t)\n\
 local l = {n=0}\n\
 local f = function (s)\n\
  l.n = l.n + 1\n\
  l[l.n] = s\n\
  return \"\"\n\
 end\n\
 local p = \"%s*(.-)%s*\"..t..\"%s*\"\n\
 s = gsub(s,\"^%s+\",\"\")\n\
 s = gsub(s,\"%s+$\",\"\")\n\
 s = gsub(s,p,f)\n\
 l.n = l.n + 1\n\
 l[l.n] = gsub(s,\"(%s%s*)$\",\"\")\n\
 return l\n\
end\n\
\n\
-- splits a string using a pattern, considering the spacial cases of C code (templates, function parameters, etc)\n\
-- pattern can't contain the '^' (as used to identify the begining of the line)\n\
-- also strips whitespace\n\
function split_c_tokens(s, pat)\n\
\n\
	s = string.gsub(s, \"^%s*\", \"\")\n\
	s = string.gsub(s, \"%s*$\", \"\")\n\
\n\
	local token_begin = 1\n\
	local token_end = 1\n\
	local ofs = 1\n\
	local ret = {n=0}\n\
\n\
	function add_token(ofs)\n\
\n\
		local t = string.sub(s, token_begin, ofs)\n\
		t = string.gsub(t, \"^%s*\", \"\")\n\
		t = string.gsub(t, \"%s*$\", \"\")\n\
		ret.n = ret.n + 1\n\
		ret[ret.n] = t\n\
	end\n\
\n\
	while ofs <= string.len(s) do\n\
\n\
		local sub = string.sub(s, ofs, -1)\n\
		local b,e = string.find(sub, \"^\"..pat)\n\
		if b then\n\
			add_token(ofs-1)\n\
			ofs = ofs+e\n\
			token_begin = ofs\n\
		else\n\
			local char = string.sub(s, ofs, ofs)\n\
			if char == \"(\" or char == \"<\" then\n\
\n\
				local block\n\
				if char == \"(\" then block = \"^%b()\" end\n\
				if char == \"<\" then block = \"^%b<>\" end\n\
\n\
				b,e = string.find(sub, block)\n\
				if not b then\n\
					-- unterminated block?\n\
					ofs = ofs+1\n\
				else\n\
					ofs = ofs + e\n\
				end\n\
\n\
			else\n\
				ofs = ofs+1\n\
			end\n\
		end\n\
\n\
	end\n\
	add_token(ofs)\n\
	--if ret.n == 0 then\n\
\n\
	--	ret.n=1\n\
	--	ret[1] = \"\"\n\
	--end\n\
\n\
	return ret\n\
\n\
end\n\
\n\
-- concatenate strings of a table\n\
function concat (t,f,l,jstr)\n\
	jstr = jstr or \" \"\n\
 local s = ''\n\
 local i=f\n\
 while i<=l do\n\
  s = s..t[i]\n\
  i = i+1\n\
  if i <= l then s = s..jstr end\n\
 end\n\
 return s\n\
end\n\
\n\
-- concatenate all parameters, following output rules\n\
function concatparam (line, ...)\n\
 local i=1\n\
 local arg = {...}\n\
 while i<=#arg do\n\
  if _cont and not strfind(_cont,'[%(,\"]') and\n\
     strfind(arg[i],\"^[%a_~]\") then\n\
	    line = line .. '\\t'\n\
  end\n\
  line = line .. arg[i]\n\
  if arg[i] ~= '' then\n\
   _cont = strsub(arg[i],-1,-1)\n\
  end\n\
  i = i+1\n\
 end\n\
 if strfind(arg[#arg],\"[%/%)%;%{%}]$\") then\n\
  _cont=nil line = line .. '\\n'\n\
 end\n\
	return line\n\
end\n\
\n\
-- output line\n\
function output (...)\n\
local arg = {...}\n\
 local i=1\n\
 while i<=#arg do\n\
	print (arg[i])\n\
  if _cont and not strfind(_cont,'[%(,\"]') and\n\
     strfind(arg[i],\"^[%a_~]\") then\n\
	    -- write(' ')\n\
	    write('\\t')\n\
  end\n\
  write(arg[i])\n\
  if arg[i] ~= '' then\n\
   _cont = strsub(arg[i],-1,-1)\n\
  end\n\
  i = i+1\n\
 end\n\
 if strfind(arg[#arg],\"[%/%)%;%{%}]$\") then\n\
  _cont=nil write('\\n')\n\
 end\n\
end\n\
\n\
function get_property_methods(ptype, name)\n\
\n\
	if get_property_methods_hook and get_property_methods_hook(ptype,name) then\n\
		return get_property_methods_hook(ptype, name)\n\
	end\n\
\n\
	if ptype == \"default\" then -- get_name, set_name\n\
		return \"get_\"..name, \"set_\"..name\n\
	end\n\
\n\
	if ptype == \"qt\" then -- name, setName\n\
		return name, \"set\"..string.upper(string.sub(name, 1, 1))..string.sub(name, 2, -1)\n\
	end\n\
\n\
	if ptype == \"overload\" then -- name, name\n\
		return name,name\n\
	end\n\
\n\
	return nil\n\
end\n\
\n\
-------------- the hooks\n\
\n\
-- called right after processing the $[ichl]file directives,\n\
-- right before processing anything else\n\
-- takes the package object as the parameter\n\
function preprocess_hook(p)\n\
	-- p.code has all the input code from the pkg\n\
end\n\
\n\
\n\
-- called for every $ifile directive\n\
-- takes a table with a string called 'code' inside, the filename, and any extra arguments\n\
-- passed to $ifile. no return value\n\
function include_file_hook(t, filename, ...)\n\
\n\
end\n\
\n\
-- called after processing anything that's not code (like '$renaming', comments, etc)\n\
-- and right before parsing the actual code.\n\
-- takes the Package object with all the code on the 'code' key. no return value\n\
function preparse_hook(package)\n\
\n\
end\n\
\n\
-- called before starting output\n\
function pre_output_hook(package)\n\
\n\
end\n\
\n\
-- called after writing all the output.\n\
-- takes the Package object\n\
function post_output_hook(package)\n\
\n\
end\n\
\n\
\n\
-- called from 'get_property_methods' to get the methods to retrieve a property\n\
-- according to its type\n\
function get_property_methods_hook(property_type, name)\n\
\n\
end\n\
\n\
-- called from ClassContainer:doparse with the string being parsed\n\
-- return nil, or a substring\n\
function parser_hook(s)\n\
\n\
	return nil\n\
end\n\
\n\
-- called from classFunction:supcode, before the call to the function is output\n\
function pre_call_hook(f)\n\
\n\
end\n\
\n\
-- called from classFunction:supcode, after the call to the function is output\n\
function post_call_hook(f)\n\
\n\
end\n\
\n\
-- called before the register code is output\n\
function pre_register_hook(package)\n\
\n\
end\n\
\n\
-- called to output an error message\n\
function output_error_hook(...)\n\
	return string.format(...)\n\
end\n\
\n\
-- custom pushers\n\
\n\
_push_functions = {}\n\
_is_functions = {}\n\
_to_functions = {}\n\
\n\
_base_push_functions = {}\n\
_base_is_functions = {}\n\
_base_to_functions = {}\n\
\n\
local function search_base(t, funcs)\n\
\n\
	local class = _global_classes[t]\n\
\n\
	while class do\n\
		if funcs[class.type] then\n\
			return funcs[class.type]\n\
		end\n\
		class = _global_classes[class.btype]\n\
	end\n\
	return nil\n\
end\n\
\n\
function get_push_function(t)\n\
	return _push_functions[t] or search_base(t, _base_push_functions) or \"tolua_pushusertype\"\n\
end\n\
\n\
function get_to_function(t)\n\
	return _to_functions[t] or search_base(t, _base_to_functions) or \"tolua_tousertype\"\n\
end\n\
\n\
function get_is_function(t)\n\
	return _is_functions[t] or search_base(t, _base_is_functions) or \"tolua_isusertype\"\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/basic.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: abstract feature class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Feature class\n\
-- Represents the base class of all mapped feature.\n\
classFeature = {\n\
}\n\
classFeature.__index = classFeature\n\
\n\
-- write support code\n\
function classFeature:supcode ()\n\
end\n\
\n\
-- output tag\n\
function classFeature:decltype ()\n\
end\n\
\n\
-- register feature\n\
function classFeature:register (pre)\n\
end\n\
\n\
-- translate verbatim\n\
function classFeature:preamble ()\n\
end\n\
\n\
-- check if it is a variable\n\
function classFeature:isvariable ()\n\
 return false\n\
end\n\
\n\
-- check if it requires collection\n\
function classFeature:requirecollection (t)\n\
 return false\n\
end\n\
\n\
-- build names\n\
function classFeature:buildnames ()\n\
 if self.name and self.name~='' then\n\
  local n = split(self.name,'@')\n\
  self.name = n[1]\n\
  self.name = string.gsub(self.name, \":%d*$\", \"\")\n\
  if not n[2] then\n\
   n[2] = applyrenaming(n[1])\n\
  end\n\
  self.lname = n[2] or gsub(n[1],\"%[.-%]\",\"\")\n\
  self.lname = string.gsub(self.lname, \":%d*$\", \"\")\n\
  self.original_name = self.name\n\
  self.lname = clean_template(self.lname)\n\
 end\n\
 if not self.is_parameter then\n\
	 self.name = getonlynamespace() .. self.name\n\
 end\n\
\n\
 local parent = classContainer.curr\n\
 if parent then\n\
 	self.access = parent.curr_member_access\n\
	self.global_access = self:check_public_access()\n\
 else\n\
 end\n\
end\n\
\n\
function classFeature:check_public_access()\n\
\n\
	if type(self.global_access) == \"boolean\" then\n\
		return self.global_access\n\
	end\n\
\n\
	if self.access and self.access ~= 0 then\n\
		return false\n\
	end\n\
\n\
	local parent = classContainer.curr\n\
	while parent do\n\
		if parent.access and parent.access ~= 0 then\n\
			return false\n\
		end\n\
		parent = parent.prox\n\
	end\n\
	return true\n\
end\n\
\n\
function clean_template(t)\n\
\n\
	return string.gsub(t, \"[<>:, %*]\", \"_\")\n\
end\n\
\n\
-- check if feature is inside a container definition\n\
-- it returns the container class name or nil.\n\
function classFeature:incontainer (which)\n\
 if self.parent then\n\
  local parent = self.parent\n\
  while parent do\n\
   if parent.classtype == which then\n\
    return parent.name\n\
   end\n\
   parent = parent.parent\n\
  end\n\
 end\n\
 return nil\n\
end\n\
\n\
function classFeature:inclass ()\n\
 return self:incontainer('class')\n\
end\n\
\n\
function classFeature:inmodule ()\n\
 return self:incontainer('module')\n\
end\n\
\n\
function classFeature:innamespace ()\n\
 return self:incontainer('namespace')\n\
end\n\
\n\
-- return C binding function name based on name\n\
-- the client specifies a prefix\n\
function classFeature:cfuncname (n)\n\
\n\
 if self.parent then\n\
  n = self.parent:cfuncname(n)\n\
 end\n\
\n\
 local fname = self.lname\n\
 if not fname or fname == '' then\n\
 	fname = self.name\n\
 end\n\
  n = string.gsub(n..'_'.. (fname), \"[<>:, \.%*&]\", \"_\")\n\
\n\
  return n\n\
end\n\
\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/feature.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */

  	{ /* begin embedded lua code */
		int top = lua_gettop(tolua_S);
		static unsigned char B[] = "\n\
-- tolua: container abstract class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
-- table to store namespaced typedefs/enums in global scope\n\
global_typedefs = {}\n\
global_enums = {}\n\
\n\
-- Container class\n\
-- Represents a container of features to be bound\n\
-- to lua.\n\
classContainer =\n\
{\n\
 curr = nil,\n\
}\n\
classContainer.__index = classContainer\n\
setmetatable(classContainer,classFeature)\n\
\n\
-- output tags\n\
function classContainer:decltype ()\n\
 push(self)\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:decltype()\n\
  i = i+1\n\
 end\n\
 pop()\n\
end\n\
\n\
\n\
-- write support code\n\
function classContainer:supcode ()\n\
\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
\n\
 push(self)\n\
 local i=1\n\
 while self[i] do\n\
  if self[i]:check_public_access() then\n\
  	self[i]:supcode()\n\
  end\n\
  i = i+1\n\
 end\n\
 pop()\n\
end\n\
\n\
function classContainer:hasvar ()\n\
 local i=1\n\
 while self[i] do\n\
  if self[i]:isvariable() then\n\
		 return 1\n\
		end\n\
  i = i+1\n\
 end\n\
	return 0\n\
end\n\
\n\
-- Internal container constructor\n\
function _Container (self)\n\
 setmetatable(self,classContainer)\n\
 self.n = 0\n\
 self.typedefs = {tolua_n=0}\n\
 self.usertypes = {}\n\
 self.enums = {tolua_n=0}\n\
 self.lnames = {}\n\
 return self\n\
end\n\
\n\
-- push container\n\
function push (t)\n\
	t.prox = classContainer.curr\n\
 classContainer.curr = t\n\
end\n\
\n\
-- pop container\n\
function pop ()\n\
--print(\"name\",classContainer.curr.name)\n\
--foreach(classContainer.curr.usertypes,print)\n\
--print(\"______________\")\n\
 classContainer.curr = classContainer.curr.prox\n\
end\n\
\n\
-- get current namespace\n\
function getcurrnamespace ()\n\
	return getnamespace(classContainer.curr)\n\
end\n\
\n\
-- append to current container\n\
function append (t)\n\
 return classContainer.curr:append(t)\n\
end\n\
\n\
-- append typedef to current container\n\
function appendtypedef (t)\n\
 return classContainer.curr:appendtypedef(t)\n\
end\n\
\n\
-- append usertype to current container\n\
function appendusertype (t)\n\
 return classContainer.curr:appendusertype(t)\n\
end\n\
\n\
-- append enum to current container\n\
function appendenum (t)\n\
 return classContainer.curr:appendenum(t)\n\
end\n\
\n\
-- substitute typedef\n\
function applytypedef (mod,type)\n\
 return classContainer.curr:applytypedef(mod,type)\n\
end\n\
\n\
-- check if is type\n\
function findtype (type)\n\
 local t = classContainer.curr:findtype(type)\n\
	return t\n\
end\n\
\n\
-- check if is typedef\n\
function istypedef (type)\n\
 return classContainer.curr:istypedef(type)\n\
end\n\
\n\
-- get fulltype (with namespace)\n\
function fulltype (t)\n\
 local curr =  classContainer.curr\n\
	while curr do\n\
	 if curr then\n\
		 if curr.typedefs and curr.typedefs[t] then\n\
		  return curr.typedefs[t]\n\
		 elseif curr.usertypes and curr.usertypes[t] then\n\
		  return curr.usertypes[t]\n\
			end\n\
		end\n\
	 curr = curr.prox\n\
	end\n\
	return t\n\
end\n\
\n\
-- checks if it requires collection\n\
function classContainer:requirecollection (t)\n\
 push(self)\n\
 local i=1\n\
	local r = false\n\
 while self[i] do\n\
  r = self[i]:requirecollection(t) or r\n\
  i = i+1\n\
 end\n\
	pop()\n\
	return r\n\
end\n\
\n\
\n\
-- get namesapce\n\
function getnamespace (curr)\n\
	local namespace = ''\n\
	while curr do\n\
	 if curr and\n\
		   ( curr.classtype == 'class' or curr.classtype == 'namespace')\n\
		then\n\
		 namespace = (curr.original_name or curr.name) .. '::' .. namespace\n\
		 --namespace = curr.name .. '::' .. namespace\n\
		end\n\
	 curr = curr.prox\n\
	end\n\
	return namespace\n\
end\n\
\n\
-- get namespace (only namespace)\n\
function getonlynamespace ()\n\
 local curr = classContainer.curr\n\
	local namespace = ''\n\
	while curr do\n\
		if curr.classtype == 'class' then\n\
		 return namespace\n\
		elseif curr.classtype == 'namespace' then\n\
		 namespace = curr.name .. '::' .. namespace\n\
		end\n\
	 curr = curr.prox\n\
	end\n\
	return namespace\n\
end\n\
\n\
-- check if is enum\n\
function isenum (type)\n\
 return classContainer.curr:isenum(type)\n\
end\n\
\n\
-- append feature to container\n\
function classContainer:append (t)\n\
 self.n = self.n + 1\n\
 self[self.n] = t\n\
 t.parent = self\n\
end\n\
\n\
-- append typedef\n\
function classContainer:appendtypedef (t)\n\
 local namespace = getnamespace(classContainer.curr)\n\
 self.typedefs.tolua_n = self.typedefs.tolua_n + 1\n\
 self.typedefs[self.typedefs.tolua_n] = t\n\
	self.typedefs[t.utype] = namespace .. t.utype\n\
	global_typedefs[namespace..t.utype] = t\n\
	t.ftype = findtype(t.type) or t.type\n\
	--print(\"appending typedef \"..t.utype..\" as \"..namespace..t.utype..\" with ftype \"..t.ftype)\n\
	append_global_type(namespace..t.utype)\n\
	if t.ftype and isenum(t.ftype) then\n\
\n\
		global_enums[namespace..t.utype] = true\n\
	end\n\
end\n\
\n\
-- append usertype: return full type\n\
function classContainer:appendusertype (t)\n\
	local container\n\
	if t == (self.original_name or self.name) then\n\
		container = self.prox\n\
	else\n\
		container = self\n\
	end\n\
	local ft = getnamespace(container) .. t\n\
	container.usertypes[t] = ft\n\
	_usertype[ft] = ft\n\
	return ft\n\
end\n\
\n\
-- append enum\n\
function classContainer:appendenum (t)\n\
 local namespace = getnamespace(classContainer.curr)\n\
 self.enums.tolua_n = self.enums.tolua_n + 1\n\
 self.enums[self.enums.tolua_n] = t\n\
	global_enums[namespace..t.name] = t\n\
end\n\
\n\
-- determine lua function name overload\n\
function classContainer:overload (lname)\n\
 if not self.lnames[lname] then\n\
  self.lnames[lname] = 0\n\
 else\n\
  self.lnames[lname] = self.lnames[lname] + 1\n\
 end\n\
 return format(\"%02d\",self.lnames[lname])\n\
end\n\
\n\
-- applies typedef: returns the 'the facto' modifier and type\n\
function classContainer:applytypedef (mod,type)\n\
	if global_typedefs[type] then\n\
		--print(\"found typedef \"..global_typedefs[type].type)\n\
		local mod1, type1 = global_typedefs[type].mod, global_typedefs[type].ftype\n\
		local mod2, type2 = applytypedef(mod..\" \"..mod1, type1)\n\
		--return mod2 .. ' ' .. mod1, type2\n\
		return mod2, type2\n\
	end\n\
	do return mod,type end\n\
end\n\
\n\
-- check if it is a typedef\n\
function classContainer:istypedef (type)\n\
 local env = self\n\
 while env do\n\
  if env.typedefs then\n\
   local i=1\n\
   while env.typedefs[i] do\n\
    if env.typedefs[i].utype == type then\n\
         return type\n\
        end\n\
        i = i+1\n\
   end\n\
  end\n\
  env = env.parent\n\
 end\n\
 return nil\n\
end\n\
\n\
function find_enum_var(var)\n\
\n\
	if tonumber(var) then return var end\n\
\n\
	local c = classContainer.curr\n\
	while c do\n\
		local ns = getnamespace(c)\n\
		for k,v in pairs(_global_enums) do\n\
			if match_type(var, v, ns) then\n\
				return v\n\
			end\n\
		end\n\
		if c.base and c.base ~= '' then\n\
			c = _global_classes[c:findtype(c.base)]\n\
		else\n\
			c = nil\n\
		end\n\
	end\n\
\n\
	return var\n\
end\n\
\n\
-- check if is a registered type: return full type or nil\n\
function classContainer:findtype (t)\n\
\n\
	t = string.gsub(t, \"=.*\", \"\")\n\
	if _basic[t] then\n\
	 return t\n\
	end\n\
\n\
	local _,_,em = string.find(t, \"([&%*])%s*$\")\n\
	t = string.gsub(t, \"%s*([&%*])%s*$\", \"\")\n\
	p = self\n\
	while p and type(p)=='table' do\n\
		local st = getnamespace(p)\n\
\n\
		for i=_global_types.n,1,-1 do -- in reverse order\n\
\n\
			if match_type(t, _global_types[i], st) then\n\
				return _global_types[i]..(em or \"\")\n\
			end\n\
		end\n\
		if p.base and p.base ~= '' and p.base ~= t then\n\
			--print(\"type is \"..t..\", p is \"..p.base..\" self.type is \"..self.type..\" self.name is \"..self.name)\n\
			p = _global_classes[p:findtype(p.base)]\n\
		else\n\
			p = nil\n\
		end\n\
	end\n\
\n\
	return nil\n\
end\n\
\n\
function append_global_type(t, class)\n\
	_global_types.n = _global_types.n +1\n\
	_global_types[_global_types.n] = t\n\
	_global_types_hash[t] = 1\n\
	if class then append_class_type(t, class) end\n\
end\n\
\n\
function append_class_type(t,class)\n\
	if _global_classes[t] then\n\
		class.flags = _global_classes[t].flags\n\
		class.lnames = _global_classes[t].lnames\n\
		if _global_classes[t].base and (_global_classes[t].base ~= '') then\n\
			class.base = _global_classes[t].base or class.base\n\
		end\n\
	end\n\
	_global_classes[t] = class\n\
	class.flags = class.flags or {}\n\
end\n\
\n\
function match_type(childtype, regtype, st)\n\
--print(\"findtype \"..childtype..\", \"..regtype..\", \"..st)\n\
	local b,e = string.find(regtype, childtype, -string.len(childtype), true)\n\
	if b then\n\
\n\
		if e == string.len(regtype) and\n\
				(b == 1 or (string.sub(regtype, b-1, b-1) == ':' and\n\
				string.sub(regtype, 1, b-1) == string.sub(st, 1, b-1))) then\n\
			return true\n\
		end\n\
	end\n\
\n\
	return false\n\
end\n\
\n\
function findtype_on_childs(self, t)\n\
\n\
	local tchild\n\
	if self.classtype == 'class' or self.classtype == 'namespace' then\n\
		for k,v in ipairs(self) do\n\
			if v.classtype == 'class' or v.classtype == 'namespace' then\n\
				if v.typedefs and v.typedefs[t] then\n\
				 return v.typedefs[t]\n\
				elseif v.usertypes and v.usertypes[t] then\n\
				 return v.usertypes[t]\n\
				end\n\
				tchild = findtype_on_childs(v, t)\n\
				if tchild then return tchild end\n\
			end\n\
		end\n\
	end\n\
	return nil\n\
\n\
end\n\
\n\
function classContainer:isenum (type)\n\
 if global_enums[type] then\n\
	return type\n\
 else\n\
 	return false\n\
 end\n\
\n\
 local basetype = gsub(type,\"^.*::\",\"\")\n\
 local env = self\n\
 while env do\n\
  if env.enums then\n\
   local i=1\n\
   while env.enums[i] do\n\
    if env.enums[i].name == basetype then\n\
         return true\n\
        end\n\
        i = i+1\n\
   end\n\
  end\n\
  env = env.parent\n\
 end\n\
 return false\n\
end\n\
\n\
methodisvirtual = false -- a global\n\
\n\
-- parse chunk\n\
function classContainer:doparse (s)\n\
--print (\"parse \"..s)\n\
\n\
 -- try the parser hook\n\
 do\n\
 	local sub = parser_hook(s)\n\
 	if sub then\n\
 		return sub\n\
 	end\n\
 end\n\
\n\
 -- try the null statement\n\
 do\n\
 	local b,e,code = string.find(s, \"^%s*;\")\n\
 	if b then\n\
 		return strsub(s,e+1)\n\
 	end\n\
 end\n\
\n\
 -- try empty verbatim line\n\
 do\n\
 	local b,e,code = string.find(s, \"^%s*$\\n\")\n\
 	if b then\n\
 		return strsub(s,e+1)\n\
 	end\n\
 end\n\
\n\
 -- try Lua code\n\
 do\n\
  local b,e,code = strfind(s,\"^%s*(%b\\1\\2)\")\n\
  if b then\n\
   Code(strsub(code,2,-2))\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try C code\n\
 do\n\
  local b,e,code = strfind(s,\"^%s*(%b\\3\\4)\")\n\
  if b then\n\
	code = '{'..strsub(code,2,-2)..'\\n}\\n'\n\
	Verbatim(code,'r')        -- verbatim code for 'r'egister fragment\n\
	return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try C code for preamble section\n\
 do\n\
 	local b,e,code = string.find(s, \"^%s*(%b\\5\\6)\")\n\
 	if b then\n\
 		code = string.sub(code, 2, -2)..\"\\n\"\n\
		Verbatim(code, '')\n\
		return string.sub(s, e+1)\n\
 	end\n\
 end\n\
\n\
 -- try default_property directive\n\
 do\n\
 	local b,e,ptype = strfind(s, \"^%s*TOLUA_PROPERTY_TYPE%s*%(+%s*([^%)%s]*)%s*%)+%s*;?\")\n\
 	if b then\n\
 		if not ptype or ptype == \"\" then\n\
 			ptype = \"default\"\n\
 		end\n\
 		self:set_property_type(ptype)\n\
	 	return strsub(s, e+1)\n\
 	end\n\
 end\n\
\n\
 -- try protected_destructor directive\n\
 do\n\
 	local b,e = string.find(s, \"^%s*TOLUA_PROTECTED_DESTRUCTOR%s*;?\")\n\
	if b then\n\
		if self.set_protected_destructor then\n\
	 		self:set_protected_destructor(true)\n\
	 	end\n\
 		return strsub(s, e+1)\n\
 	end\n\
 end\n\
\n\
 -- try 'extern' keyword\n\
 do\n\
 	local b,e = string.find(s, \"^%s*extern%s+\")\n\
 	if b then\n\
		-- do nothing\n\
 		return strsub(s, e+1)\n\
 	end\n\
 end\n\
\n\
 -- try 'virtual' keyworkd\n\
 do\n\
 	local b,e = string.find(s, \"^%s*virtual%s+\")\n\
 	if b then\n\
 		methodisvirtual = true\n\
 		return strsub(s, e+1)\n\
 	end\n\
 end\n\
\n\
 -- try labels (public, private, etc)\n\
 do\n\
 	local b,e = string.find(s, \"^%s*%w*%s*:[^:]\")\n\
 	if b then\n\
 		return strsub(s, e) -- preserve the [^:]\n\
 	end\n\
 end\n\
\n\
 -- try module\n\
 do\n\
  local b,e,name,body = strfind(s,\"^%s*module%s%s*([_%w][_%w]*)%s*(%b{})%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Module(name,body)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try namesapce\n\
 do\n\
  local b,e,name,body = strfind(s,\"^%s*namespace%s%s*([_%w][_%w]*)%s*(%b{})%s*;?\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Namespace(name,body)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try define\n\
 do\n\
  local b,e,name = strfind(s,\"^%s*#define%s%s*([^%s]*)[^\\n]*\\n%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Define(name)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try enumerates\n\
\n\
 do\n\
  local b,e,name,body,varname = strfind(s,\"^%s*enum%s+(%S*)%s*(%b{})%s*([^%s;]*)%s*;?%s*\")\n\
  if b then\n\
   --error(\"#Sorry, declaration of enums and variables on the same statement is not supported.\\nDeclare your variable separately (example: '\"..name..\" \"..varname..\";')\")\n\
   _curr_code = strsub(s,b,e)\n\
   Enumerate(name,body,varname)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
-- do\n\
--  local b,e,name,body = strfind(s,\"^%s*enum%s+(%S*)%s*(%b{})%s*;?%s*\")\n\
--  if b then\n\
--   _curr_code = strsub(s,b,e)\n\
--   Enumerate(name,body)\n\
--  return strsub(s,e+1)\n\
--  end\n\
-- end\n\
\n\
 do\n\
  local b,e,body,name = strfind(s,\"^%s*typedef%s+enum[^{]*(%b{})%s*([%w_][^%s]*)%s*;%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Enumerate(name,body)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try operator\n\
 do\n\
  local b,e,decl,kind,arg,const = strfind(s,\"^%s*([_%w][_%w%s%*&:<>,]-%s+operator)%s*([^%s][^%s]*)%s*(%b())%s*(c?o?n?s?t?)%s*;%s*\")\n\
  if not b then\n\
		 -- try inline\n\
   b,e,decl,kind,arg,const = strfind(s,\"^%s*([_%w][_%w%s%*&:<>,]-%s+operator)%s*([^%s][^%s]*)%s*(%b())%s*(c?o?n?s?t?)[%s\\n]*%b{}%s*;?%s*\")\n\
  end\n\
  if not b then\n\
  	-- try cast operator\n\
  	b,e,decl,kind,arg,const = strfind(s, \"^%s*(operator)%s+([%w_:%d<>%*%&%s]+)%s*(%b())%s*(c?o?n?s?t?)\");\n\
  	if b then\n\
  		local _,ie = string.find(s, \"^%s*%b{}\", e+1)\n\
  		if ie then\n\
  			e = ie\n\
  		end\n\
  	end\n\
  end\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Operator(decl,kind,arg,const)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try function\n\
 do\n\
  --local b,e,decl,arg,const = strfind(s,\"^%s*([~_%w][_@%w%s%*&:<>]*[_%w])%s*(%b())%s*(c?o?n?s?t?)%s*=?%s*0?%s*;%s*\")\n\
  local b,e,decl,arg,const,virt = strfind(s,\"^%s*([^%(\\n]+)%s*(%b())%s*(c?o?n?s?t?)%s*(=?%s*0?)%s*;%s*\")\n\
  if not b then\n\
  	-- try function with template\n\
  	b,e,decl,arg,const = strfind(s,\"^%s*([~_%w][_@%w%s%*&:<>]*[_%w]%b<>)%s*(%b())%s*(c?o?n?s?t?)%s*=?%s*0?%s*;%s*\")\n\
  end\n\
  if not b then\n\
   -- try a single letter function name\n\
   b,e,decl,arg,const = strfind(s,\"^%s*([_%w])%s*(%b())%s*(c?o?n?s?t?)%s*;%s*\")\n\
  end\n\
  if not b then\n\
   -- try function pointer\n\
   b,e,decl,arg,const = strfind(s,\"^%s*([^%(;\\n]+%b())%s*(%b())%s*;%s*\")\n\
   if b then\n\
    decl = string.gsub(decl, \"%(%s*%*([^%)]*)%s*%)\", \" %1 \")\n\
   end\n\
  end\n\
  if b then\n\
  	if virt and string.find(virt, \"[=0]\") then\n\
  		if self.flags then\n\
  			self.flags.pure_virtual = true\n\
  		end\n\
  	end\n\
   _curr_code = strsub(s,b,e)\n\
   Function(decl,arg,const)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try inline function\n\
 do\n\
  local b,e,decl,arg,const = strfind(s,\"^%s*([^%(\\n]+)%s*(%b())%s*(c?o?n?s?t?)[^;{]*%b{}%s*;?%s*\")\n\
  --local b,e,decl,arg,const = strfind(s,\"^%s*([~_%w][_@%w%s%*&:<>]*[_%w>])%s*(%b())%s*(c?o?n?s?t?)[^;]*%b{}%s*;?%s*\")\n\
  if not b then\n\
   -- try a single letter function name\n\
   b,e,decl,arg,const = strfind(s,\"^%s*([_%w])%s*(%b())%s*(c?o?n?s?t?).-%b{}%s*;?%s*\")\n\
  end\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Function(decl,arg,const)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try class\n\
 do\n\
	 local b,e,name,base,body\n\
		base = '' body = ''\n\
		b,e,name = strfind(s,\"^%s*class%s*([_%w][_%w@]*)%s*;\")  -- dummy class\n\
		local dummy = false\n\
		if not b then\n\
			b,e,name = strfind(s,\"^%s*struct%s*([_%w][_%w@]*)%s*;\")    -- dummy struct\n\
			if not b then\n\
				b,e,name,base,body = strfind(s,\"^%s*class%s*([_%w][_%w@]*)%s*([^{]-)%s*(%b{})%s*\")\n\
				if not b then\n\
					b,e,name,base,body = strfind(s,\"^%s*struct%s+([_%w][_%w@]*)%s*([^{]-)%s*(%b{})%s*\")\n\
					if not b then\n\
						b,e,name,base,body = strfind(s,\"^%s*union%s*([_%w][_%w@]*)%s*([^{]-)%s*(%b{})%s*\")\n\
						if not b then\n\
							base = ''\n\
							b,e,body,name = strfind(s,\"^%s*typedef%s%s*struct%s%s*[_%w]*%s*(%b{})%s*([_%w][_%w@]*)%s*;\")\n\
						end\n\
					end\n\
				end\n\
			else dummy = 1 end\n\
		else dummy = 1 end\n\
		if b then\n\
			if base ~= '' then\n\
				base = string.gsub(base, \"^%s*:%s*\", \"\")\n\
				base = string.gsub(base, \"%s*public%s*\", \"\")\n\
				base = split(base, \",\")\n\
				--local b,e\n\
				--b,e,base = strfind(base,\".-([_%w][_%w<>,:]*)$\")\n\
			else\n\
				base = {}\n\
			end\n\
			_curr_code = strsub(s,b,e)\n\
			Class(name,base,body)\n\
			if not dummy then\n\
				varb,vare,varname = string.find(s, \"^%s*([_%w]+)%s*;\", e+1)\n\
				if varb then\n\
					Variable(name..\" \"..varname)\n\
					e = vare\n\
				end\n\
			end\n\
			return strsub(s,e+1)\n\
		end\n\
	end\n\
\n\
 -- try typedef\n\
 do\n\
  local b,e,types = strfind(s,\"^%s*typedef%s%s*(.-)%s*;%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Typedef(types)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try variable\n\
 do\n\
  local b,e,decl = strfind(s,\"^%s*([_%w][_@%s%w%d%*&:<>,]*[_%w%d])%s*;%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
\n\
	local list = split_c_tokens(decl, \",\")\n\
	Variable(list[1])\n\
	if list.n > 1 then\n\
		local _,_,type = strfind(list[1], \"(.-)%s+([^%s]*)$\");\n\
\n\
		local i =2;\n\
		while list[i] do\n\
			Variable(type..\" \"..list[i])\n\
			i=i+1\n\
		end\n\
	end\n\
   --Variable(decl)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
	-- try string\n\
 do\n"
  "local b,e,decl = strfind(s,\"^%s*([_%w]?[_%s%w%d]-char%s+[_@%w%d]*%s*%[%s*%S+%s*%])%s*;%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Variable(decl)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- try array\n\
 do\n\
  local b,e,decl = strfind(s,\"^%s*([_%w][][_@%s%w%d%*&:<>]*[]_%w%d])%s*;%s*\")\n\
  if b then\n\
   _curr_code = strsub(s,b,e)\n\
   Array(decl)\n\
   return strsub(s,e+1)\n\
  end\n\
 end\n\
\n\
 -- no matching\n\
 if gsub(s,\"%s%s*\",\"\") ~= \"\" then\n\
  _curr_code = s\n\
  error(\"#parse error\")\n\
 else\n\
  return \"\"\n\
 end\n\
\n\
end\n\
\n\
function classContainer:parse (s)\n\
\n\
	--self.curr_member_access = nil\n\
\n\
 while s ~= '' do\n\
  s = self:doparse(s)\n\
  methodisvirtual = false\n\
 end\n\
end\n\
\n\
\n\
-- property types\n\
\n\
function get_property_type()\n\
\n\
	return classContainer.curr:get_property_type()\n\
end\n\
\n\
function classContainer:set_property_type(ptype)\n\
	ptype = string.gsub(ptype, \"^%s*\", \"\")\n\
	ptype = string.gsub(ptype, \"%s*$\", \"\")\n\
\n\
	self.property_type = ptype\n\
end\n\
\n\
function classContainer:get_property_type()\n\
	return self.property_type or (self.parent and self.parent:get_property_type()) or \"default\"\n\
end\n\
";
		int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/container.lua");
		if (0 != error)
		{
			printf("%s", lua_tostring(tolua_S, -1));
		}
		lua_settop(tolua_S, top);
	} /* end of embedded lua code */

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: verbatim class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: verbatim.lua,v 1.3 2000/01/24 20:41:16 celes Exp $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
\n\
-- Verbatim class\n\
-- Represents a line translated directed to the binding file.\n\
-- The following filds are stored:\n\
--   line = line text\n\
classVerbatim = {\n\
 line = '',\n\
	cond = nil,    -- condition: where to generate the code (s=suport, r=register)\n\
}\n\
classVerbatim.__index = classVerbatim\n\
setmetatable(classVerbatim,classFeature)\n\
\n\
-- preamble verbatim\n\
function classVerbatim:preamble ()\n\
 if self.cond == '' then\n\
  write(self.line)\n\
 end\n\
end\n\
\n\
-- support code\n\
function classVerbatim:supcode ()\n\
 if strfind(self.cond,'s') then\n\
  write(self.line)\n\
  write('\\n')\n\
 end\n\
end\n\
\n\
-- register code\n\
function classVerbatim:register (pre)\n\
 if strfind(self.cond,'r') then\n\
  write(self.line)\n\
 end\n\
end\n\
\n\
\n\
-- Print method\n\
function classVerbatim:print (ident,close)\n\
 print(ident..\"Verbatim{\")\n\
 print(ident..\" line = '\"..self.line..\"',\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
\n\
-- Internal constructor\n\
function _Verbatim (t)\n\
 setmetatable(t,classVerbatim)\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects a string representing the text line\n\
function Verbatim (l,cond)\n\
 if strsub(l,1,1) == \"'\" then\n\
  l = strsub(l,2)\n\
 elseif strsub(l,1,1) == '$' then\n\
  cond = 'sr'       -- generates in both suport and register fragments\n\
  l = strsub(l,2)\n\
 end\n\
 return _Verbatim {\n\
  line = l,\n\
  cond = cond or '',\n\
 }\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/verbatim.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: code class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1999\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
-- global\n\
code_n = 1\n\
\n\
-- Code class\n\
-- Represents Lua code to be compiled and included\n\
-- in the initialization function.\n\
-- The following fields are stored:\n\
--   text = text code\n\
classCode = {\n\
 text = '',\n\
}\n\
classCode.__index = classCode\n\
setmetatable(classCode,classFeature)\n\
\n\
-- register code\n\
function classCode:register (pre)\n\
 pre = pre or ''\n\
 -- clean Lua code\n\
 local s = clean(self.text)\n\
 if not s then\n\
  --print(self.text)\n\
  error(\"parser error in embedded code\")\n\
 end\n\
\n\
 -- get first line\n\
 local _, _, first_line=string.find(self.text, \"^([^\\n\\r]*)\")\n\
 if string.find(first_line, \"^%s*%-%-\") then\n\
	 if string.find(first_line, \"^%-%-##\") then\n\
		first_line = string.gsub(first_line, \"^%-%-##\", \"\")\n\
		if flags['C'] then\n\
			s = string.gsub(s, \"^%-%-##[^\\n\\r]*\\n\", \"\")\n\
		end\n\
	 end\n\
 else\n\
 	first_line = \"\"\n\
 end\n\
\n\
 -- pad to 16 bytes\n\
 local npad = 16 - (#s % 16)\n\
 local spad = \"\"\n\
 for i=1,npad do\n\
 	spad = spad .. \"-\"\n\
 end\n\
 s = s..spad\n\
 \n\
 -- convert to C\n\
 output('\\n\'..pre..'{ /* begin embedded lua code */\\n')\n\
 output(pre..' int top = lua_gettop(tolua_S);')\n\
 output(pre..' static const unsigned char B[] = {\\n   ')\n\
 local t={n=0}\n\
\n\
 local b = gsub(s,'(.)',function (c)\n\
                         local e = ''\n\
                         t.n=t.n+1 if t.n==15 then t.n=0 e='\\n'..pre..'  ' end\n\
                         return format('%3u,%s',strbyte(c),e)\n\
                        end\n\
               )\n\
 output(b..strbyte(\" \"))\n\
 output('\\n'..pre..' };\\n')\n\
 if first_line and first_line ~= \"\" then\n\
 	output(pre..' tolua_dobuffer(tolua_S,(char*)B,strlen(B),\"tolua embedded: '..first_line..'\");')\n\
 else\n\
 	output(pre..' tolua_dobuffer(tolua_S,(char*)B,strlen(B),\"tolua: embedded Lua code '..code_n..'\");')\n\
 end\n\
 output(pre..' lua_settop(tolua_S, top);')\n\
 output(pre..'} /* end of embedded lua code */\\n\\n')\n\
 code_n = code_n +1\n\
end\n\
\n\
\n\
-- Print method\n\
function classCode:print (ident,close)\n\
 print(ident..\"Code{\")\n\
 print(ident..\" text = [[\"..self.text..\"]],\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
\n\
-- Internal constructor\n\
function _Code (t)\n\
 setmetatable(t,classCode)\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects a string representing the code text\n\
function Code (l)\n\
 return _Code {\n\
  text = l\n\
 }\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/code.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: typedef class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
\n\
-- Typedef class\n\
-- Represents a type synonym.\n\
-- The 'de facto' type replaces the typedef before the\n\
-- remaining code is parsed.\n\
-- The following fields are stored:\n\
--   utype = typedef name\n\
--   type = 'the facto' type\n\
--   mod = modifiers to the 'de facto' type\n\
classTypedef = {\n\
 utype = '',\n\
 mod = '',\n\
 type = ''\n\
}\n\
classTypedef.__index = classTypedef\n\
\n\
-- Print method\n\
function classTypedef:print (ident,close)\n\
 print(ident..\"Typedef{\")\n\
 print(ident..\" utype = '\"..self.utype..\"',\")\n\
 print(ident..\" mod = '\"..self.mod..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- Return it's not a variable\n\
function classTypedef:isvariable ()\n\
 return false\n\
end\n\
\n\
-- Internal constructor\n\
function _Typedef (t)\n\
 setmetatable(t,classTypedef)\n\
 t.type = resolve_template_types(t.type)\n\
 appendtypedef(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects one string representing the type definition.\n\
function Typedef (s)\n\
 if strfind(string.gsub(s, '%b<>', ''),'[%*&]') then\n\
  tolua_error(\"#invalid typedef: pointers (and references) are not supported\")\n\
 end\n\
 local o = {mod = ''}\n\
 if string.find(s, \"[<>]\") then\n\
 	_,_,o.type,o.utype = string.find(s, \"^%s*([^<>]+%b<>[^%s]*)%s+(.-)$\")\n\
 else\n\
 	local t = split(gsub(s,\"%s%s*\",\" \"),\" \")\n\
 	o = {\n\
	  utype = t[t.n],\n\
	  type = t[t.n-1],\n\
	  mod = concat(t,1,t.n-2),\n\
	 }\n\
 end\n\
 return _Typedef(o)\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/typedef.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: package class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
\n\
-- Package class\n\
-- Represents the whole package being bound.\n\
-- The following fields are stored:\n\
--    {i} = list of objects in the package.\n\
classPackage = {\n\
	classtype = 'package'\n\
}\n\
classPackage.__index = classPackage\n\
setmetatable(classPackage,classContainer)\n\
\n\
-- Print method\n\
function classPackage:print ()\n\
	print(\"Package: \"..self.name)\n\
	local i=1\n\
	while self[i] do\n\
		self[i]:print(\"\",\"\")\n\
		i = i+1\n\
	end\n\
end\n\
\n\
function classPackage:preprocess ()\n\
\n\
	-- avoid preprocessing embedded Lua code\n\
	local L = {}\n\
	self.code = gsub(self.code,\"\\n%s*%$%[\",\"\1\") -- deal with embedded lua code\n\
	self.code = gsub(self.code,\"\\n%s*%$%]\",\"\2\")\n\
	self.code = gsub(self.code,\"(%b\\1\\2)\",       function (c)\n\
		tinsert(L,c)\n\
		return \"\\n#[\"..#L..\"]#\"\n\
	end)\n\
	-- avoid preprocessing embedded C code\n\
	local C = {}\n\
	self.code = gsub(self.code,\"\\n%s*%$%<\",\"\\3\") -- deal with embedded C code\n\
	self.code = gsub(self.code,\"\\n%s*%$%>\",\"\\4\")\n\
	self.code = gsub(self.code,\"(%b\\3\\4)\",       function (c)\n\
		tinsert(C,c)\n\
		return \"\\n#<\"..#C..\">#\"\n\
	end)\n\
	-- avoid preprocessing embedded C code\n\
	self.code = gsub(self.code,\"\\n%s*%$%{\",\"\\5\") -- deal with embedded C code\n\
	self.code = gsub(self.code,\"\\n%s*%$%}\",\"\\6\")\n\
	self.code = gsub(self.code,\"(%b\\5\\6)\",       function (c)\n\
		tinsert(C,c)\n\
		return \"\\n#<\"..#C..\">#\"\n\
	end)\n\
\n\
	--self.code = gsub(self.code,\"\\n%s*#[^d][^\\n]*\\n\", \"\\n\\n\") -- eliminate preprocessor directives that don't start with 'd'\n\
	self.code = gsub(self.code,\"\\n[ \\t]*#[ \\t]*[^d%<%[]\", \"\\n//\") -- eliminate preprocessor directives that don't start with 'd'\n\
\n\
	-- avoid preprocessing verbatim lines\n\
	local V = {}\n\
	self.code = gsub(self.code,\"\\n(%s*%$[^%[%]][^\\n]*)\",function (v)\n\
		tinsert(V,v)\n\
		-- return \"\\n#\"..#V..\"#\"\n\
		return \"\\n#\"..#V..\"#\"\n\
	end)\n\
\n\
	-- perform global substitution\n\
\n\
	self.code = gsub(self.code,\"(//[^\\n]*)\",\"\")     -- eliminate C++ comments\n\
	self.code = gsub(self.code,\"/%*\",\"\\1\")\n\
	self.code = gsub(self.code,\"%*/\",\"\\2\")\n\
	self.code = gsub(self.code,\"%b\\1\\2\",\"\")\n\
	self.code = gsub(self.code,\"\\1\",\"/%*\")\n\
	self.code = gsub(self.code,\"\\2\",\"%*/\")\n\
	self.code = gsub(self.code,\"%s*@%s*\",\"@\") -- eliminate spaces beside @\n\
	self.code = gsub(self.code,\"%s?inline(%s)\",\"%1\") -- eliminate 'inline' keyword\n\
	--self.code = gsub(self.code,\"%s?extern(%s)\",\"%1\") -- eliminate 'extern' keyword\n\
	--self.code = gsub(self.code,\"%s?virtual(%s)\",\"%1\") -- eliminate 'virtual' keyword\n\
	--self.code = gsub(self.code,\"public:\",\"\") -- eliminate 'public:' keyword\n\
	self.code = gsub(self.code,\"([^%w_])void%s*%*\",\"%1_userdata \") -- substitute 'void*'\n\
	self.code = gsub(self.code,\"([^%w_])void%s*%*\",\"%1_userdata \") -- substitute 'void*'\n\
	self.code = gsub(self.code,\"([^%w_])char%s*%*\",\"%1_cstring \")  -- substitute 'char*'\n\
	self.code = gsub(self.code,\"([^%w_])lua_State%s*%*\",\"%1_lstate \")  -- substitute 'lua_State*'\n\
\n\
	-- restore embedded Lua code\n\
	self.code = gsub(self.code,\"%#%[(%d+)%]%#\",function (n)\n\
		return L[tonumber(n)]\n\
	end)\n\
	-- restore embedded C code\n\
	self.code = gsub(self.code,\"%#%<(%d+)%>%#\",function (n)\n\
		return C[tonumber(n)]\n\
	end)\n\
	-- restore verbatim lines\n\
	self.code = gsub(self.code,\"%#(%d+)%#\",function (n)\n\
		return V[tonumber(n)]\n\
	end)\n\
\n\
	self.code = string.gsub(self.code, \"\\n%s*%$([^\\n]+)\", function (l)\n\
		Verbatim(l..\"\\n\")\n\
		return \"\\n\"\n\
	end)\n\
end\n\
\n\
-- translate verbatim\n\
function classPackage:preamble ()\n\
	output('/*\\n')\n\
	output('** Lua binding: '..self.name..'\\n')\n\
	output('** Generated automatically by '..TOLUA_VERSION..' on '..date()..'.\\n')\n\
	output('*/\\n\\n')\n\
\n\
	output('#ifndef __cplusplus\\n')\n\
	output('#include \"stdlib.h\"\\n')\n\
	output('#endif\\n')\n\
	output('#include \"string.h\"\\n\\n')\n\
	output('#include \"tolua++.h\"\\n\\n')\n\
\n\
	if not flags.h then\n\
		output('/* Exported function */')\n\
		output('TOLUA_API int  tolua_'..self.name..'_open (lua_State* tolua_S);')\n\
		output('\\n')\n\
	end\n\
\n\
	local i=1\n\
	while self[i] do\n\
		self[i]:preamble()\n\
		i = i+1\n\
	end\n\
\n\
	if self:requirecollection(_collect) then\n\
		output('\\n')\n\
		output('/* function to release collected object via destructor */')\n\
		output('#ifdef __cplusplus\\n')\n\
		for i,v in pairs(_collect) do\n\
			output('\\nstatic int '..v..' (lua_State* tolua_S)')\n\
			output('{')\n\
			output('\\t'..i..'* self = ('..i..'*) tolua_tousertype(tolua_S,1,0);')\n\
			output('\\tMtolua_delete(self);')\n\
			output('\\treturn 0;')\n\
			output('}')\n\
		end\n\
		output('#endif\\n\\n')\n\
	end\n\
\n\
	output('\\n')\n\
	output('/* function to register type */')\n\
	output('static void tolua_reg_types (lua_State* tolua_S)')\n\
	output('{')\n\
\n\
	if flags.t then\n\
		output(\"#ifndef Mtolua_typeid\\n#define Mtolua_typeid(L,TI,T)\\n#endif\\n\")\n\
	end\n\
	for n,v in pairs(_usertype) do\n\
		if (not _global_classes[v]) or _global_classes[v]:check_public_access() then\n\
			output('\ttolua_usertype(tolua_S,\"',v,'\");')\n\
			if flags.t then\n\
				output(' Mtolua_typeid(tolua_S,typeid(',v,'), \"',v,'\");')\n\
			end\n\
		end\n\
	end\n\
	output('}')\n\
	output('\\n')\n\
end\n\
\n\
-- register package\n\
-- write package open function\n\
function classPackage:register (pre)\n\
	pre = pre or ''\n\
	push(self)\n\
	output(pre..\"/* Open function */\")\n\
	output(pre..\"TOLUA_API int tolua_\"..self.name..\"_open (lua_State* tolua_S)\")\n\
	output(pre..\"{\")\n\
	output(pre..\" tolua_open(tolua_S);\")\n\
	output(pre..\" tolua_reg_types(tolua_S);\")\n\
	output(pre..\" tolua_module(tolua_S,NULL,\",self:hasvar(),\");\")\n\
	output(pre..\" tolua_beginmodule(tolua_S,NULL);\")\n\
	local i=1\n\
	while self[i] do\n\
		self[i]:register(pre..\"  \")\n\
		i = i+1\n\
	end\n\
	output(pre..\" tolua_endmodule(tolua_S);\")\n\
	output(pre..\" return 1;\")\n\
	output(pre..\"}\")\n\
\n\
	output(\"\\n\\n\")\n\
	output(\"#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501\\n\");\n\
	output(pre..\"TOLUA_API int luaopen_\"..self.name..\" (lua_State* tolua_S) {\")\n\
	output(pre..\" return tolua_\"..self.name..\"_open(tolua_S);\")\n\
	output(pre..\"};\")\n\
	output(\"#endif\\n\\n\")\n\
\n\
	pop()\n\
end\n\
\n\
-- write header file\n\
function classPackage:header ()\n\
	output('/*\\n') output('** Lua binding: '..self.name..'\\n')\n\
	output('** Generated automatically by '..TOLUA_VERSION..' on '..date()..'.\\n')\n\
	output('*/\\n\\n')\n\
\n\
	if not flags.h then\n\
		output('/* Exported function */')\n\
		output('TOLUA_API int  tolua_'..self.name..'_open (lua_State* tolua_S);')\n\
		output('\\n')\n\
	end\n\
end\n\
\n\
-- Internal constructor\n\
function _Package (self)\n\
	setmetatable(self,classPackage)\n\
	return self\n\
end\n\
\n\
-- Parse C header file with tolua directives\n\
-- *** Thanks to Ariel Manzur for fixing bugs in nested directives ***\n\
function extract_code(fn,s)\n\
	local code = '\\n$#include \"'..fn..'\"\\n'\n\
	s= \"\\n\" .. s .. \"\\n\" -- add blank lines as sentinels\n\
	local _,e,c,t = strfind(s, \"\\n([^\\n]-)[Tt][Oo][Ll][Uu][Aa]_([^%s]*)[^\\n]*\\n\")\n\
	while e do\n\
		t = strlower(t)\n\
		if t == \"begin\" then\n\
			_,e,c = strfind(s,\"(.-)\\n[^\\n]*[Tt][Oo][Ll][Uu][Aa]_[Ee][Nn][Dd][^\\n]*\\n\",e)\n\
			if not e then\n\
				tolua_error(\"Unbalanced 'tolua_begin' directive in header file\")\n\
			end\n\
		end\n\
		code = code .. c .. \"\\n\"\n\
		_,e,c,t = strfind(s, \"\\n([^\\n]-)[Tt][Oo][Ll][Uu][Aa]_([^%s]*)[^\\n]*\\n\",e)\n\
	end\n\
	return code\n\
end\n\
\n\
-- Constructor\n\
-- Expects the package name, the file extension, and the file text.\n\
function Package (name,fn)\n\
	local ext = \"pkg\"\n\
\n\
	-- open input file, if any\n\
	local st,msg\n\
	if fn then\n\
		st, msg = readfrom(flags.f)\n\
		if not st then\n\
			error('#'..msg)\n\
		end\n\
		local _; _, _, ext = strfind(fn,\".*%.(.*)$\")\n\
	end\n\
	local code\n\
	if ext == 'pkg' then\n\
		code = prep(st)\n\
	else\n\
		code = \"\\n\" .. read('*a')\n\
		if ext == 'h' or ext == 'hpp' then\n\
			code = extract_code(fn,code)\n\
		end\n\
	end\n\
\n\
	-- close file\n\
	if fn then\n\
		readfrom()\n\
	end\n\
\n\
	-- deal with include directive\n\
	local nsubst\n\
	repeat\n\
		code,nsubst = gsub(code,'\\n%s*%$(.)file%s*\"(.-)\"([^\\n]*)\\n',\n\
		function (kind,fn,extra)\n\
			local _, _, ext = strfind(fn,\".*%.(.*)$\")\n\
			local fp,msg = openfile(fn,'r')\n\
			if not fp then\n\
				error('#'..msg..': '..fn)\n\
			end\n\
			if kind == 'p' then\n\
				local s = prep(fp)\n\
				closefile(fp)\n\
				return s\n\
			end\n\
			local s = read(fp,'*a')\n\
			closefile(fp)\n\
			if kind == 'c' or kind == 'h' then\n\
				return extract_code(fn,s)\n\
			elseif kind == 'l' then\n\
				return \"\\n$[--##\"..fn..\"\\n\" .. s .. \"\\n$]\\n\"\n\
			elseif kind == 'i' then\n\
				local t = {code=s}\n\
				extra = string.gsub(extra, \"^%s*,%s*\", \"\")\n\
				local pars = split_c_tokens(extra, \",\")\n\
				include_file_hook(t, fn, unpack(pars))\n\
				return \"\\n\\n\" .. t.code\n\
			else\n\
				error('#Invalid include directive (use $cfile, $pfile, $lfile or $ifile)')\n\
			end\n\
		end)\n\
	until nsubst==0\n\
\n\
	-- deal with renaming directive\n\
	repeat -- I don't know why this is necesary\n\
		code,nsubst = gsub(code,'\\n%s*%$renaming%s*(.-)%s*\\n', function (r) appendrenaming(r) return \"\\n\" end)\n\
	until nsubst == 0\n\
\n\
	local t = _Package(_Container{name=name, code=code})\n\
	push(t)\n\
	preprocess_hook(t)\n\
	t:preprocess()\n\
	preparse_hook(t)\n\
	t:parse(t.code)\n\
	pop()\n\
	return t\n\
end\n\
\n\
\n\
setmetatable(_extra_parameters, { __index = _G })\n\
\n\
function prep(file)\n\
\n\
	local chunk = {'local __ret = {\"\\\\n\"}\\n'}\n\
	for line in file:lines() do\n\
		if string.find(line, \"^##\") then\n\
			table.insert(chunk, string.sub(line, 3) .. \"\\n\")\n\
		else\n\
			local last = 1\n\
			for text, expr, index in string.gmatch(line, \"(.-)$(%b())()\") do \n\
				last = index\n\
				if text ~= \"\" then\n\
					table.insert(chunk, string.format('table.insert(__ret, %q )', text))\n\
				end\n\
				table.insert(chunk, string.format('table.insert(__ret, %s )', expr))\n\
			end\n\
			table.insert(chunk, string.format('table.insert(__ret, %q)\\n',\n\
			string.sub(line, last)..\"\\n\"))\n\
		end\n\
	end\n\
	table.insert(chunk, '\\nreturn table.concat(__ret)\\n')\n\
	-- local f,e = loadstring(table.concat(chunk))\n\
	local f,e = load(table.concat(chunk))\n\
	if e then\n\
		error(\"#\"..e)\n\
	end\n\
	-- setfenv(f, _extra_parameters)\n\
	local _ENV = _extra_parameters\n\
	return f()\n\
end \n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/package.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: module class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
\n\
-- Module class\n\
-- Represents module.\n\
-- The following fields are stored:\n\
--    {i} = list of objects in the module.\n\
classModule = {\n\
 classtype = 'module'\n\
}\n\
classModule.__index = classModule\n\
setmetatable(classModule,classContainer)\n\
\n\
-- register module\n\
function classModule:register (pre)\n\
 pre = pre or ''\n\
 push(self)\n\
 output(pre..'tolua_module(tolua_S,\"'..self.name..'\",',self:hasvar(),');')\n\
 output(pre..'tolua_beginmodule(tolua_S,\"'..self.name..'\");')\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:register(pre..'\t')\n\
  i = i+1\n\
 end\n\
 output(pre..'tolua_endmodule(tolua_S);')\n\
	pop()\n\
end\n\
\n\
-- Print method\n\
function classModule:print (ident,close)\n\
 print(ident..\"Module{\")\n\
 print(ident..\" name = '\"..self.name..\"';\")\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:print(ident..\" \",\",\")\n\
  i = i+1\n\
 end\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- Internal constructor\n\
function _Module (t)\n\
 setmetatable(t,classModule)\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects two string representing the module name and body.\n\
function Module (n,b)\n\
 local t = _Module(_Container{name=n})\n\
 push(t)\n\
 t:parse(strsub(b,2,strlen(b)-1)) -- eliminate braces\n\
 pop()\n\
 return t\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/module.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: namespace class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 2003\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Namespace class\n\
-- Represents a namesapce definition.\n\
-- Stores the following fields:\n\
--    name = class name\n\
--    {i}  = list of members\n\
classNamespace = {\n\
 classtype = 'namespace',\n\
 name = '',\n\
}\n\
classNamespace.__index = classNamespace\n\
setmetatable(classNamespace,classModule)\n\
\n\
-- Print method\n\
function classNamespace:print (ident,close)\n\
 print(ident..\"Namespace{\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:print(ident..\" \",\",\")\n\
  i = i+1\n\
 end\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- Internal constructor\n\
function _Namespace (t)\n\
 setmetatable(t,classNamespace)\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects the name and the body of the namespace.\n\
function Namespace (n,b)\n\
 local c = _Namespace(_Container{name=n})\n\
 push(c)\n\
 c:parse(strsub(b,2,strlen(b)-1)) -- eliminate braces\n\
 pop()\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/namespace.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: define class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: define.lua,v 1.2 1999/07/28 22:21:08 celes Exp $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Define class\n\
-- Represents a numeric const definition\n\
-- The following filds are stored:\n\
--   name = constant name\n\
classDefine = {\n\
 name = '',\n\
}\n\
classDefine.__index = classDefine\n\
setmetatable(classDefine,classFeature)\n\
\n\
-- register define\n\
function classDefine:register (pre)\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
\n\
 pre = pre or ''\n\
 output(pre..'tolua_constant(tolua_S,\"'..self.lname..'\",'..self.name..');')\n\
end\n\
\n\
-- Print method\n\
function classDefine:print (ident,close)\n\
 print(ident..\"Define{\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 print(ident..\" lname = '\"..self.lname..\"',\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
\n\
-- Internal constructor\n\
function _Define (t)\n\
 setmetatable(t,classDefine)\n\
 t:buildnames()\n\
\n\
 if t.name == '' then\n\
  error(\"#invalid define\")\n\
 end\n\
\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects a string representing the constant name\n\
function Define (n)\n\
 return _Define{\n\
  name = n\n\
 }\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/define.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: enumerate class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: enumerate.lua,v 1.3 2000/01/24 20:41:15 celes Exp $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Enumerate class\n\
-- Represents enumeration\n\
-- The following fields are stored:\n\
--    {i} = list of constant names\n\
classEnumerate = {\n\
}\n\
classEnumerate.__index = classEnumerate\n\
setmetatable(classEnumerate,classFeature)\n\
\n\
-- register enumeration\n\
function classEnumerate:register (pre)\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
 pre = pre or ''\n\
 local nspace = getnamespace(classContainer.curr)\n\
 local i=1\n\
 while self[i] do\n\
 	if self.lnames[i] and self.lnames[i] ~= \"\" then\n\
	\n\
		output(pre..'tolua_constant(tolua_S,\"'..self.lnames[i]..'\",'..nspace..self[i]..');')\n\
	end\n\
  i = i+1\n\
 end\n\
end\n\
\n\
-- Print method\n\
function classEnumerate:print (ident,close)\n\
 print(ident..\"Enumerate{\")\n\
 print(ident..\" name = \"..self.name)\n\
 local i=1\n\
 while self[i] do\n\
  print(ident..\" '\"..self[i]..\"'(\"..self.lnames[i]..\"),\")\n\
  i = i+1\n\
 end\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- Internal constructor\n\
function _Enumerate (t,varname)\n\
 setmetatable(t,classEnumerate)\n\
 append(t)\n\
 appendenum(t)\n\
	 if varname and varname ~= \"\" then\n\
		if t.name ~= \"\" then\n\
			Variable(t.name..\" \"..varname)\n\
		else\n\
			local ns = getcurrnamespace()\n\
			warning(\"Variable \"..ns..varname..\" of type <anonymous enum> is declared as read-only\")\n\
			Variable(\"tolua_readonly int \"..varname)\n\
		end\n\
	end\n\
	 local parent = classContainer.curr\n\
	 if parent then\n\
		t.access = parent.curr_member_access\n\
		t.global_access = t:check_public_access()\n\
	 end\n\
return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects a string representing the enumerate body\n\
function Enumerate (n,b,varname)\n\
	b = string.gsub(b, \",[%s\\n]*}\", \"\\n}\") -- eliminate last ','\n\
 local t = split(strsub(b,2,-2),',') -- eliminate braces\n\
 local i = 1\n\
 local e = {n=0}\n\
 while t[i] do\n\
  local tt = split(t[i],'=')  -- discard initial value\n\
  e.n = e.n + 1\n\
  e[e.n] = tt[1]\n\
  i = i+1\n\
 end\n\
 -- set lua names\n\
 i  = 1\n\
 e.lnames = {}\n\
 local ns = getcurrnamespace()\n\
 while e[i] do\n\
  local t = split(e[i],'@')\n\
  e[i] = t[1]\n\
		if not t[2] then\n\
		 t[2] = applyrenaming(t[1])\n\
		end\n\
  e.lnames[i] = t[2] or t[1]\n\
  _global_enums[ ns..e[i] ] = (ns..e[i])\n\
  i = i+1\n\
 end\n\
	e.name = n\n\
	if n ~= \"\" then\n\
		Typedef(\"int \"..n)\n\
	end\n\
 return _Enumerate(e, varname)\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/enumerate.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: declaration class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Declaration class\n\
-- Represents variable, function, or argument declaration.\n\
-- Stores the following fields:\n\
--  mod  = type modifiers\n\
--  type = type\n\
--  ptr  = \"*\" or \"&\", if representing a pointer or a reference\n\
--  name = name\n\
--  dim  = dimension, if a vector\n\
--  def  = default value, if any (only for arguments)\n\
--  ret  = \"*\" or \"&\", if value is to be returned (only for arguments)\n\
classDeclaration = {\n\
 mod = '',\n\
 type = '',\n\
 ptr = '',\n\
 name = '',\n\
 dim = '',\n\
 ret = '',\n\
 def = ''\n\
}\n\
classDeclaration.__index = classDeclaration\n\
setmetatable(classDeclaration,classFeature)\n\
\n\
-- Create an unique variable name\n\
function create_varname ()\n\
 if not _varnumber then _varnumber = 0 end\n\
 _varnumber = _varnumber + 1\n\
 return \"tolua_var_\".._varnumber\n\
end\n\
\n\
-- Check declaration name\n\
-- It also identifies default values\n\
function classDeclaration:checkname ()\n\
\n\
 if strsub(self.name,1,1) == '[' and not findtype(self.type) then\n\
  self.name = self.type..self.name\n\
  local m = split(self.mod,'%s%s*')\n\
  self.type = m[m.n]\n\
  self.mod = concat(m,1,m.n-1)\n\
 end\n\
\n\
 local t = split(self.name,'=')\n\
 if t.n==2 then\n\
  self.name = t[1]\n\
  self.def = find_enum_var(t[t.n])\n\
 end\n\
\n\
 local b,e,d = strfind(self.name,\"%[(.-)%]\")\n\
 if b then\n\
  self.name = strsub(self.name,1,b-1)\n\
  self.dim = find_enum_var(d)\n\
 end\n\
\n\
\n\
 if self.type ~= '' and self.type ~= 'void' and self.name == '' then\n\
  self.name = create_varname()\n\
 elseif self.kind=='var' then\n\
  if self.type=='' and self.name~='' then\n\
   self.type = self.type..self.name\n\
   self.name = create_varname()\n\
  elseif findtype(self.name) then\n\
   if self.type=='' then self.type = self.name\n\
   else self.type = self.type..' '..self.name end\n\
   self.name = create_varname()\n\
  end\n\
 end\n\
\n\
 -- adjust type of string\n\
 if self.type == 'char' and self.dim ~= '' then\n\
	 self.type = 'char*'\n\
 end\n\
\n\
	if self.kind and self.kind == 'var' then\n\
		self.name = string.gsub(self.name, \":.*$\", \"\") -- ???\n\
	end\n\
end\n\
\n\
-- Check declaration type\n\
-- Substitutes typedef's.\n\
function classDeclaration:checktype ()\n\
\n\
 -- check if there is a pointer to basic type\n\
 local basic = isbasic(self.type)\n\
 if self.kind == 'func' and basic=='number' and string.find(self.ptr, \"%*\") then\n\
 	self.type = '_userdata'\n\
 	self.ptr = \"\"\n\
 end\n\
 if basic and self.ptr~='' then\n\
  self.ret = self.ptr\n\
  self.ptr = nil\n\
  if isbasic(self.type) == 'number' then\n\
  	self.return_userdata = true\n\
  end\n\
 end\n\
\n\
 -- check if there is array to be returned\n\
 if self.dim~='' and self.ret~='' then\n\
   error('#invalid parameter: cannot return an array of values')\n\
 end\n\
 -- restore 'void*' and 'string*'\n\
 if self.type == '_userdata' then self.type = 'void*'\n\
 elseif self.type == '_cstring' then self.type = 'char*'\n\
 elseif self.type == '_lstate' then self.type = 'lua_State*'\n\
 end\n\
\n\
 -- resolve types inside the templates\n\
 if self.type then\n\
	 self.type = resolve_template_types(self.type)\n\
 end\n\
\n\
--\n\
-- -- if returning value, automatically set default value\n\
-- if self.ret ~= '' and self.def == '' then\n\
--  self.def = '0'\n\
-- end\n\
--\n\
\n\
end\n\
\n\
function resolve_template_types(type)\n\
\n\
	if isbasic(type) then\n\
		return type\n\
	end\n\
	local b,_,m = string.find(type, \"(%b<>)\")\n\
	if b then\n\
\n\
		m = split_c_tokens(string.sub(m, 2, -2), \",\")\n\
		for i=1, #m do\n\
			m[i] = string.gsub(m[i],\"%s*([%*&])\", \"%1\")\n\
			if not isbasic(m[i]) then\n\
				if not isenum(m[i]) then _, m[i] = applytypedef(\"\", m[i]) end\n\
				m[i] = findtype(m[i]) or m[i]\n\
				m[i] = resolve_template_types(m[i])\n\
			end\n\
		end\n\
\n\
		local b,i\n\
		type,b,i = break_template(type)\n\
--print(\"concat is \",concat(m, 1, m.n))\n\
		local template_part = \"<\"..concat(m, 1, m.n, \",\")..\">\"\n\
		type = rebuild_template(type, b, template_part)\n\
		type = string.gsub(type, \">>\", \"> >\")\n\
	end\n\
	return type\n\
end\n\
\n\
function break_template(s)\n\
	local b,e,timpl = string.find(s, \"(%b<>)\")\n\
	if timpl then\n\
		s = string.gsub(s, \"%b<>\", \"\")\n\
		return s, b, timpl\n\
	else\n\
		return s, 0, nil\n\
	end\n\
end\n\
\n\
function rebuild_template(s, b, timpl)\n\
\n\
	if b == 0 then\n\
		return s\n\
	end\n\
\n\
	return string.sub(s, 1, b-1)..timpl..string.sub(s, b, -1)\n\
end\n\
\n\
-- Print method\n\
function classDeclaration:print (ident,close)\n\
 print(ident..\"Declaration{\")\n\
 print(ident..\" mod  = '\"..self.mod..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\" ptr  = '\"..self.ptr..\"',\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 print(ident..\" dim  = '\"..self.dim..\"',\")\n\
 print(ident..\" def  = '\"..self.def..\"',\")\n\
 print(ident..\" ret  = '\"..self.ret..\"',\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- check if array of values are returned to Lua\n\
function classDeclaration:requirecollection (t)\n\
 if self.mod ~= 'const' and\n\
	    self.dim and self.dim ~= '' and\n\
				 not isbasic(self.type) and\n\
				 self.ptr == '' and self:check_public_access() then\n\
		local type = gsub(self.type,\"%s*const%s+\",\"\")\n\
		t[type] = \"tolua_collect_\" .. clean_template(type)\n\
		return true\n\
	end\n\
	return false\n\
end\n\
\n\
-- declare tag\n\
function classDeclaration:decltype ()\n\
\n\
	self.type = typevar(self.type)\n\
	if strfind(self.mod,'const') then\n\
		self.type = 'const '..self.type\n\
		self.mod = gsub(self.mod,'const%s*','')\n\
	end\n\
end\n\
\n\
\n\
-- output type checking\n\
function classDeclaration:outchecktype (narg)\n\
 local def\n\
 local t = isbasic(self.type)\n\
 if self.def~='' then\n\
  def = 1\n\
 else\n\
  def = 0\n\
 end\n\
 if self.dim ~= '' then\n\
	--if t=='string' then\n\
	--	return 'tolua_isstringarray(tolua_S,'..narg..','..def..',&tolua_err)'\n\
	--else\n\
	return '!tolua_istable(tolua_S,'..narg..',0,&tolua_err)'\n\
 	--end\n\
 elseif t then\n\
	return '!tolua_is'..t..'(tolua_S,'..narg..','..def..',&tolua_err)'\n\
 else\n\
  local is_func = get_is_function(self.type)\n\
  if self.ptr == '&' or self.ptr == '' then\n\
  	return '(tolua_isvaluenil(tolua_S,'..narg..',&tolua_err) || !'..is_func..'(tolua_S,'..narg..',\"'..self.type..'\",'..def..',&tolua_err))'\n\
  else\n\
	return '!'..is_func..'(tolua_S,'..narg..',\"'..self.type..'\",'..def..',&tolua_err)'\n\
  end\n\
 end\n\
end\n\
\n\
function classDeclaration:builddeclaration (narg, cplusplus)\n\
 local array = self.dim ~= '' and tonumber(self.dim)==nil\n\
	local line = \"\"\n\
 local ptr = ''\n\
 local mod\n\
 local type = self.type\n\
 local nctype = gsub(self.type,'const%s+','')\n\
 if self.dim ~= '' then\n\
	 type = gsub(self.type,'const%s+','')  -- eliminates const modifier for arrays\n\
 end\n\
 if self.ptr~='' and not isbasic(type) then ptr = '*' end\n\
 line = concatparam(line,\"\t\",self.mod,type,ptr)\n\
 if array then\n\
  line = concatparam(line,'*')\n\
 end\n\
 line = concatparam(line,self.name)\n\
 if self.dim ~= '' then\n\
  if tonumber(self.dim)~=nil then\n\
   line = concatparam(line,'[',self.dim,'];')\n\
  else\n\
	if cplusplus then\n\
		line = concatparam(line,' = Mtolua_new_dim(',type,ptr,', '..self.dim..');')\n\
	else\n\
		line = concatparam(line,' = (',type,ptr,'*)',\n\
		'malloc((',self.dim,')*sizeof(',type,ptr,'));')\n\
	end\n\
  end\n\
 else\n\
  local t = isbasic(type)\n\
  line = concatparam(line,' = ')\n\
  if t == 'state' then\n\
  	line = concatparam(line, 'tolua_S;')\n\
  else\n\
  	--print(\"t is \"..tostring(t)..\", ptr is \"..tostring(self.ptr))\n\
  	if t == 'number' and string.find(self.ptr, \"%*\") then\n\
  		t = 'userdata'\n\
  	end\n\
	if not t and ptr=='' then line = concatparam(line,'*') end\n\
	line = concatparam(line,'((',self.mod,type)\n\
	if not t then\n\
		line = concatparam(line,'*')\n\
	end\n\
	line = concatparam(line,') ')\n\
	if isenum(nctype) then\n\
		line = concatparam(line,'(int) ')\n\
	end\n\
	local def = 0\n\
	if self.def ~= '' then\n\
		def = self.def\n\
		if (ptr == '' or self.ptr == '&') and not t then\n\
			def = \"(void*)&(const \"..type..\")\"..def\n\
		end\n\
	end\n\
	if t then\n\
		line = concatparam(line,' tolua_to'..t,'(tolua_S,',narg,',',def,'));')\n\
	else\n\
		local to_func = get_to_function(type)\n\
		line = concatparam(line,to_func..'(tolua_S,',narg,',',def,'));')\n\
	end\n\
  end\n\
 end\n\
	return line\n\
end\n\
\n\
-- Declare variable\n\
function classDeclaration:declare (narg)\n\
 if self.dim ~= '' and tonumber(self.dim)==nil then\n\
	 output('#ifdef __cplusplus\\n')\n\
		output(self:builddeclaration(narg,true))\n\
		output('#else\\n')\n\
		output(self:builddeclaration(narg,false))\n\
	 output('#endif\\n')\n\
	else\n\
		output(self:builddeclaration(narg,false))\n\
	end\n\
end\n\
\n\
-- Get parameter value\n\
function classDeclaration:getarray (narg)\n\
 if self.dim ~= '' then\n\
	 local type = gsub(self.type,'const ','')\n\
  output('\\t{')\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
  local def; if self.def~='' then def=1 else def=0 end\n\
		local t = isbasic(type)\n\
		if (t) then\n\
		   output('\tif (!tolua_is'..t..'array(tolua_S,',narg,',',self.dim,',',def,',&tolua_err))')\n\
		else\n\
		   output('\tif (!tolua_isusertypearray(tolua_S,',narg,',\"',type,'\",',self.dim,',',def,',&tolua_err))')\n\
		end\n\
  output('\\t\\tgoto tolua_lerror;')\n\
  output('\\telse\\n')\n\
	 output('#endif\\n')\n\
  output('\\t{')\n\
  output('\\tint i;')\n\
  output('\\tfor(i=0; i<'..self.dim..';i++)')\n\
  local t = isbasic(type)\n\
  local ptr = ''\n\
  if self.ptr~='' then ptr = '*' end\n\
  output('\\t',self.name..'[i] = ')\n\
  if not t and ptr=='' then output('*') end\n\
  output('((',type)\n\
  if not t then\n\
   output('*')\n\
  end\n\
  output(') ')\n\
  local def = 0\n\
  if self.def ~= '' then def = self.def end\n\
  if t then\n\
   output('tolua_tofield'..t..'(tolua_S,',narg,',i+1,',def,'));')\n\
  else\n\
   output('tolua_tofieldusertype(tolua_S,',narg,',i+1,',def,'));')\n\
  end\n\
  output('\\t\\t}')\n\
  output('\\t}')\n\
 end\n\
end\n\
\n\
-- Get parameter value\n\
function classDeclaration:setarray (narg)\n\
 if not strfind(self.type,'const%s+') and self.dim ~= '' then\n\
	 local type = gsub(self.type,'const ','')\n\
  output('  {')\n\
  output('   int i;')\n\
  output('   for(i=0; i<'..self.dim..';i++)')\n\
  local t,ct = isbasic(type)\n\
  if t then\n\
   output('    tolua_pushfield'..t..'(tolua_S,',narg,',i+1,(',ct,')',self.name,'[i]);')\n\
  else\n\
   if self.ptr == '' then\n\
     output('   {')\n\
     output('#ifdef __cplusplus\\n')\n\
     output('    void* tolua_obj = Mtolua_new((',type,')(',self.name,'[i]));')\n\
     output('    tolua_pushfieldusertype_and_takeownership(tolua_S,',narg,',i+1,tolua_obj,\"',type,'\");')\n\
     output('#else\\n')\n\
     output('    void* tolua_obj = tolua_copy(tolua_S,(void*)&',self.name,'[i],sizeof(',type,'));')\n\
     output('    tolua_pushfieldusertype(tolua_S,',narg,',i+1,tolua_obj,\"',type,'\");')\n\
     output('#endif\\n')\n\
     output('   }')\n\
   else\n\
    output('   tolua_pushfieldusertype(tolua_S,',narg,',i+1,(void*)',self.name,'[i],\"',type,'\");')\n\
   end\n\
  end\n\
  output('  }')\n\
 end\n\
end\n\
\n\
-- Free dynamically allocated array\n\
function classDeclaration:freearray ()\n\
 if self.dim ~= '' and tonumber(self.dim)==nil then\n\
	 output('#ifdef __cplusplus\\n')\n\
		output('  Mtolua_delete_dim(',self.name,');')\n\
	 output('#else\\n')\n\
  output('  free(',self.name,');')\n\
	 output('#endif\\n')\n\
 end\n\
end\n\
\n\
-- Pass parameter\n\
function classDeclaration:passpar ()\n\
 if self.ptr=='&' and not isbasic(self.type) then\n\
  output('*'..self.name)\n\
 elseif self.ret=='*' then\n\
  output('&'..self.name)\n\
 else\n\
  output(self.name)\n\
 end\n\
end\n\
\n\
-- Return parameter value\n\
function classDeclaration:retvalue ()\n\
 if self.ret ~= '' then\n\
  local t,ct = isbasic(self.type)\n\
  if t and t~='' then\n\
   output('\\t\\ttolua_push'..t..'(tolua_S,(',ct,')'..self.name..');')\n\
  else\n\
   local push_func = get_push_function(self.type)\n\
   output('\\t\\t',push_func,'(tolua_S,(void*)'..self.name..',\"',self.type,'\");')\n\
  end\n\
  return 1\n\
 end\n\
 return 0\n\
end\n\
\n\
-- Internal constructor\n\
function _Declaration (t)\n\
\n\
 setmetatable(t,classDeclaration)\n\
 t:buildnames()\n\
 t:checkname()\n\
 t:checktype()\n\
 local ft = findtype(t.type) or t.type\n\
 if not isenum(ft) then\n\
	t.mod, t.type = applytypedef(t.mod, ft)\n\
 end\n\
\n\
 if t.kind==\"var\" and (string.find(t.mod, \"tolua_property%s\") or string.find(t.mod, \"tolua_property$\")) then\n\
 	t.mod = string.gsub(t.mod, \"tolua_property\", \"tolua_property__\"..get_property_type())\n\
 end\n\
\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects the string declaration.\n\
-- The kind of declaration can be \"var\" or \"func\".\n\
function Declaration (s,kind,is_parameter)\n\
\n\
 -- eliminate spaces if default value is provided\n\
 s = gsub(s,\"%s*=%s*\",\"=\")\n\
 s = gsub(s, \"%s*<\", \"<\")\n\
\n\
 local defb,tmpdef\n\
 defb,_,tmpdef = string.find(s, \"(=.*)$\")\n\
 if defb then\n\
 	s = string.gsub(s, \"=.*$\", \"\")\n\
 else\n\
 	tmpdef = ''\n\
 end\n\
 if kind == \"var\" then\n\
  -- check the form: void\n\
  if s == '' or s == 'void' then\n\
   return _Declaration{type = 'void', kind = kind, is_parameter = is_parameter}\n\
  end\n\
 end\n\
\n\
 -- check the form: mod type*& name\n\
 local t = split_c_tokens(s,'%*%s*&')\n\
 if t.n == 2 then\n\
  if kind == 'func' then\n\
   error(\"#invalid function return type: \"..s)\n\
  end\n\
  --local m = split(t[1],'%s%s*')\n\
  local m = split_c_tokens(t[1],'%s+')\n\
  return _Declaration{\n\
   name = t[2]..tmpdef,\n\
   ptr = '*',\n\
   ret = '&',\n\
   --type = rebuild_template(m[m.n], tb, timpl),\n\
   type = m[m.n],\n\
   mod = concat(m,1,m.n-1),\n\
   is_parameter = is_parameter,\n\
   kind = kind\n\
  }\n\
 end\n\
\n\
 -- check the form: mod type** name\n\
 t = split_c_tokens(s,'%*%s*%*')\n\
 if t.n == 2 then\n\
  if kind == 'func' then\n\
   error(\"#invalid function return type: \"..s)\n\
  end\n\
  --local m = split(t[1],'%s%s*')\n\
  local m = split_c_tokens(t[1],'%s+')\n\
  return _Declaration{\n\
   name = t[2]..tmpdef,\n\
   ptr = '*',\n\
   ret = '*',\n\
   --type = rebuild_template(m[m.n], tb, timpl),\n\
   type = m[m.n],\n\
   mod = concat(m,1,m.n-1),\n\
   is_parameter = is_parameter,\n\
   kind = kind\n\
  }\n\
 end\n\
\n\
 -- check the form: mod type& name\n\
 t = split_c_tokens(s,'&')\n\
 if t.n == 2 then\n\
  --local m = split(t[1],'%s%s*')\n\
  local m = split_c_tokens(t[1],'%s+')\n\
  return _Declaration{\n\
   name = t[2]..tmpdef,\n\
   ptr = '&',\n\
   --type = rebuild_template(m[m.n], tb, timpl),\n\
   type = m[m.n],\n\
   mod = concat(m,1,m.n-1),\n\
   is_parameter = is_parameter,\n\
   kind = kind\n\
  }\n\
 end\n\
\n\
 -- check the form: mod type* name\n\
 local s1 = gsub(s,\"(%b\\\\[\\\\])\",function (n) return gsub(n,'%*','\\1') end)\n\
 t = split_c_tokens(s1,'%*')\n\
 if t.n == 2 then\n\
  t[2] = gsub(t[2],'\1','%*') -- restore * in dimension expression\n\
  --local m = split(t[1],'%s%s*')\n\
  local m = split_c_tokens(t[1],'%s+')\n\
  return _Declaration{\n\
   name = t[2]..tmpdef,\n\
   ptr = '*',\n\
   type = m[m.n],\n\
   --type = rebuild_template(m[m.n], tb, timpl),\n\
   mod = concat(m,1,m.n-1)   ,\n\
   is_parameter = is_parameter,\n\
   kind = kind\n\
  }\n\
 end\n\
\n\
 if kind == 'var' then\n\
  -- check the form: mod type name\n\
  --t = split(s,'%s%s*')\n\
  t = split_c_tokens(s,'%s+')\n\
  local v\n\
  if findtype(t[t.n]) then v = create_varname() else v = t[t.n]; t.n = t.n-1 end\n\
  return _Declaration{\n\
   name = v..tmpdef,\n\
   --type = rebuild_template(t[t.n], tb, timpl),\n\
   type = t[t.n],\n\
   mod = concat(t,1,t.n-1),\n\
   is_parameter = is_parameter,\n\
   kind = kind\n\
  }\n\
\n\
 else -- kind == \"func\"\n\
\n\
  -- check the form: mod type name\n\
  --t = split(s,'%s%s*')\n\
  t = split_c_tokens(s,'%s+')\n\
  local v = t[t.n]  -- last word is the function name\n\
  local tp,md\n\
  if t.n>1 then\n\
   tp = t[t.n-1]\n\
   md = concat(t,1,t.n-2)\n\
  end\n\
  --if tp then tp = rebuild_template(tp, tb, timpl) end\n\
  return _Declaration{\n\
   name = v,\n\
   type = tp,\n\
   mod = md,\n\
   is_parameter = is_parameter,\n\
   kind = kind\n\
  }\n\
 end\n\
\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/declaration.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: variable class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Variable class\n\
-- Represents a extern variable or a public member of a class.\n\
-- Stores all fields present in a declaration.\n\
classVariable = {\n\
 _get = {},   -- mapped get functions\n\
 _set = {},   -- mapped set functions\n\
}\n\
classVariable.__index = classVariable\n\
setmetatable(classVariable,classDeclaration)\n\
\n\
-- Print method\n\
function classVariable:print (ident,close)\n\
 print(ident..\"Variable{\")\n\
 print(ident..\" mod  = '\"..self.mod..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\" ptr  = '\"..self.ptr..\"',\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 if self.dim then print(ident..\" dim = '\"..self.dim..\"',\") end\n\
 print(ident..\" def  = '\"..self.def..\"',\")\n\
 print(ident..\" ret  = '\"..self.ret..\"',\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- Generates C function name\n\
function classVariable:cfuncname (prefix)\n\
 local parent = \"\"\n\
 local unsigned = \"\"\n\
 local ptr = \"\"\n\
\n\
 local p = self:inmodule() or self:innamespace() or self:inclass()\n\
\n\
 if p then\n\
 	if self.parent.classtype == 'class' then\n\
		parent = \"_\" .. self.parent.type\n\
	else\n\
	  parent = \"_\" .. p\n\
	end\n\
 end\n\
\n\
 if strfind(self.mod,\"(unsigned)\") then\n\
  unsigned = \"_unsigned\"\n\
 end\n\
\n\
 if self.ptr == \"*\" then ptr = \"_ptr\"\n\
 elseif self.ptr == \"&\" then ptr = \"_ref\"\n\
 end\n\
\n\
 local name =  prefix .. parent .. unsigned .. \"_\" .. gsub(self.lname or self.name,\".*::\",\"\") .. ptr\n\
\n\
	name = clean_template(name)\n\
 return name\n\
\n\
end\n\
\n\
-- check if it is a variable\n\
function classVariable:isvariable ()\n\
 return true\n\
end\n\
\n\
-- get variable value\n\
function classVariable:getvalue (class,static, prop_get)\n\
\n\
	local name\n\
	if prop_get then\n\
\n\
		name = prop_get..\"()\"\n\
	else\n\
		name = self.name\n\
	end\n\
\n\
	if class and static then\n\
	 return self.parent.type..'::'..name\n\
	elseif class then\n\
	 return 'self->'..name\n\
	else\n\
	 return name\n\
	end\n\
end\n\
\n\
-- get variable pointer value\n\
function classVariable:getpointervalue (class,static)\n\
 if class and static then\n\
  return class..'::p'\n\
 elseif class then\n\
  return 'self->p'\n\
 else\n\
  return 'p'\n\
 end\n\
end\n\
\n\
-- Write binding functions\n\
function classVariable:supcode ()\n\
\n\
 local class = self:inclass()\n\
\n\
	local prop_get,prop_set\n\
	if string.find(self.mod, 'tolua_property') then\n\
\n\
		local _,_,type = string.find(self.mod, \"tolua_property__([^%s]*)\")\n\
		type = type or \"default\"\n\
		prop_get,prop_set = get_property_methods(type, self.name)\n\
		self.mod = string.gsub(self.mod, \"tolua_property[^%s]*\", \"\")\n\
	end\n\
\n\
 -- get function ------------------------------------------------\n\
 if class then\n\
  output(\"/* get function:\",self.name,\" of class \",class,\" */\")\n\
 else\n\
  output(\"/* get function:\",self.name,\" */\")\n\
 end\n\
 self.cgetname = self:cfuncname(\"tolua_get\")\n\
 output(\"#ifndef TOLUA_DISABLE_\"..self.cgetname)\n\
 output(\"\\nstatic int\",self.cgetname,\"(lua_State* tolua_S)\")\n\
 output(\"{\")\n\
\n\
 -- declare self, if the case\n\
 local _,_,static = strfind(self.mod,'^%s*(static)')\n\
 if class and static==nil then\n\
  output(' ',self.parent.type,'*','self = ')\n\
  output('(',self.parent.type,'*) ')\n\
  local to_func = get_to_function(self.parent.type)\n\
  output(to_func,'(tolua_S,1,0);')\n\
 elseif static then\n\
  _,_,self.mod = strfind(self.mod,'^%s*static%s%s*(.*)')\n\
 end\n\
\n\
\n\
 -- check self value\n\
 if class and static==nil then\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
	 output('\\tif (!self)')\n\
	output('\\t\\ttolua_error(tolua_S,\"'..output_error_hook(\"invalid \'self\' in accessing variable \'%s\'\", self.name)..'\",NULL);');\n\
		output('#endif\\n')\n\
 end\n\
\n\
 -- return value\n\
 if string.find(self.mod, 'tolua_inherits') then\n\
	local push_func = get_push_function(self.type)\n\
 	output('#ifdef __cplusplus\\n')\n\
	output('\\t',push_func,'(tolua_S,(void*)static_cast<'..self.type..'*>(self), \"',self.type,'\");')\n\
	output('#else\\n')\n\
	output('\\t',push_func,'(tolua_S,(void*)(('..self.type..'*)self), \"',self.type,'\");')\n\
	output('#endif\\n')\n\
 else\n\
	local t,ct = isbasic(self.type)\n\
	if t then\n\
		output('\\ttolua_push'..t..'(tolua_S,(',ct,')'..self:getvalue(class,static,prop_get)..');')\n\
	else\n\
		local push_func = get_push_function(self.type)\n\
		t = self.type\n\
		if self.ptr == '&' or self.ptr == '' then\n\
			output('\\t',push_func,'(tolua_S,(void*)&'..self:getvalue(class,static,prop_get)..',\"',t,'\");')\n\
		else\n\
			output('\\t',push_func,'(tolua_S,(void*)'..self:getvalue(class,static,prop_get)..',\"',t,'\");')\n\
		end\n\
	end\n\
 end\n\
 output('\\treturn 1;')\n\
 output('}')\n\
 output('#endif //#ifndef TOLUA_DISABLE\\n')\n\
 output('\\n')\n\
\n\
 -- set function ------------------------------------------------\n\
 if not (strfind(self.type,'const%s+') or string.find(self.mod, 'tolua_readonly') or string.find(self.mod, 'tolua_inherits'))  then\n\
  if class then\n\
   output(\"/* set function:\",self.name,\" of class \",class,\" */\")\n\
  else\n\
   output(\"/* set function:\",self.name,\" */\")\n\
  end\n\
  self.csetname = self:cfuncname(\"tolua_set\")\n\
  output(\"#ifndef TOLUA_DISABLE_\"..self.csetname)\n\
  output(\"\\nstatic int\",self.csetname,\"(lua_State* tolua_S)\")\n\
  output(\"{\")\n\
\n\
  -- declare self, if the case\n\
  if class and static==nil then\n\
   output(' ',self.parent.type,'*','self = ')\n\
   output('(',self.parent.type,'*) ')\n\
   local to_func = get_to_function(self.parent.type)\n\
   output(to_func,'(tolua_S,1,0);')\n\
   -- check self value\n\
		end\n\
  -- check types\n\
		output('#ifndef TOLUA_RELEASE\\n')\n\
		output('\\ttolua_Error tolua_err;')\n\
  if class and static==nil then\n\
  output('\\tif (!self)')\n\
  output('\\t\\ttolua_error(tolua_S,\"'..output_error_hook(\"invalid \'self\' in accessing variable \'%s\'\", self.name)..'\",NULL);');\n\
  elseif static then\n\
   _,_,self.mod = strfind(self.mod,'^%s*static%s%s*(.*)')\n\
  end\n\
\n\
  -- check variable type\n\
  output('\\tif ('..self:outchecktype(2)..')')\n\
  output('\\t\\ttolua_error(tolua_S,\"#vinvalid type in variable assignment.\",&tolua_err);')\n\
		output('#endif\\n')\n\
\n\
  -- assign value\n\
		local def = 0\n\
		if self.def ~= '' then def = self.def end\n\
		if self.type == 'char*' and self.dim ~= '' then -- is string\n\
			output(' strncpy((char*)')\n\
			if class and static then\n\
				output(self.parent.type..'::'..self.name)\n\
			elseif class then\n\
				output('self->'..self.name)\n\
			else\n\
				output(self.name)\n\
			end\n\
			output(',(const char*)tolua_tostring(tolua_S,2,',def,'),',self.dim,'-1);')\n\
		else\n\
			local ptr = ''\n\
			if self.ptr~='' then ptr = '*' end\n\
			output(' ')\n\
			local name = prop_set or self.name\n\
			if class and static then\n\
				output(self.parent.type..'::'..name)\n\
			elseif class then\n\
				output('self->'..name)\n\
			else\n\
				output(name)\n\
			end\n\
			local t = isbasic(self.type)\n\
			if prop_set then\n\
				output('(')\n\
			else\n\
				output(' = ')\n\
			end\n\
			if not t and ptr=='' then output('*') end\n\
			output('((',self.mod,self.type)\n\
			if not t then\n\
				output('*')\n\
			end\n\
			output(') ')\n\
			if t then\n\
				if isenum(self.type) then\n\
					output('(int)')\n\
				end\n\
				if prop_set then\n\
					output(' tolua_to'..t,'(tolua_S,2,',def,')));')\n\
				else\n\
					output(' tolua_to'..t,'(tolua_S,2,',def,'));')\n\
				end\n\
			else\n\
				local to_func = get_to_function(self.type)\n\
				if prop_set then\n\
					output(to_func,'(tolua_S,2,',def,')));')\n\
				else\n\
					output(to_func,'(tolua_S,2,',def,'));')\n\
				end\n\
			end\n\
		end\n\
  output(' return 0;')\n\
  output('}')\n\
  output('#endif //#ifndef TOLUA_DISABLE\\n')\n\
  output('\\n')\n\
 end\n\
\n\
end\n\
\n\
function classVariable:register (pre)\n\
\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
 pre = pre or ''\n\
 local parent = self:inmodule() or self:innamespace() or self:inclass()\n\
 if not parent then\n\
  if classVariable._warning==nil then\n\
   warning(\"Mapping variable to global may degrade performance\")\n\
   classVariable._warning = 1\n\
  end\n\
 end\n\
 if self.csetname then\n\
  output(pre..'tolua_variable(tolua_S,\"'..self.lname..'\",'..self.cgetname..','..self.csetname..');')\n\
 else\n\
  output(pre..'tolua_variable(tolua_S,\"'..self.lname..'\",'..self.cgetname..',NULL);')\n\
 end\n\
end\n\
\n\
-- Internal constructor\n\
function _Variable (t)\n\
 setmetatable(t,classVariable)\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects a string representing the variable declaration.\n\
function Variable (s)\n\
 return _Variable (Declaration(s,'var'))\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/variable.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: array class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1999\n\
-- $Id: array.lua,v 1.1 2000/11/06 22:03:57 celes Exp $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Array class\n\
-- Represents a extern array variable or a public member of a class.\n\
-- Stores all fields present in a declaration.\n\
classArray = {\n\
}\n\
classArray.__index = classArray\n\
setmetatable(classArray,classDeclaration)\n\
\n\
-- Print method\n\
function classArray:print (ident,close)\n\
 print(ident..\"Array{\")\n\
 print(ident..\" mod  = '\"..self.mod..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\" ptr  = '\"..self.ptr..\"',\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 print(ident..\" def  = '\"..self.def..\"',\")\n\
 print(ident..\" dim  = '\"..self.dim..\"',\")\n\
 print(ident..\" ret  = '\"..self.ret..\"',\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- check if it is a variable\n\
function classArray:isvariable ()\n\
 return true\n\
end\n\
\n\
\n\
-- get variable value\n\
function classArray:getvalue (class,static)\n\
 if class and static then\n\
  return class..'::'..self.name..'[tolua_index]'\n\
 elseif class then\n\
  return 'self->'..self.name..'[tolua_index]'\n\
 else\n\
  return self.name..'[tolua_index]'\n\
 end\n\
end\n\
\n\
-- Write binding functions\n\
function classArray:supcode ()\n\
 local class = self:inclass()\n\
\n\
 -- get function ------------------------------------------------\n\
 if class then\n\
  output(\"/* get function:\",self.name,\" of class \",class,\" */\")\n\
 else\n\
  output(\"/* get function:\",self.name,\" */\")\n\
 end\n\
 self.cgetname = self:cfuncname(\"tolua_get\")\n\
 output(\"#ifndef TOLUA_DISABLE_\"..self.cgetname)\n\
 output(\"\\nstatic int\",self.cgetname,\"(lua_State* tolua_S)\")\n\
 output(\"{\")\n\
 output(\" int tolua_index;\")\n\
\n\
 -- declare self, if the case\n\
 local _,_,static = strfind(self.mod,'^%s*(static)')\n\
 if class and static==nil then\n\
  output(' ',self.parent.type,'*','self;')\n\
  output(' lua_pushstring(tolua_S,\".self\");')\n\
  output(' lua_rawget(tolua_S,1);')\n\
  output(' self = ')\n\
  output('(',self.parent.type,'*) ')\n\
  output('lua_touserdata(tolua_S,-1);')\n\
 elseif static then\n\
  _,_,self.mod = strfind(self.mod,'^%s*static%s%s*(.*)')\n\
 end\n\
\n\
 -- check index\n\
	output('#ifndef TOLUA_RELEASE\\n')\n\
	output('\\t{')\n\
	output('\\t\\ttolua_Error tolua_err;')\n\
 output('\\t\\tif (!tolua_isnumber(tolua_S,2,0,&tolua_err))')\n\
 output('\\t\\t\\ttolua_error(tolua_S,\"#vinvalid type in array indexing.\",&tolua_err);')\n\
	output('\\t}')\n\
	output('#endif\\n')\n\
	if flags['1'] then -- for compatibility with tolua5 ?\n\
		output('\\ttolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;')\n\
	else\n\
		output('\\ttolua_index = (int)tolua_tonumber(tolua_S,2,0);')\n\
	end\n\
	output('#ifndef TOLUA_RELEASE\\n')\n\
	if self.dim and self.dim ~= '' then\n\
	  output('\\tif (tolua_index<0 || tolua_index>='..self.dim..')')\n\
	else\n\
	  output('\\tif (tolua_index<0)')\n\
	end\n\
 output('\\t\\ttolua_error(tolua_S,\"array indexing out of range.\",NULL);')\n\
	output('#endif\\n')\n\
\n\
 -- return value\n\
 local t,ct = isbasic(self.type)\n\
 local push_func = get_push_function(t)\n\
 if t then\n\
  output('\\ttolua_push'..t..'(tolua_S,(',ct,')'..self:getvalue(class,static)..');')\n\
 else\n\
		t = self.type\n\
  if self.ptr == '&' or self.ptr == '' then\n\
   output('\\t',push_func,'(tolua_S,(void*)&'..self:getvalue(class,static)..',\"',t,'\");')\n\
  else\n\
   output('\\t',push_func,'(tolua_S,(void*)'..self:getvalue(class,static)..',\"',t,'\");')\n\
  end\n\
 end\n\
 output(' return 1;')\n\
 output('}')\n\
 output('#endif //#ifndef TOLUA_DISABLE\\n')\n\
 output('\\n')\n\
\n\
 -- set function ------------------------------------------------\n\
 if not strfind(self.type,'const') then\n\
  if class then\n\
   output(\"/* set function:\",self.name,\" of class \",class,\" */\")\n\
  else\n\
   output(\"/* set function:\",self.name,\" */\")\n\
  end\n\
  self.csetname = self:cfuncname(\"tolua_set\")\n\
  output(\"#ifndef TOLUA_DISABLE_\"..self.csetname)\n\
  output(\"\\nstatic int\",self.csetname,\"(lua_State* tolua_S)\")\n\
  output(\"{\")\n\
\n\
  -- declare index\n\
  output(' int tolua_index;')\n\
\n\
  -- declare self, if the case\n\
  local _,_,static = strfind(self.mod,'^%s*(static)')\n\
  if class and static==nil then\n\
   output(' ',self.parent.type,'*','self;')\n\
   output(' lua_pushstring(tolua_S,\".self\");')\n\
   output(' lua_rawget(tolua_S,1);')\n\
   output(' self = ')\n\
   output('(',self.parent.type,'*) ')\n\
   output('lua_touserdata(tolua_S,-1);')\n\
  elseif static then\n\
   _,_,self.mod = strfind(self.mod,'^%s*static%s%s*(.*)')\n\
  end\n\
\n\
  -- check index\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
	 output(' {')\n\
	 output('  tolua_Error tolua_err;')\n\
  output('  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))')\n\
  output('   tolua_error(tolua_S,\"#vinvalid type in array indexing.\",&tolua_err);')\n\
		output(' }')\n\
		output('#endif\\n')\n\
\n\
	if flags['1'] then -- for compatibility with tolua5 ?\n\
		output('\\ttolua_index = (int)tolua_tonumber(tolua_S,2,0)-1;')\n\
	else\n\
		output('\\ttolua_index = (int)tolua_tonumber(tolua_S,2,0);')\n\
	end\n\
\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
	if self.dim and self.dim ~= '' then\n\
	  output('\\tif (tolua_index<0 || tolua_index>='..self.dim..')')\n\
	else\n\
	  output('\\tif (tolua_index<0)')\n\
	end\n\
  output('\\t\\ttolua_error(tolua_S,\"array indexing out of range.\",NULL);')\n\
		output('#endif\\n')\n\
\n\
  -- assign value\n\
  local ptr = ''\n\
  if self.ptr~='' then ptr = '*' end\n\
  output('\\t')\n\
  if class and static then\n\
   output(class..'::'..self.name..'[tolua_index]')\n\
  elseif class then\n\
   output('self->'..self.name..'[tolua_index]')\n\
  else\n\
   output(self.name..'[tolua_index]')\n\
  end\n\
  local t = isbasic(self.type)\n\
  output(' = ')\n\
  if not t and ptr=='' then output('*') end\n\
  output('((',self.mod,self.type)\n\
  if not t then\n\
   output('*')\n\
  end\n\
  output(') ')\n\
  local def = 0\n\
  if self.def ~= '' then def = self.def end\n\
  if t then\n\
   output(' tolua_to'..t,'(tolua_S,3,',def,'));')\n\
  else\n\
   local to_func = get_to_function(self.type)\n\
   output(to_func,'(tolua_S,3,',def,'));')\n\
  end\n\
  output(' return 0;')\n\
  output('}')\n\
  output('#endif //#ifndef TOLUA_DISABLE\\n')\n\
  output('\\n')\n\
 end\n\
\n\
end\n\
\n\
function classArray:register (pre)\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
\n\
 pre = pre or ''\n\
 if self.csetname then\n\
  output(pre..'tolua_array(tolua_S,\"'..self.lname..'\",'..self.cgetname..','..self.csetname..');')\n\
 else\n\
  output(pre..'tolua_array(tolua_S,\"'..self.lname..'\",'..self.cgetname..',NULL);')\n\
 end\n\
end\n\
\n\
-- Internal constructor\n\
function _Array (t)\n\
 setmetatable(t,classArray)\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects a string representing the variable declaration.\n\
function Array (s)\n\
 return _Array (Declaration(s,'var'))\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/array.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: function class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
\n\
-- Function class\n\
-- Represents a function or a class method.\n\
-- The following fields are stored:\n\
--  mod  = type modifiers\n\
--  type = type\n\
--  ptr  = \"*\" or \"&\", if representing a pointer or a reference\n\
--  name = name\n\
--  lname = lua name\n\
--  args  = list of argument declarations\n\
--  const = if it is a method receiving a const \"this\".\n\
classFunction = {\n\
 mod = '',\n\
 type = '',\n\
 ptr = '',\n\
 name = '',\n\
 args = {n=0},\n\
 const = '',\n\
}\n\
classFunction.__index = classFunction\n\
setmetatable(classFunction,classFeature)\n\
\n\
-- declare tags\n\
function classFunction:decltype ()\n\
 self.type = typevar(self.type)\n\
 if strfind(self.mod,'const') then\n\
	 self.type = 'const '..self.type\n\
		self.mod = gsub(self.mod,'const','')\n\
	end\n\
 local i=1\n\
 while self.args[i] do\n\
  self.args[i]:decltype()\n\
  i = i+1\n\
 end\n\
end\n\
\n\
\n\
-- Write binding function\n\
-- Outputs C/C++ binding function.\n\
function classFunction:supcode (local_constructor)\n\
\n\
 local overload = strsub(self.cname,-2,-1) - 1  -- indicate overloaded func\n\
 local nret = 0      -- number of returned values\n\
 local class = self:inclass()\n\
 local _,_,static = strfind(self.mod,'^%s*(static)')\n\
 if class then\n\
\n\
 	if self.name == 'new' and self.parent.flags.pure_virtual then\n\
 		-- no constructor for classes with pure virtual methods\n\
 		return\n\
 	end\n\
\n\
 	if local_constructor then\n\
		output(\"/* method: new_local of class \",class,\" */\")\n\
	else\n\
		output(\"/* method:\",self.name,\" of class \",class,\" */\")\n\
	end\n\
 else\n\
  output(\"/* function:\",self.name,\" */\")\n\
 end\n\
\n\
 if local_constructor then\n\
  output(\"#ifndef TOLUA_DISABLE_\"..self.cname..\"_local\")\n\
  output(\"\\nstatic int\",self.cname..\"_local\",\"(lua_State* tolua_S)\")\n\
 else\n\
  output(\"#ifndef TOLUA_DISABLE_\"..self.cname)\n\
  output(\"\\nstatic int\",self.cname,\"(lua_State* tolua_S)\")\n\
 end\n\
 output(\"{\")\n\
\n\
 -- check types\n\
	if overload < 0 then\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
	end\n\
	output('\\ttolua_Error tolua_err;')\n\
 output('\\tif (\\n')\n\
 -- check self\n\
 local narg\n\
 if class then narg=2 else narg=1 end\n\
 if class then\n\
		local func = get_is_function(self.parent.type)\n\
		local type = self.parent.type\n\
		if self.name=='new' or static~=nil then\n\
			func = 'tolua_isusertable'\n\
			type = self.parent.type\n\
		end\n\
		if self.const ~= '' then\n\
			type = \"const \"..type\n\
		end\n\
		output('\\t\\t!'..func..'(tolua_S,1,\"'..type..'\",0,&tolua_err) ||\\n')\n\
 end\n\
 -- check args\n\
 if self.args[1].type ~= 'void' then\n\
  local i=1\n\
  while self.args[i] do\n\
   local btype = isbasic(self.args[i].type)\n\
   if btype ~= 'value' and btype ~= 'state' then\n\
    output('\\t\\t'..self.args[i]:outchecktype(narg)..' ||\\n')\n\
   end\n\
   if btype ~= 'state' then\n\
	   narg = narg+1\n\
   end\n\
   i = i+1\n\
  end\n\
 end\n\
 -- check end of list\n\
 output('\\t\\t!tolua_isnoobj(tolua_S,'..narg..',&tolua_err)\\n\\t)')\n\
	output('\\t\\tgoto tolua_lerror;')\n\
\n\
 output('\\telse\\n')\n\
	if overload < 0 then\n\
	 output('#endif\\n')\n\
	end\n\
	output('\\t{')\n\
\n\
 -- declare self, if the case\n\
 local narg\n\
 if class then narg=2 else narg=1 end\n\
 if class and self.name~='new' and static==nil then\n\
  output('\\t',self.const,self.parent.type,'*','self = ')\n\
  output('(',self.const,self.parent.type,'*) ')\n\
  local to_func = get_to_function(self.parent.type)\n\
  output(to_func,'(tolua_S,1,0);')\n\
 elseif static then\n\
  _,_,self.mod = strfind(self.mod,'^%s*static%s%s*(.*)')\n\
 end\n\
 -- declare parameters\n\
 if self.args[1].type ~= 'void' then\n\
  local i=1\n\
  while self.args[i] do\n\
   self.args[i]:declare(narg)\n\
   if isbasic(self.args[i].type) ~= \"state\" then\n\
	   narg = narg+1\n\
   end\n\
   i = i+1\n\
  end\n\
 end\n\
\n\
 -- check self\n\
 if class and self.name~='new' and static==nil then\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
	 output('\\tif (!self)')\n\
	 output('\\t\\ttolua_error(tolua_S,\"'..output_error_hook(\"invalid \'self\' in function \'%s\'\", self.name)..'\", NULL);');\n\
	 output('#endif\\n')\n\
 end\n\
\n\
 -- get array element values\n\
 if class then narg=2 else narg=1 end\n\
 if self.args[1].type ~= 'void' then\n\
  local i=1\n\
  while self.args[i] do\n\
   self.args[i]:getarray(narg)\n\
   narg = narg+1\n\
   i = i+1\n\
  end\n\
 end\n\
\n\
 pre_call_hook(self)\n\
\n\
 local out = string.find(self.mod, \"tolua_outside\")\n\
 -- call function\n\
 if class and self.name=='delete' then\n\
  output('\\tMtolua_delete(self);')\n\
 elseif class and self.name == 'operator&[]' then\n\
  if flags['1'] then -- for compatibility with tolua5 ?\n\
	output('\\tself->operator[](',self.args[1].name,'-1) = ',self.args[2].name,';')\n\
  else\n\
    output('\\tself->operator[](',self.args[1].name,') = ',self.args[2].name,';')\n\
  end\n\
 else\n\
  output('\\t\\t{')\n\
  if self.type ~= '' and self.type ~= 'void' then\n\
   output('\\t\\t',self.mod,self.type,self.ptr,'tolua_ret = ')\n\
   output('(',self.mod,self.type,self.ptr,') ')\n\
  else\n\
   output('\\t\\t')\n\
  end\n\
  if class and self.name=='new' then\n\
   output('Mtolua_new((',self.type,')(')\n\
  elseif class and static then\n\
	if out then\n\
		output(self.name,'(')\n\
	else\n\
		output(class..'::'..self.name,'(')\n\
	end\n\
  elseif class then\n\
	if out then\n\
		output(self.name,'(')\n\
	else\n\
	  if self.cast_operator then\n\
	  	--output('static_cast<',self.mod,self.type,self.ptr,' >(*self')\n\
		output('self->operator ',self.mod,self.type,'(')\n\
	  else\n\
		output('self->'..self.name,'(')\n\
	  end\n\
	end\n\
  else\n\
   output(self.name,'(')\n\
  end\n\
\n\
  if out and not static then\n\
  	output('self')\n\
	if self.args[1] and self.args[1].name ~= '' then\n\
		output(',')\n\
	end\n\
  end\n\
  -- write parameters\n\
  local i=1\n\
  while self.args[i] do\n\
   self.args[i]:passpar()\n\
   i = i+1\n\
   if self.args[i] then\n\
    output(',')\n\
   end\n\
  end\n\
\n\
  if class and self.name == 'operator[]' and flags['1'] then\n\
	output('-1);')\n\
  else\n\
	if class and self.name=='new' then\n\
		output('));') -- close Mtolua_new(\n\
	else\n\
		output(');')\n\
	end\n\
  end\n\
\n\
  -- return values\n\
  if self.type ~= '' and self.type ~= 'void' then\n\
   nret = nret + 1\n\
   local t,ct = isbasic(self.type)\n\
   if t and self.name ~= \"new\" then\n\
   	if self.cast_operator and _basic_raw_push[t] then\n\
		output('\\t\\t\\t',_basic_raw_push[t],'(tolua_S,(',ct,')tolua_ret);')\n\
   	else\n\
	    output('\\t\\t\\ttolua_push'..t..'(tolua_S,(',ct,')tolua_ret);')\n\
	end\n\
   else\n\
	t = self.type\n\
	new_t = string.gsub(t, \"const%s+\", \"\")\n\
	local owned = false\n\
	if string.find(self.mod, \"tolua_owned\") then\n\
		owned = true\n\
	end\n\
    local push_func = get_push_function(t)\n\
    if self.ptr == '' then\n\
     output('\\t\\t{')\n\
     output('#ifdef __cplusplus\\n')\n\
     output('\\t\\t\\tvoid* tolua_obj = Mtolua_new((',new_t,')(tolua_ret));')\n\
     output('\\t\\t\\t',push_func,'(tolua_S,tolua_obj,\"',t,'\");')\n\
     output('\\t\\t\\ttolua_register_gc(tolua_S,lua_gettop(tolua_S));')\n\
     output('#else\\n')\n\
     output('\\t\\t\\tvoid* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(',t,'));')\n\
     output('\\t\\t\\t',push_func,'(tolua_S,tolua_obj,\"',t,'\");')\n\
     output('\\t\\t\\ttolua_register_gc(tolua_S,lua_gettop(tolua_S));')\n\
     output('#endif\\n')\n\
     output('\\t\\t}')\n\
    elseif self.ptr == '&' then\n\
     output('\\t\\t',push_func,'(tolua_S,(void*)&tolua_ret,\"',t,'\");')\n\
    else\n\
	 output('\\t\\t',push_func,'(tolua_S,(void*)tolua_ret,\"',t,'\");')\n\
	 if owned or local_constructor then\n\
      output('\\t\\t\\ttolua_register_gc(tolua_S,lua_gettop(tolua_S));')\n\
	 end\n\
    end\n\
   end\n\
  end\n\
  local i=1\n\
  while self.args[i] do\n\
   nret = nret + self.args[i]:retvalue()\n\
   i = i+1\n\
  end\n\
  output('\\t\\t}')\n\
\n\
  -- set array element values\n\
  if class then narg=2 else narg=1 end\n\
  if self.args[1].type ~= 'void' then\n\
   local i=1\n\
   while self.args[i] do\n\
    self.args[i]:setarray(narg)\n\
    narg = narg+1\n\
    i = i+1\n\
   end\n\
  end\n\
\n\
  -- free dynamically allocated array\n\
  if self.args[1].type ~= 'void' then\n\
   local i=1\n\
   while self.args[i] do\n\
    self.args[i]:freearray()\n\
    i = i+1\n\
   end\n\
  end\n\
 end\n\
\n\
 post_call_hook(self)\n\
\n\
 output('\\t}')\n\
 output('\\treturn '..nret..';')\n\
\n\
 -- call overloaded function or generate error\n\
	if overload < 0 then\n\
\n\
		output('#ifndef TOLUA_RELEASE\\n')\n\
		output('tolua_lerror:\\n')\n\
		output('tolua_error(tolua_S,\"'..output_error_hook(\"#ferror in function \'%s\'.\", self.lname)..'\",&tolua_err);')\n\
		output('\\treturn 0;')\n\
		output('#endif\\n')\n\
	else\n\
		local _local = \"\"\n\
		if local_constructor then\n\
			_local = \"_local\"\n\
		end\n\
		output('tolua_lerror:\\n')\n\
		output('return '..strsub(self.cname,1,-3)..format(\"%02d\",overload).._local..'(tolua_S);')\n\
	end\n\
 output('}')\n\
 output('#endif //#ifndef TOLUA_DISABLE\\n')\n\
 output('\\n')\n\
\n\
	-- recursive call to write local constructor\n\
	if class and self.name=='new' and not local_constructor then\n\
\n\
		self:supcode(1)\n\
	end\n\
\n\
end\n\
\n\
\n\
-- register function\n\
function classFunction:register (pre)\n\
\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
\n\
 	if self.name == 'new' and self.parent.flags.pure_virtual then\n\
 		-- no constructor for classes with pure virtual methods\n\
 		return\n\
 	end\n\
\n\
 output(pre..'tolua_function(tolua_S,\"'..self.lname..'\",'..self.cname..');')\n\
  if self.name == 'new' then\n\
	  output(pre..'tolua_function(tolua_S,\"new_local\",'..self.cname..'_local);')\n\
	  output(pre..'tolua_function(tolua_S,\".call\",'..self.cname..'_local);')\n\
	  --output(' tolua_set_call_event(tolua_S,'..self.cname..'_local, \"'..self.parent.type..'\");')\n\
  end\n\
end\n\
\n\
-- Print method\n\
function classFunction:print (ident,close)\n\
 print(ident..\"Function{\")\n\
 print(ident..\" mod  = '\"..self.mod..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\" ptr  = '\"..self.ptr..\"',\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 print(ident..\" lname = '\"..self.lname..\"',\")\n\
 print(ident..\" const = '\"..self.const..\"',\")\n\
 print(ident..\" cname = '\"..self.cname..\"',\")\n\
 print(ident..\" lname = '\"..self.lname..\"',\")\n\
 print(ident..\" args = {\")\n\
 local i=1\n\
 while self.args[i] do\n\
  self.args[i]:print(ident..\"  \",\",\")\n\
  i = i+1\n\
 end\n\
 print(ident..\" }\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
-- check if it returns an object by value\n\
function classFunction:requirecollection (t)\n\
	local r = false\n\
	if self.type ~= '' and not isbasic(self.type) and self.ptr=='' then\n\
		local type = gsub(self.type,\"%s*const%s+\",\"\")\n\
	 t[type] = \"tolua_collect_\" .. clean_template(type)\n\
	 r = true\n\
	end\n\
	local i=1\n\
	while self.args[i] do\n\
		r = self.args[i]:requirecollection(t) or r\n\
		i = i+1\n\
	end\n\
	return r\n\
end\n\
\n\
-- determine lua function name overload\n\
function classFunction:overload ()\n\
 return self.parent:overload(self.lname)\n\
end\n\
\n\
\n\
function param_object(par) -- returns true if the parameter has an object as its default value\n\
\n\
	if not string.find(par, '=') then return false end -- it has no default value\n\
\n\
	local _,_,def = string.find(par, \"=(.*)$\")\n\
\n\
	if string.find(par, \"|\") then -- a list of flags\n\
\n\
		return true\n\
	end\n\
\n\
	if string.find(par, \"%*\") then -- it's a pointer with a default value\n\
\n\
		if string.find(par, '=%s*new') or string.find(par, \"%(\") then -- it's a pointer with an instance as default parameter.. is that valid?\n\
			return true\n\
		end\n\
		return false -- default value is 'NULL' or something\n\
	end\n\
\n\
\n\
	if string.find(par, \"[%(&]\") then\n\
		return true\n\
	end -- default value is a constructor call (most likely for a const reference)\n\
\n\
	--if string.find(par, \"&\") then\n\
\n\
	--	if string.find(def, \":\") or string.find(def, \"^%s*new%s+\") then\n\
\n\
	--		-- it's a reference with default to something like Class::member, or 'new Class'\n\
	--		return true\n\
	--	end\n\
	--end\n\
\n\
	return false -- ?\n\
end\n\
\n\
function strip_last_arg(all_args, last_arg) -- strips the default value from the last argument\n\
\n\
	local _,_,s_arg = string.find(last_arg, \"^([^=]+)\")\n\
	last_arg = string.gsub(last_arg, \"([%%%(%)])\", \"%%%1\");\n\
	all_args = string.gsub(all_args, \"%s*,%s*\"..last_arg..\"%s*%)%s*$\", \")\")\n\
	return all_args, s_arg\n\
end\n\
\n\
\n\
\n\
-- Internal constructor\n\
function _Function (t)\n\
 setmetatable(t,classFunction)\n\
\n\
 if t.const ~= 'const' and t.const ~= '' then\n\
  error(\"#invalid 'const' specification\")\n\
 end\n\
\n\
 append(t)\n\
 if t:inclass() then\n\
 --print ('t.name is '..t.name..', parent.name is '..t.parent.name)\n\
  if string.gsub(t.name, \"%b<>\", \"\") == string.gsub(t.parent.original_name or t.parent.name, \"%b<>\", \"\") then\n\
   t.name = 'new'\n\
   t.lname = 'new'\n\
   t.parent._new = true\n\
   t.type = t.parent.name\n\
   t.ptr = '*'\n\
  elseif string.gsub(t.name, \"%b<>\", \"\") == '~'..string.gsub(t.parent.original_name or t.parent.name, \"%b<>\", \"\") then\n\
   t.name = 'delete'\n\
   t.lname = 'delete'\n\
   t.parent._delete = true\n\
  end\n\
 end\n\
 t.cname = t:cfuncname(\"tolua\")..t:overload(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects three strings: one representing the function declaration,\n\
-- another representing the argument list, and the third representing\n\
-- the \"const\" or empty string.\n\
function Function (d,a,c)\n\
 --local t = split(strsub(a,2,-2),',') -- eliminate braces\n\
 --local t = split_params(strsub(a,2,-2))\n\
\n\
	if not flags['W'] and string.find(a, \"%.%.%.%s*%)\") then\n\
\n\
		warning(\"Functions with variable arguments (`...') are not supported. Ignoring \"..d..a..c)\n\
		return nil\n\
	end\n\
\n\
\n\
 local i=1\n\
 local l = {n=0}\n\
\n\
 	a = string.gsub(a, \"%s*([%(%)])%s*\", \"%1\")\n\
	local t,strip,last = strip_pars(strsub(a,2,-2));\n\
	if strip then\n\
		--local ns = string.sub(strsub(a,1,-2), 1, -(string.len(last)+1))\n\
		local ns = join(t, \",\", 1, last-1)\n\
\n\
		ns = \"(\"..string.gsub(ns, \"%s*,%s*$\", \"\")..')'\n\
		--ns = strip_defaults(ns)\n\
\n\
		local f = Function(d, ns, c)\n\
		for i=1,last do\n\
			t[i] = string.gsub(t[i], \"=.*$\", \"\")\n\
		end\n\
	end\n\
\n\
 while t[i] do\n\
  l.n = l.n+1\n\
  l[l.n] = Declaration(t[i],'var',true)\n\
  i = i+1\n\
 end\n\
 local f = Declaration(d,'func')\n\
 f.args = l\n\
 f.const = c\n\
 return _Function(f)\n\
end\n\
\n\
function join(t, sep, first, last)\n\
\n\
	first = first or 1\n\
	last = last or #t\n\
	local lsep = \"\"\n\
	local ret = \"\"\n\
	local loop = false\n\
	for i = first,last do\n\
\n\
		ret = ret..lsep..t[i]\n\
		lsep = sep\n\
		loop = true\n\
	end\n\
	if not loop then\n\
		return \"\"\n\
	end\n\
\n\
	return ret\n\
end\n\
\n\
function strip_pars(s)\n\
\n\
	local t = split_c_tokens(s, ',')\n\
	local strip = false\n\
	local last\n\
\n\
	for i=t.n,1,-1 do\n\
\n\
		if not strip and param_object(t[i]) then\n\
			last = i\n\
			strip = true\n\
		end\n\
		--if strip then\n\
		--	t[i] = string.gsub(t[i], \"=.*$\", \"\")\n\
		--end\n\
	end\n\
\n\
	return t,strip,last\n\
\n\
end\n\
\n\
function strip_defaults(s)\n\
\n\
	s = string.gsub(s, \"^%(\", \"\")\n\
	s = string.gsub(s, \"%)$\", \"\")\n\
\n\
	local t = split_c_tokens(s, \",\")\n\
	local sep, ret = \"\",\"\"\n\
	for i=1,t.n do\n\
		t[i] = string.gsub(t[i], \"=.*$\", \"\")\n\
		ret = ret..sep..t[i]\n\
		sep = \",\"\n\
	end\n\
\n\
	return \"(\"..ret..\")\"\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/function.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: operator class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Operator class\n\
-- Represents an operator function or a class operator method.\n\
-- It stores the same fields as functions do plus:\n\
--  kind = set of character representing the operator (as it appers in C++ code)\n\
classOperator = {\n\
 kind = '',\n\
}\n\
classOperator.__index = classOperator\n\
setmetatable(classOperator,classFunction)\n\
\n\
-- table to transform operator kind into the appropriate tag method name\n\
_TM = {['+'] = 'add',\n\
       ['-'] = 'sub',\n\
       ['*'] = 'mul',\n\
       ['/'] = 'div',\n\
       ['<'] = 'lt',\n\
       ['<='] = 'le',\n\
       ['=='] = 'eq',\n\
       ['[]'] = 'geti',\n\
       ['&[]'] = 'seti',\n\
       --['->'] = 'flechita',\n\
      }\n\
\n\
\n\
-- Print method\n\
function classOperator:print (ident,close)\n\
 print(ident..\"Operator{\")\n\
 print(ident..\" kind  = '\"..self.kind..\"',\")\n\
 print(ident..\" mod  = '\"..self.mod..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\" ptr  = '\"..self.ptr..\"',\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 print(ident..\" const = '\"..self.const..\"',\")\n\
 print(ident..\" cname = '\"..self.cname..\"',\")\n\
 print(ident..\" lname = '\"..self.lname..\"',\")\n\
 print(ident..\" args = {\")\n\
 local i=1\n\
 while self.args[i] do\n\
  self.args[i]:print(ident..\"  \",\",\")\n\
  i = i+1\n\
 end\n\
 print(ident..\" }\")\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
function classOperator:supcode_tmp()\n\
\n\
	if not _TM[self.kind] then\n\
		return classFunction.supcode(self)\n\
	end\n\
\n\
	-- no overload, no parameters, always inclass\n\
	output(\"/* method:\",self.name,\" of class \",self:inclass(),\" */\")\n\
\n\
	output(\"#ifndef TOLUA_DISABLE_\"..self.cname)\n\
	output(\"\\nstatic int\",self.cname,\"(lua_State* tolua_S)\")\n\
\n\
	if overload < 0 then\n\
	 output('#ifndef TOLUA_RELEASE\\n')\n\
	end\n\
	output(' tolua_Error tolua_err;')\n\
	output(' if (\\n')\n\
	-- check self\n\
	local is_func = get_is_function(self.parent.type)\n\
	output('\\t\\t\\t!'..is_func..'(tolua_S,1,\"'..self.parent.type..'\",0,&tolua_err) ||\\n')\n\
	output('\\t\\t\\t!tolua_isnoobj(tolua_S,2,&tolua_err)\\n )')\n\
	output('\\t\\tgoto tolua_lerror;')\n\
\n\
	output('\\telse\\n')\n\
	output('#endif\\n') -- tolua_release\n\
	output('\\t{')\n\
\n\
	-- declare self\n\
	output('\\t\\t',self.const,self.parent.type,'*','self = ')\n\
	output('(',self.const,self.parent.type,'*) ')\n\
	local to_func = get_to_func(self.parent.type)\n\
	output(to_func,'(tolua_S,1,0);')\n\
\n\
	-- check self\n\
	output('#ifndef TOLUA_RELEASE\\n')\n\
	output('\\tif (!self)')\n\
	output('\\t\\ttolua_error(tolua_S,\"'..output_error_hook(\"invalid \'self\' in function \'%s\'\", self.name)..'\",NULL);');\n\
	output('#endif\\n')\n\
\n\
	-- cast self\n\
	output('\\t',self.mod,self.type,self.ptr,'tolua_ret = ')\n\
	output('(',self.mod,self.type,self.ptr,')(*self);')\n\
\n\
	-- return value\n\
	local t,ct = isbasic(self.type)\n\
	if t then\n\
		output('\\t\\ttolua_push'..t..'(tolua_S,(',ct,')tolua_ret);')\n\
	else\n\
		t = self.type\n\
		local push_func = get_push_function(t)\n\
		new_t = string.gsub(t, \"const%s+\", \"\")\n\
		if self.ptr == '' then\n\
			output('\\t\\t{')\n\
			output('#ifdef __cplusplus\\n')\n\
			output('\\t\\t\\tvoid* tolua_obj = Mtolua_new((',new_t,')(tolua_ret));')\n\
			output('\\t\\t\\t',push_func,'(tolua_S,tolua_obj,\"',t,'\");')\n\
			output('\\t\\t\\ttolua_register_gc(tolua_S,lua_gettop(tolua_S));')\n\
			output('#else\\n')\n\
			output('\\t\\t\\tvoid* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(',t,'));')\n\
			output('\\t\\t\\t',push_func,'(tolua_S,tolua_obj,\"',t,'\");')\n\
			output('\\t\\t\\ttolua_register_gc(tolua_S,lua_gettop(tolua_S));')\n\
			output('#endif\\n')\n\
			output('\\t\\t}')\n\
		elseif self.ptr == '&' then\n\
			output('\\t\\t',push_func,'(tolua_S,(void*)&tolua_ret,\"',t,'\");')\n\
		else\n\
			if local_constructor then\n\
				output('\\t\\t\\t',push_func,'(tolua_S,(void *)tolua_ret,\"',t,'\");')\n\
				output('\\t\\t\\ttolua_register_gc(tolua_S,lua_gettop(tolua_S));')\n\
			else\n\
				output('\\t\\t',push_func,'(tolua_S,(void*)tolua_ret,\"',t,'\");')\n\
			end\n\
		end\n\
	end\n\
\n\
	output('\\t}')\n\
	output(' return 1;')\n\
\n\
	output('#ifndef TOLUA_RELEASE\\n')\n\
	output('tolua_lerror:\\n')\n\
	output('\\ttolua_error(tolua_S,\"'..output_error_hook(\"#ferror in function \'%s\'.\", self.lname)..'\",&tolua_err);')\n\
	output('\\treturn 0;')\n\
	output('#endif\\n')\n\
\n\
\n\
	output('}')\n\
	output('#endif //#ifndef TOLUA_DISABLE\\n')\n\
	output('\\n')\n\
end\n\
\n\
-- Internal constructor\n\
function _Operator (t)\n\
 setmetatable(t,classOperator)\n\
\n\
 if t.const ~= 'const' and t.const ~= '' then\n\
  error(\"#invalid 'const' specification\")\n\
 end\n\
\n\
 append(t)\n\
 if not t:inclass() then\n\
  error(\"#operator can only be defined as class member\")\n\
 end\n\
\n\
 --t.name = t.name .. \"_\" .. (_TM[t.kind] or t.kind)\n\
 t.cname = t:cfuncname(\"tolua\")..t:overload(t)\n\
 t.name = \"operator\" .. t.kind  -- set appropriate calling name\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
function Operator (d,k,a,c)\n\
\n\
	local op_k = string.gsub(k, \"^%s*\", \"\")\n\
	op_k = string.gsub(k, \"%s*$\", \"\")\n\
	--if string.find(k, \"^[%w_:%d<>%*%&]+$\") then\n\
	if d == \"operator\" and k ~= '' then\n\
\n\
		d = k..\" operator\"\n\
	elseif not _TM[op_k] then\n\
\n\
		if flags['W'] then\n\
			error(\"tolua: no support for operator\" .. f.kind)\n\
		else\n\
			warning(\"No support for operator \"..op_k..\", ignoring\")\n\
			return nil\n\
		end\n\
	end\n\
\n\
	local ref = ''\n\
 local t = split_c_tokens(strsub(a,2,strlen(a)-1),',') -- eliminate braces\n\
 local i=1\n\
 local l = {n=0}\n\
 while t[i] do\n\
  l.n = l.n+1\n\
  l[l.n] = Declaration(t[i],'var')\n\
  i = i+1\n\
 end\n\
 if k == '[]' then\n\
	 local _\n\
	 _, _, ref = strfind(d,'(&)')\n\
  d = gsub(d,'&','')\n\
 elseif k=='&[]' then\n\
  l.n = l.n+1\n\
  l[l.n] = Declaration(d,'var')\n\
  l[l.n].name = 'tolua_value'\n\
 end\n\
 local f = Declaration(d,'func')\n\
 if k == '[]' and (l[1]==nil or isbasic(l[1].type)~='number') then\n\
  error('operator[] can only be defined for numeric index.')\n\
 end\n\
 f.args = l\n\
 f.const = c\n\
 f.kind = op_k\n\
 f.lname = \".\"..(_TM[f.kind] or f.kind)\n\
 if not _TM[f.kind] then\n\
 	f.cast_operator = true\n\
 end\n\
 if f.kind == '[]' and ref=='&' and f.const~='const' then\n\
  Operator(d,'&'..k,a,c) 	-- create correspoding set operator\n\
 end\n\
 return _Operator(f)\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/operator.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
\n\
_global_templates = {}\n\
\n\
classTemplateClass = {\n\
\n\
	name = '',\n\
	body = '',\n\
	parents = {},\n\
	args = {}, -- the template arguments\n\
}\n\
\n\
classTemplateClass.__index = classTemplateClass\n\
\n\
\n\
function classTemplateClass:throw(types, local_scope)\n\
\n\
	--if table.getn(types) ~= table.getn(self.args) then\n\
	--	error(\"#invalid parameter count\")\n\
	--end\n\
\n\
	-- replace\n\
	for i =1 , types.n do\n\
\n\
		local Il = split_c_tokens(types[i], \" \")\n\
		if #Il ~= #(self.args) then\n\
			error(\"#invalid parameter count for \"..types[i])\n\
		end\n\
		local bI = self.body\n\
		local pI = {}\n\
		for j = 1,self.args.n do\n\
			--Tl[j] = findtype(Tl[j]) or Tl[j]\n\
			bI = string.gsub(bI, \"([^_%w])\"..self.args[j]..\"([^_%w])\", \"%1\"..Il[j]..\"%2\")\n\
			if self.parents then\n\
				for i=1,#(self.parents) do\n\
					pI[i] = string.gsub(self.parents[i], \"([^_%w]?)\"..self.args[j]..\"([^_%w]?)\", \"%1\"..Il[j]..\"%2\")\n\
				end\n\
			end\n\
		end\n\
		--local append = \"<\"..string.gsub(types[i], \"%s+\", \",\")..\">\"\n\
		local append = \"<\"..concat(Il, 1, #Il, \",\")..\">\"\n\
		append = string.gsub(append, \"%s*,%s*\", \",\")\n\
		append = string.gsub(append, \">>\", \"> >\")\n\
		for i=1,#pI do\n\
			--pI[i] = string.gsub(pI[i], \">>\", \"> >\")\n\
			pI[i] = resolve_template_types(pI[i])\n\
		end\n\
		bI = string.gsub(bI, \">>\", \"> >\")\n\
		local n = self.name\n\
		if local_scope then\n\
			n = self.local_name\n\
		end\n\
\n\
		Class(n..append, pI, bI)\n\
	end\n\
end\n\
\n\
\n\
function TemplateClass(name, parents, body, parameters)\n\
\n\
	local o = {\n\
	\n\
		parents = parents,\n\
		body = body,\n\
		args = parameters,\n\
	}\n\
	\n\
	local oname = string.gsub(name, \"@.*$\", \"\")\n\
	oname = getnamespace(classContainer.curr)..oname\n\
	o.name = oname\n\
\n\
	o.local_name = name\n\
	\n\
	setmetatable(o, classTemplateClass)\n\
\n\
	if _global_templates[oname] then\n\
		warning(\"Duplicate declaration of template \"..oname)\n\
	else\n\
		_global_templates[oname] = o\n\
	end\n\
\n\
	return o\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/template_class.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- tolua: class class\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- $Id: $\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
\n\
-- Class class\n\
-- Represents a class definition.\n\
-- Stores the following fields:\n\
--    name = class name\n\
--    base = class base, if any (only single inheritance is supported)\n\
--    {i}  = list of members\n\
classClass = {\n\
 classtype = 'class',\n\
 name = '',\n\
 base = '',\n\
 type = '',\n\
 btype = '',\n\
 ctype = '',\n\
}\n\
classClass.__index = classClass\n\
setmetatable(classClass,classContainer)\n\
\n\
\n\
-- register class\n\
function classClass:register (pre)\n\
\n\
	if not self:check_public_access() then\n\
		return\n\
	end\n\
\n\
 pre = pre or ''\n\
 push(self)\n\
	if _collect[self.type] then\n\
		output(pre,'#ifdef __cplusplus\\n')\n\
  output(pre..'tolua_cclass(tolua_S,\"'..self.lname..'\",\"'..self.type..'\",\"'..self.btype..'\",'.._collect[self.type]..');')\n\
		output(pre,'#else\\n')\n\
  output(pre..'tolua_cclass(tolua_S,\"'..self.lname..'\",\"'..self.type..'\",\"'..self.btype..'\",NULL);')\n\
		output(pre,'#endif\\n')\n\
	else\n\
  output(pre..'tolua_cclass(tolua_S,\"'..self.lname..'\",\"'..self.type..'\",\"'..self.btype..'\",NULL);')\n\
	end\n\
	if self.extra_bases then\n\
		for k,base in ipairs(self.extra_bases) do\n\
			-- not now\n\
   --output(pre..' tolua_addbase(tolua_S, \"'..self.type..'\", \"'..base..'\");')\n\
		end\n\
	end\n\
 output(pre..'tolua_beginmodule(tolua_S,\"'..self.lname..'\");')\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:register(pre..' ')\n\
  i = i+1\n\
 end\n\
 output(pre..'tolua_endmodule(tolua_S);')\n\
	pop()\n\
end\n\
\n\
-- return collection requirement\n\
function classClass:requirecollection (t)\n\
	if self.flags.protected_destructor or (not self:check_public_access()) then\n\
		return false\n\
	end\n\
 push(self)\n\
	local r = false\n\
 local i=1\n\
 while self[i] do\n\
  r = self[i]:requirecollection(t) or r\n\
  i = i+1\n\
 end\n\
	pop()\n\
	-- only class that exports destructor can be appropriately collected\n\
	-- classes that export constructors need to have a collector (overrided by -D flag on command line)\n\
	if self._delete or ((not flags['D']) and self._new) then\n\
		--t[self.type] = \"tolua_collect_\" .. gsub(self.type,\"::\",\"_\")\n\
		t[self.type] = \"tolua_collect_\" .. clean_template(self.type)\n\
		r = true\n\
	end\n\
 return r\n\
end\n\
\n\
-- output tags\n\
function classClass:decltype ()\n\
 push(self)\n\
	self.type = regtype(self.original_name or self.name)\n\
	self.btype = typevar(self.base)\n\
	self.ctype = 'const '..self.type\n\
	if self.extra_bases then\n\
		for i=1,#self.extra_bases do\n\
			self.extra_bases[i] = typevar(self.extra_bases[i])\n\
		end\n\
	end\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:decltype()\n\
  i = i+1\n\
 end\n\
	pop()\n\
end\n\
\n\
\n\
-- Print method\n\
function classClass:print (ident,close)\n\
 print(ident..\"Class{\")\n\
 print(ident..\" name = '\"..self.name..\"',\")\n\
 print(ident..\" base = '\"..self.base..\"';\")\n\
 print(ident..\" lname = '\"..self.lname..\"',\")\n\
 print(ident..\" type = '\"..self.type..\"',\")\n\
 print(ident..\" btype = '\"..self.btype..\"',\")\n\
 print(ident..\" ctype = '\"..self.ctype..\"',\")\n\
 local i=1\n\
 while self[i] do\n\
  self[i]:print(ident..\" \",\",\")\n\
  i = i+1\n\
 end\n\
 print(ident..\"}\"..close)\n\
end\n\
\n\
function classClass:set_protected_destructor(p)\n\
	self.flags.protected_destructor = self.flags.protected_destructor or p\n\
end\n\
\n\
-- Internal constructor\n\
function _Class (t)\n\
 setmetatable(t,classClass)\n\
 t:buildnames()\n\
 append(t)\n\
 return t\n\
end\n\
\n\
-- Constructor\n\
-- Expects the name, the base (array) and the body of the class.\n\
function Class (n,p,b)\n\
\n\
	if #p > 1 then\n\
		b = string.sub(b, 1, -2)\n\
		for i=2,#p,1 do\n\
			b = b..\"\\n tolua_inherits \"..p[i]..\" __\"..p[i]..\"__;\\n\"\n\
		end\n\
		b = b..\"\\n}\"\n\
	end\n\
\n\
	-- check for template\n\
	b = string.gsub(b, \"^{%s*TEMPLATE_BIND\", \"{\\nTOLUA_TEMPLATE_BIND\")\n\
	local t,_,T,I = string.find(b, '^{%s*TOLUA_TEMPLATE_BIND%s*%(+%s*\\\"?([^\\\",]*)\\\"?%s*,%s*([^%)]*)%s*%)+')\n\
	if t then\n\
\n\
		-- remove quotes\n\
		I = string.gsub(I, \"\\\"\", \"\")\n\
		T = string.gsub(T, \"\\\"\", \"\")\n\
		-- get type list\n\
		local types = split_c_tokens(I, \",\")\n\
		-- remove TEMPLATE_BIND line\n\
		local bs = string.gsub(b, \"^{%s*TOLUA_TEMPLATE_BIND[^\\n]*\\n\", \"{\\n\")\n\
			\n\
		local Tl = split(T, \" \")\n\
		local tc = TemplateClass(n, p, bs, Tl)\n\
\n\
		\n\
		tc:throw(types, true)\n\
		--for i=1,types.n do\n\
		--	tc:throw(split_c_tokens(types[i], \" \"), true)\n\
		--end\n\
		return\n\
	end\n\
	\n\
	local mbase\n\
\n\
	if p then\n\
		mbase = table.remove(p, 1)\n\
		if not p[1] then p = nil end\n\
	end\n\
\n\
	mbase = mbase and resolve_template_types(mbase)\n\
\n\
	local c\n\
	local oname = string.gsub(n, \"@.*$\", \"\")\n\
	oname = getnamespace(classContainer.curr)..oname\n\
\n\
	if _global_classes[oname] then\n\
		c = _global_classes[oname]\n\
		if mbase and ((not c.base) or c.base == \"\") then\n\
			c.base = mbase\n\
		end\n\
	else\n\
		c = _Class(_Container{name=n, base=mbase, extra_bases=p})\n\
\n\
		local ft = getnamespace(c.parent)..c.original_name\n\
		append_global_type(ft, c)\n\
	end\n\
\n\
	push(c)\n\
	c:parse(strsub(b,2,strlen(b)-1)) -- eliminate braces\n\
	pop()\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/class.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- mark up comments and strings\n\
STR1 = \"\001\"\n\
STR2 = \"\002\"\n\
STR3 = \"\003\"\n\
STR4 = \"\004\"\n\
REM  = \"\005\"\n\
ANY  = \"([\001-\005])\"\n\
ESC1 = \"\006\"\n\
ESC2 = \"\007\"\n\
\n\
MASK = { -- the substitution order is important\n\
 {ESC1, \"\\'\"},\n\
 {ESC2, '\\\"'},\n\
 {STR1, \"'\"},\n\
 {STR2, '\"'},\n\
 {STR3, \"%[%[\"},\n\
 {STR4, \"%]%]\"},\n\
 {REM , \"%-%-\"},\n\
}\n\
\n\
function mask (s)\n\
 for i = 1,#MASK  do\n\
  s = gsub(s,MASK[i][2],MASK[i][1])\n\
 end\n\
 return s\n\
end\n\
\n\
function unmask (s)\n\
 for i = 1,#MASK  do\n\
  s = gsub(s,MASK[i][1],MASK[i][2])\n\
 end\n\
 return s\n\
end\n\
\n\
function clean (s)\n\
 -- check for compilation error\n\
 local code = \"return function ()\\n\" .. s .. \"\\n end\"\n\
 if not dostring(code) then\n\
  return nil\n\
 end\n\
\n\
 if flags['C'] then\n\
 	return s\n\
 end\n\
\n\
 local S = \"\" -- saved string\n\
\n\
 s = mask(s)\n\
\n\
 -- remove blanks and comments\n\
 while 1 do\n\
  local b,e,d = strfind(s,ANY)\n\
  if b then\n\
   S = S..strsub(s,1,b-1)\n\
   s = strsub(s,b+1)\n\
   if d==STR1 or d==STR2 then\n\
    e = strfind(s,d)\n\
    S = S ..d..strsub(s,1,e)\n\
    s = strsub(s,e+1)\n\
   elseif d==STR3 then\n\
    e = strfind(s,STR4)\n\
    S = S..d..strsub(s,1,e)\n\
    s = strsub(s,e+1)\n\
   elseif d==REM then\n\
    s = gsub(s,\"[^\\n]*(\\n?)\",\"%1\",1)\n\
   end\n\
  else\n\
   S = S..s\n\
   break\n\
  end\n\
 end\n\
 -- eliminate unecessary spaces\n\
 S = gsub(S,\"[ \\t]+\",\" \")\n\
 S = gsub(S,\"[ \\t]*\\n[ \\t]*\",\"\\n\")\n\
	S = gsub(S,\"\\n+\",\"\\n\")\n\
 S = unmask(S)\n\
 return S\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/clean.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
-- Generate binding code\n\
-- Written by Waldemar Celes\n\
-- TeCGraf/PUC-Rio\n\
-- Jul 1998\n\
-- Last update: Apr 2003\n\
-- $Id: $\n\
\n\
\n\
-- This code is free software; you can redistribute it and/or modify it.\n\
-- The software provided hereunder is on an \"as is\" basis, and\n\
-- the author has no obligation to provide maintenance, support, updates,\n\
-- enhancements, or modifications.\n\
\n\
function parse_extra()\n\
\n\
	for k,v in ipairs(_extra_parameters or {}) do\n\
		\n\
		local b,e,name,value = string.find(v, \"^([^=]*)=(.*)$\")\n\
		if b then\n\
			_extra_parameters[name] = value\n\
		else\n\
			_extra_parameters[v] = true\n\
		end\n\
	end\n\
end\n\
\n\
function doit ()\n\
	-- define package name, if not provided\n\
	if not flags.n then\n\
		if flags.f then\n\
			flags.n = gsub(flags.f,\"%..*$\",\"\")\n\
			print (string.find(flags.n, \"([^/\\\\]*)$\"))\n\
			_,_,flags.n = string.find(flags.n, \"([^/\\\\]*)$\")\n\
		else\n\
			error(\"#no package name nor input file provided\")\n\
		end\n\
	end\n\
\n\
	print (flags['L'])\n\
	-- parse table with extra paramters\n\
	parse_extra()\n\
\n\
	-- do this after setting the package name\n\
	if flags['L'] then\n\
		dofile(flags['L'])\n\
	end\n\
\n\
	-- add cppstring\n\
	if not flags['S'] then\n\
		_basic['string'] = 'cppstring'\n\
		_basic['std::string'] = 'cppstring'\n\
		_basic_ctype.cppstring = 'const char*'\n\
	end\n\
\n\
	-- proccess package\n\
	local p  = Package(flags.n,flags.f)\n\
\n\
	if flags.p then\n\
		return        -- only parse\n\
	end\n\
\n\
	if flags.o then\n\
		local st,msg = writeto(flags.o)\n\
		if not st then\n\
			error('#'..msg)\n\
		end\n\
	end\n\
\n\
	p:decltype()\n\
	if flags.P then\n\
		p:print()\n\
	else\n\
		push(p)\n\
		pre_output_hook(p)\n\
		pop()\n\
		p:preamble()\n\
		p:supcode()\n\
		push(p)\n\
		pre_register_hook(p)\n\
		pop()\n\
		p:register()\n\
		push(p)\n\
		post_output_hook(p)\n\
		pop()\n\
	end\n\
\n\
	if flags.o then\n\
		writeto()\n\
	end\n\
\n\
	-- write header file\n\
	if not flags.P then\n\
		if flags.H then\n\
			local st,msg = writeto(flags.H)\n\
			if not st then\n\
				error('#'..msg)\n\
			end\n\
			p:header()\n\
			writeto()\n\
		end\n\
	end\n\
end\n\
";
   int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua embedded: src/bin/lua/doit.lua");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */


  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = "\n\
local err,msg = pcall(doit)\n\
if not err then\n\
   local _,_,label,msg = strfind(msg,\"(.-:.-:%s*)(.*)\")\n\
   tolua_error(msg,label)\n\
   print(debug.traceback())\n\
end\n\n\
";
	int error = tolua_dobuffer(tolua_S,(char*)B,strlen(B),"tolua: embedded Lua code 23");
	if (0 != error)
	{
		printf("%s", lua_tostring(tolua_S, -1));
	}

	lua_settop(tolua_S, top);
  } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_tolua (lua_State* tolua_S) {
 return tolua_tolua_open(tolua_S);
};
#endif

