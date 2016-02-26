#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/util/Audio.hpp"
#include "mge/util/LuaLoader.hpp"

class Light;
class Camera;

class World : public GameObject
{
	public:

        static World* GetInstance();
		void setMainCamera (Camera* pCamera);
		Camera* getMainCamera();
        std::vector<Mesh> MeshList;
        std::vector<AudioStruct> AudioList;

        std::vector<DialogStruct> * dialogList = new std::vector<DialogStruct>();
        std::vector<int> waitTimesList;
        std::vector<int> DialogNumberList;
        bool startTimer = false;
        int maxTime = 0;
        std::string state;
        std::string nextState;
        std::string displayText;

        bool IsRunning;
        void renderDebugInfo();
        bool isRunning;

	private:
        World();
	    Camera* _mainCamera;

	    static World* worldInstance;
};


#endif // WORLD_H
