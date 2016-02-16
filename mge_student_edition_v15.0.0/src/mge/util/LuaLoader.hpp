#ifndef LUALOADER_H
#define LUALOADER_H
#include <string>
#include "mge/core/GameObject.hpp"

class LuaLoader : public GameObject
{
    public:
        LuaLoader(std::string pName = "Lua", std::string pLuaFileName = ".lua");
        virtual ~LuaLoader();
    protected:
    private:
        //void AddModel();
};

#endif // LUALOADER_H
