#ifndef LUALOADER_H
#define LUALOADER_H
#include <string>
#include "mge/core/GameObject.hpp"

class LuaLoader : public GameObject
{
    public:
        LuaLoader(std::string pName = "Lua");
        virtual ~LuaLoader();
    protected:
    private:
};

#endif // LUALOADER_H
