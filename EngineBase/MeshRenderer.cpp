#include"MeshRenderer.hpp"

void MeshRenderer::Render(){
    glBindVertexArray(vao);
    //glVertexPointer(3, GL_FLOAT, 24, (void*)0);

    glDrawElements(GL_TRIANGLES, mesh->triangleCount, GL_UNSIGNED_INT, (void*)0);
};

void MeshRenderer::UpdateMeshProperties(){
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLfloat *vertices = mesh->GetGLfloatArray();
    GLuint *triangles = (GLuint*)mesh->triangles;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->vertexCount * 6, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &elementsIdx);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementsIdx);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * mesh->triangleCount, triangles, GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

};
