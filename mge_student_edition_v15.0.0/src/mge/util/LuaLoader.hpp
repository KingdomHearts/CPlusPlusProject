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
        static LuaLoader* GetInstance();
        void LoadAllModels();
        void LoadAllInteractiveModels();
        void LoadAllTiggers();
        void LoadSounds();
        void LoadAllDialogs();
        void RuntimeLoader();
        void RuntimeUpdater();
        void SetNewState(std::string pNewState);
        void SetTime(int pTime);
        void SetTrigger(std::string pTriggerName);
        void SetCompletedPuzzle(std::string pCompletedPuzzleName);
        void KeyPressed(std::string pPressedKey);
        virtual ~LuaLoader();
    protected:
    private:
        LuaLoader();
        lua_State* lua;
        static LuaLoader* LuaLoaderInstance;
};

#endif // LUALOADER_H
