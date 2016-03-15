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

    /**
    for(int i = 0; i < InventoryList.size(); i++)
    {
        myfile << SavePuzzle[i].sPuzzleName << " = \n";

        myfile << "PuzzleName = " << SavePuzzle[i].sPuzzleName << " = \n";

        for(int j = 0; j < SavePuzzle[i].sPuzzleList[j]; j++)
        {
            myfile << "PuzzlePieces = \n {";
            myfile << "sGameObjectID = " << "'" << sGameObjectID << "' \n";
            myfile << "sStartPosition = "<< "'"sStartPosition.x<<"," << sStartPosition.y<< "," << sStartPosition.z <<"' \n";
            myfile << "sEndPosition = "<< "'"sEndPosition.x<<"," << sEndPosition.y<< "," << sEndPosition.z <<"' \n";
            myfile << "}";
        }

        myfile << "isComplete = " << SavePuzzle[i].sComplete;
    }
    /**

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
    /**
    std::vector<std::string> saveGameStingList;
  std::string line;
	std::ifstream myfile ("mge/lua/SaveGames.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          //std::cout << line << '\n';
        }
        myfile.close();
      }

    std::string s = line;
    std::string delimiter = "=>";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        //std::cout << token << std::endl;
        saveGameStingList.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    saveGameStingList.push_back(s);
    //std::cout << saveGameStingList.size() << std::endl;

    std::vector<std::string> SaveString;

    for(int i =0; i< saveGameStingList.size(); i++)
    {
        std::string s = saveGameStingList[i];
        std::string delimiter = "=";
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
        }
        SaveString.push_back(s);
    }

    std::string saveGameName = SaveString[0];
    float x = std::stof(SaveString[1]);
    float y = std::stof(SaveString[2]) - 3;
    float z = std::stof(SaveString[3]);

    return glm::vec3(x,y,z);
    **/
    lua_State * lua = luaL_newstate();
    luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/SaveGames.lua");
	lua_call(lua,0,0);
    lua_getglobal(lua,"SaveName");
    std::string SaveName = lua_tostring(lua,lua_gettop( lua ));
    lua_getglobal(lua,"X");
    int x = lua_tonumber(lua,lua_gettop( lua ));
    lua_getglobal(lua,"Y");
    int y = lua_tonumber(lua,lua_gettop( lua ));
    lua_getglobal(lua,"Z");
    int z = lua_tonumber(lua,lua_gettop( lua ));

    return glm::vec3(x,y-3,z);
}

PlayerProgress::~PlayerProgress()
{
    //dtor

}
