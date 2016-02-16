#include "LuaLoader.hpp"
#include "mge/config.hpp"
#include "luainc.h"
#include <iostream>
#include <string>
#include "mge/core/Mesh.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"

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

/*
void LuaLoader::AssetLoader(World& pWorld){
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/AssetLoader.lua");

	lua_register(lua, "AddModel", AddModel);

	lua_call(lua,0,0);
	lua_close(lua);
	std::cout << ""  << std::endl;


}

private void LuaLoader::AddModel(std::string pModel, std::string pTexture)
{
    Mesh* MockUpCube = Mesh::load(config::MGE_MODEL_PATH+"mockup.obj");
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load (config::MGE_TEXTURE_PATH+"bricks.jpg"));

    GameObject* Room = new GameObject ("mockup", glm::vec3(0,0,0));
    Room->setMesh (MockUpCube);
    Room->setMaterial(textureMaterial);

    pWorld.add(Room);

}
*/


LuaLoader::~LuaLoader()
{
    //dtor
}
