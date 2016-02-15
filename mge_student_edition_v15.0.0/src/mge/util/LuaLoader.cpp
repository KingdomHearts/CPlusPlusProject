#include "LuaLoader.hpp"
#include "mge/config.hpp"
#include "luainc.h"
#include <iostream>
#include <string>
LuaLoader::LuaLoader(std::string pName,std::string pLuaFileName) : GameObject(pName)
{
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/TestLua.lua");
	lua_call(lua,0,0);
	lua_close(lua);
	std::cout << ""  << std::endl;
    //config::MGE_LUA_PATH
    //ctor
}

LuaLoader::~LuaLoader()
{
    //dtor
}
