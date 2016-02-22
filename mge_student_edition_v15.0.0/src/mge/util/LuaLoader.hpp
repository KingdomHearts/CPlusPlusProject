#ifndef LUALOADER_H
#define LUALOADER_H
#include <string>
#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "luainc.h"

class LuaLoader : public GameObject
{
    public:
        LuaLoader(std::string pName = "Lua", std::string pLuaFileName = ".lua");
        void LoadAllModels();
        void LoadSounds();
        void RuntimeLoader();
        void RuntimeUpdater();
        virtual ~LuaLoader();
    protected:
    private:
        lua_State* lua;

};

#endif // LUALOADER_H
