#ifndef MGEDEMO_H
#define MGEDEMO_H

#include <mge/core/AbstractGame.hpp>
#include <SFML/Graphics.hpp>
//#include "Mesh.hpp"
#include <vector>

#include <BulletCollision\BroadphaseCollision\btBroadphaseInterface.h>
#include <BulletCollision\CollisionDispatch\btDefaultCollisionConfiguration.h>
#include <BulletCollision\CollisionDispatch\btCollisionDispatcher.h>
#include <BulletDynamics\ConstraintSolver\btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics\Dynamics\btDiscreteDynamicsWorld.h>
#include <BulletCollision\BroadphaseCollision\btDbvtBroadphase.h>

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
		//std::vector<Mesh> * AssetList;


        void _updateHud();
};

#endif // MGEDEMO_H
