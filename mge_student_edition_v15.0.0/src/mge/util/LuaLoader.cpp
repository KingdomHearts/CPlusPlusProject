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
    std::string sRotation;
    float fRotation;


    if (lua_isstring(lua, -5)) {
		IDname = lua_tostring(lua, -5);
		std::cout << IDname  << std::endl;
	}
    if (lua_isstring(lua, -4)) {
		Model = lua_tostring(lua, -4);
	}
	if (lua_isstring(lua, -3)) {
		Texture= lua_tostring(lua, -3);
	}
	if (lua_isstring(lua, -2)) {
		sPosition = lua_tostring(lua, -2);
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
	}
	if (lua_isstring(lua, -1)) {
		sRotation = lua_tostring(lua, -1);
		fRotation = std::stof(sRotation);
	}

    Mesh* mesh = Mesh::load("mge/models/"+Model);
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/"+Texture));

    GameObject* GO = new GameObject (IDname, vPosition);
    GO->rotate(glm::radians(fRotation), glm::vec3(0,1,0));
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
