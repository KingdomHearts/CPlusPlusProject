#ifndef LUALOADER_H
#define LUALOADER_H
#include <string>
#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/core/GameObject.hpp"

class LuaLoader : public GameObject
{
    public:
        LuaLoader(std::string pName = "Lua", std::string pLuaFileName = ".lua");
        void LoadAllModels();
        virtual ~LuaLoader();
    protected:
    private:

};

#endif // LUALOADER_H
