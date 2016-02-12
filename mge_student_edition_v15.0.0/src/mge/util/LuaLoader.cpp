#include "LuaLoader.hpp"
#include "mge/config.hpp"
#include "luainc.h"
#include <iostream>
#include <string>
LuaLoader::LuaLoader(std::string pName) : GameObject(pName)
{
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	int status = luaL_dofile(lua,"mge/lua/TestLua.lua");
	lua_close(lua);
	std::cout << status << std::endl;
    //config::MGE_LUA_PATH
    //ctor


}

LuaLoader::~LuaLoader()
{
    //dtor
}
