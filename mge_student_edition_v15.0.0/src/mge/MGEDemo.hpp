#ifndef MGEDEMO_H
#define MGEDEMO_H

#include <mge/core/AbstractGame.hpp>
#include <SFML/Graphics.hpp>
//#include "Mesh.hpp"
#include <vector>

#include "mge/PlayerProgress.h"
#include "mge/core/Camera.hpp"


class Swapper;
class GameObject;
class DebugHud;

class MGEDemo: public AbstractGame
{
    //PUBLIC FUNCTIONS

	public:
		MGEDemo();
		virtual ~MGEDemo();

        virtual void initialize();

	protected:
        virtual void _initializeScene();

	    //override render to render the hud as well.
	    virtual void _render();

	private:
		DebugHud* _hud;                   //hud display
		bool _fredActive = false;
		//std::vector<Mesh> * AssetList;

		PlayerProgress * _playerProgress;
		Camera* _camera;

        void _updateHud();
};

#endif // MGEDEMO_H
