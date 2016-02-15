#ifndef RAYCAST_H
#define RAYCAST_H

#include <glm.hpp>
#include "Mesh.hpp"


class Raycast
{
    public:
        /**
         * Check Ray Intersection of a Triangle
        */
        static bool Ray_Intersect_Triangle(glm::vec3 pStartPoint, glm::vec3 pSlopeLine, glm::vec3 pVertice0, glm::vec3 pVertice1, glm::vec3 pVertice2, bool pExtend_To_Infinity, bool pCull_Backfaces);
        /**
         * Go through all the triangles of a Mesh and check Ray Intersection of each Triangle
         */
        static bool Ray_Intersect_Mesh(Mesh* pMesh, glm::vec3 pStartPoint, glm::vec3 pSlopeLine, bool pExtend_To_Infinity, bool pCull_Backfaces);
    protected:
    private:
};

#endif // RAYCAST_H
