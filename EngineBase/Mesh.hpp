#ifndef MESH_HPP
#define MESH_HPP

#include<GL/gl.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"CubeTest.hpp"

class Mesh : Behaviour {
    public:
        Mesh();
        void Setup();
        GLfloat *GetGLfloatArray();

        Vector3 *vertices;
        Vector3 *normals;
        unsigned int *triangles;
        int vertexCount;
        int triangleCount;

};

#endif
