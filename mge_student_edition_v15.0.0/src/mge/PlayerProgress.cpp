#include "PlayerProgress.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <fstream>
#include "luainc.h"

PlayerProgress* PlayerProgress::PlayerProgressInstance = NULL;
PlayerProgress::PlayerProgress()
{
    //ctor
}


PlayerProgress* PlayerProgress::GetInstance()
{
    if (PlayerProgress::PlayerProgressInstance == NULL)
        PlayerProgress::PlayerProgressInstance = new PlayerProgress();

    return PlayerProgress::PlayerProgressInstance;
}

void PlayerProgress::SaveGame()
{
    std::vector<InventoryObject> InventoryListProgress = Inventory::GetInstance()->InventoryList;
    /**
    std::ofstream myfile;
    myfile.open ("mge/lua/SaveGames.txt");
    myfile << "SaveName=" << pSaveName;
    myfile << "=>X=" << pPosition.x;
    myfile << "=>Y=" << pPosition.y;
    myfile << "=>Z=" << pPosition.z;
    **/
    std::ofstream myfile;
    myfile.open("mge/lua/SaveGames.lua");
    //std::cout << SaveName << std::endl;
    myfile << "SaveName = " <<"'" << SaveName << "'" << "\n";
    myfile << "X = " << Position.x << "\n";
    myfile << "Y = " << Position.y << "\n";
    myfile << "Z = " << Position.z << "\n";

/**
    for(int i = 0; i < SavePuzzle.size(); i++)
    {
        myfile << SavePuzzle[i].sPuzzleName << " = \n";

        myfile << "PuzzleName = " << SavePuzzle[i].sPuzzleName << " = \n";

        for(int j = 0; j < SavePuzzle[i].sPuzzleList.size(); j++)
        {
            myfile << "PuzzlePieces = \n {";
            myfile << "sGameObjectID = " << "'" << SavePuzzle[i].sPuzzleList[j].sGameObjectID << "' \n";
            myfile << "sStartPosition = "<< "'" << SavePuzzle[i].sPuzzleList[j].sStartPosition.x <<"," << SavePuzzle[i].sPuzzleList[j].sStartPosition.y << "," << SavePuzzle[i].sPuzzleList[j].sStartPosition.z <<"' \n";
            myfile << "sEndPosition = "<< "'" << SavePuzzle[i].sPuzzleList[j].sEndPosition.x <<"," << SavePuzzle[i].sPuzzleList[j].sEndPosition.y << "," << SavePuzzle[i].sPuzzleList[j].sEndPosition.z <<"' \n";
            myfile << "}";
        }

        myfile << "isComplete = " << SavePuzzle[i].sComplete;
    }
**/

    myfile << "CompletedGameObjects = \n{\n";
    for(int i = 0; i < gameObjectName.size();i++)
    {
        myfile << gameObjectName[i] << "',\n";
    }
    myfile << "}";

    myfile << "Inventory = \n{\n";
    //myfile << "items = \n{\n";
    for(int i = 0; i < InventoryListProgress.size(); i++)
    {
        myfile <</** "GameObjectName = " <</**/ "'" << InventoryListProgress[i].GO->getName() << "'," << "\n";

        std::cout << "testInventory" << std::endl;
        }
    //myfile << "}\n";
    myfile << "}";
    /** Example

level1 =
{
  music = "music1",

  items =
  {
    A = 1,
    B = 2,

    {
      c = "C",
    }
  }
}

    /**/
}


glm::vec3 PlayerProgress::LoadGame()
{
    lua_State * lua = luaL_newstate();
    luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/SaveGames.lua");
	lua_call(lua,0,0);
    lua_getglobal(lua,"SaveName");
    lua_getglobal(lua,"X");
    int x = lua_tonumber(lua,lua_gettop( lua ));
    lua_getglobal(lua,"Y");
    int y = lua_tonumber(lua,lua_gettop( lua ));
    lua_getglobal(lua,"Z");
    int z = lua_tonumber(lua,lua_gettop( lua ));


    lua_getglobal(lua,"CompletedGameObjects");

    lua_pushnil(lua);

    std::vector<std::string> CompletedGameObjectsList;
    while(lua_next(lua, -2) != 0)
    {
        std::string puzzle;
        if(lua_isstring(lua, -1))
        {
            puzzle = lua_tostring(lua,-1);
            CompletedGameObjectsList.push_back(puzzle);
        }
        lua_pop(lua, 1);
    }

    for(int i = 0; i < CompletedGameObjectsList.size();i++)
    {
        Inventory::GetInstance()->PlaceObjectInInventory(CompletedGameObjectsList[i]);
        Inventory::GetInstance()->PlaceObjectInWorld(CompletedGameObjectsList[i]);
    }

    lua_getglobal(lua,"Inventory");

    lua_pushnil(lua);

    std::vector<std::string> inventoryStringList;
    while(lua_next(lua, -2) != 0)
    {
        std::string gameObject;
        if(lua_isstring(lua, -1))
        {
            gameObject = lua_tostring(lua,-1);
            inventoryStringList.push_back(gameObject);
        }
        lua_pop(lua, 1);
    }

    for(int i =0;i < inventoryStringList.size();i++)
    {
        Inventory::GetInstance()->PlaceObjectInInventory(inventoryStringList[i]);
    }

    return glm::vec3(x,y,z);
}

PlayerProgress::~PlayerProgress()
{
    //dtor

}
