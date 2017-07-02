#ifndef MESHRENDERER_HPP
#define MESHRENDERER_HPP

#include<GL/gl.h>
#include"Behaviour.hpp"
#include"Mesh.hpp"

class MeshRenderer : public Behaviour {
    public:
        GLuint vao;
        GLuint vbo;
        GLuint elementsIdx;
        Mesh *mesh;

        void Render();
        void UpdateMeshProperties();
};

#endif
