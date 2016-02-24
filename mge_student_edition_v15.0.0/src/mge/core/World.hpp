#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/util/Audio.hpp"

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
        bool IsRunning;
        void renderDebugInfo();
        bool isRunning;

	private:
        World();
	    Camera* _mainCamera;

	    static World* worldInstance;
};


#endif // WORLD_H
