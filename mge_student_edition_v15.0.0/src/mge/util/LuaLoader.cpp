#include "LuaLoader.hpp"
#include "mge/config.hpp"
#include "luainc.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/core/World.hpp"

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

int AddModel(lua_State * lua)
{
    std::string IDname;
    std::string Model;
    std::string Texture;
    std::string sPosition;
    glm::vec3 vPosition;


    if (lua_isstring(lua, -4)) {
		IDname = lua_tostring(lua, -4);
		std::cout << IDname << std::endl;
	}
    if (lua_isstring(lua, -3)) {
		Model = lua_tostring(lua, -3);
		std::cout << Model << std::endl;
	}
	if (lua_isstring(lua, -2)) {
		Texture= lua_tostring(lua, -2);
		std::cout << Texture << std::endl;
	}
	if (lua_isstring(lua, -1)) {
		sPosition = lua_tostring(lua, -1);
		std::istringstream ss(sPosition);
		std::string number;
		int index = 0;
		while(std::getline(ss, number, ','))
        {
            switch(index)
            {
            case 0:
                vPosition.x = atoi(number.c_str());
                break;
            case 1:
                vPosition.y = atoi(number.c_str());
                break;
            case 2:
                vPosition.z = atoi(number.c_str());
                break;
            default:
                break;
            }
            if(index >= 2) break;
            index++;

        }
		std::cout << sPosition << std::endl;
	}

    Mesh* mesh = Mesh::load("mge/models/"+Model);
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/"+Texture));

    GameObject* GO = new GameObject (IDname, vPosition);
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);
    World::GetInstance()->MeshList.push_back(*mesh);
}


void LuaLoader::LoadAllModels(){

    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/AssetLoader.lua");

    lua_pushcfunction(lua, AddModel);
    lua_setglobal(lua, "AddModel");

	lua_call(lua,0,0);
	lua_close(lua);
}




LuaLoader::~LuaLoader()
{
    //dtor
}
