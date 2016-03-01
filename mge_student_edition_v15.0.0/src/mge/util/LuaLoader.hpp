#ifndef LUALOADER_H
#define LUALOADER_H
#include <string>
#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "luainc.h"
#include "mge/util/Audio.hpp"

struct DialogStruct
{
    int sDialogNumber;
    std::string sText;
    int sScreenTime;
};

class LuaLoader : public GameObject
{
    public:
        LuaLoader(std::string pName = "Lua", std::string pLuaFileName = ".lua");
        void LoadAllModels();
        void LoadAllInteractiveModels();
        void LoadSounds();
        void LoadAllDialogs();
        void RuntimeLoader();
        void RuntimeUpdater();
        void SetNewState(std::string pNewState);
        void SetTime(int pTime);
        void KeyPressed(std::string pPressedKey);
        virtual ~LuaLoader();
    protected:
    private:
        lua_State* lua;
};

#endif // LUALOADER_H
