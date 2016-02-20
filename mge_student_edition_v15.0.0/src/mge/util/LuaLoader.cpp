#include "LuaLoader.hpp"
#include "mge/config.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/core/World.hpp"

#include "mge/core/AbstractGame.hpp"

#include "mge/util/Audio.hpp"

LuaLoader::LuaLoader(std::string pName,std::string pLuaFileName) : GameObject(pName)
{
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/TestLua.lua");
	lua_call(lua,0,0);
	lua_close(lua);
	std::cout << ""  << std::endl;
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


    if (lua_isstring(lua, -19)) {
		IDname = lua_tostring(lua, -19);
		std::cout << IDname  << std::endl;
	}
    if (lua_isstring(lua, -18)) {
		Model = lua_tostring(lua, -18);
	}
	if (lua_isstring(lua, -17)) {
		Texture= lua_tostring(lua, -17);
	}
	float m[16];
	for (int i=0; i<16; i++) {
        m[i] = lua_tonumber(lua, -((15-i)+1));
	}

    Mesh* mesh = Mesh::load("mge/models/"+Model);
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/bricks.jpg"));
    if(Texture != ""){
        textureMaterial = new TextureMaterial (Texture::load ("mge/textures/"+Texture));
    }
    GameObject* GO = new GameObject (IDname, glm::vec3(0,0,0));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);
    World::GetInstance()->MeshList.push_back(*mesh);


    GO->translate(vPosition);
    GO->rotate(glm::radians(-fRotation), glm::vec3(0,1,0));

    glm::mat4 matrix(m[0],  m[4],  m[8],  m[12],
                     m[1],  m[5],  m[9],  m[13],
                     m[2],  m[6],  m[10], m[14],
                     m[3],  m[7],  m[11], m[15]);

    matrix = glm::transpose(matrix);
    matrix[0][0] *= -1;
    matrix[1][0] *= -1;
    matrix[2][0] *= -1;
    matrix[3][0] *= -1;
    GO->setTransform(matrix);

    std::cout << World::GetInstance()->MeshList.size() << std::endl;
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

int AddSound(lua_State * lua)
{

    AudioStruct * sAudio = new AudioStruct();
    sAudio->sObject = lua_tostring(lua,-1);
    sAudio->sSetAttenuation = lua_tonumber(lua,-2);
    sAudio->sMinDistance = lua_tonumber(lua,-3);
    sAudio->sIs3D = lua_toboolean(lua,-4);
    sAudio->sSetVolume = lua_tonumber(lua,-5);
    sAudio->sTrigger = lua_tostring(lua,-6);
    sAudio->sLayer = lua_tonumber(lua,-7);
    sAudio->sLoop = lua_toboolean(lua,-8);
    sAudio->sFileName = lua_tostring(lua,-9);
    sAudio->sID = lua_tostring(lua,-10);
    World::GetInstance()->AudioList.push_back(*sAudio);
    return 0;
}

void LuaLoader::LoadSounds()
{
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/SoundLoader.lua");

    lua_pushcfunction(lua, AddSound);
    lua_setglobal(lua, "AddSound");

	lua_call(lua,0,0);
	lua_close(lua);
}

int Print(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
}

void LuaLoader::RuntimeUpdater()
{
    std::cout << "test2" << std::endl;
	//luaL_loadfile(lua,"mge/lua/Runtime.lua");
    lua_getglobal(lua, "update");
	lua_call(lua,0,0);
    std::cout << "test3" << std::endl;
	//lua_close(lua);
	//lua_call(lua,0,0);
}

void LuaLoader::RuntimeLoader()
{
    lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/Runtime.lua");

    lua_register(lua,"Print",Print);
	lua_call(lua,0,0);

	//lua_close(lua);
    std::cout << "test1" << std::endl;
}


LuaLoader::~LuaLoader()
{
    //dtor
}
