#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>
#include <iostream>
#include <glm.hpp>
#include "mge/core/GameObject.hpp"
#include <BulletDynamics/Dynamics/btRigidBody.h>

class AbstractCollider;
class AbstractBehaviour;
class AbstractMaterial;
class World;
class Mesh;

/**
 * A GameObject wraps all data required to display an (interactive / dynamic) object, but knows nothing about OpenGL or rendering.
 * GameObject exposes both local and world transform and shows one way of how you can cache the worldtransform.
 * A nice addition for you as a student would be for example to try and add an inversetransform and inverseworldtransform (also cached).
 *
 * You will need to alter this class to add colliders etc.
 */
class GameObject
{
	public:
		GameObject(std::string pName = NULL, glm::vec3 pPosition = glm::vec3( 0.0f, 0.0f, 0.0f ), bool pIsInteractive = false);

		virtual ~GameObject();

        void setName (std::string pName);
        std::string getName() const;

        bool IsInteractive();

        //contains local rotation, scale, position
		void setTransform (const glm::mat4& pTransform);
        glm::mat4& getTransform();

        //access just the local position
		void setLocalPosition (glm::vec3 pPosition);
		glm::vec3 getLocalPosition();

        //get the objects world position by combining transforms
		glm::vec3 getWorldPosition();
		virtual glm::mat4& getWorldTransform();

        //change local position, rotation, scaling
		void translate(glm::vec3 pTranslation);
		void rotate(float pAngle, glm::vec3 pAxis);
		void scale(glm::vec3 pScale);

        //mesh and material should be shared as much as possible
		void setMesh(Mesh* pMesh);
		Mesh* getMesh() const;

		void setMaterial (AbstractMaterial* pMaterial);
		AbstractMaterial* getMaterial() const;

        //behaviour will probably be a unique instance per gameobject
		void setBehaviour(AbstractBehaviour* pBehaviour);
		AbstractBehaviour* getBehaviour() const;

		virtual void update(float pStep, const glm::mat4& pParentTransform);

        //child management

        //shortcut to set the parent of pChild to ourselves
		void add (GameObject* pChild);
		//shortcut to set the parent of pChild to NULL
		void remove (GameObject* pChild);

		virtual void setParent (GameObject* pGameObject);
		GameObject* getParent();

        int getChildCount();
        GameObject* getChildAt (int pIndex);

        btRigidBody *RigidBody;
        glm::mat4 TransformToPlace;

        //Info For Rigid Body
        float GOSizeX;
        float GOSizeY;
        float GOSizeZ;
        glm::vec4 GORotation;
        glm::vec3 GOPositionToPlace;


        //puzzle stuff
        int IsPainting;
        std::string puzzleNameString;

	protected:
		std::string _name;
		glm::mat4 _transform;
		glm::mat4 _worldTransform;

        GameObject* _parent;
		std::vector<GameObject*> _children;

        Mesh* _mesh;
		AbstractBehaviour* _behaviour;
		AbstractMaterial* _material;
		World* _world;

        //update children list administration
        void _innerAdd (GameObject* pChild);
		void _innerRemove (GameObject* pChild);
    private:
        bool Interactive;
};

#endif // GAMEOBJECT_H
