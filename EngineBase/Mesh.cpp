#include"Mesh.hpp"
#include<stdlib.h>

Mesh::Mesh(){

}

GLfloat *Mesh::GetGLfloatArray(){
    vertexCount = 36;
    triangleCount = 36;
    GLfloat *result = (GLfloat*)malloc(sizeof(GLfloat) * vertexCount * 6);
    int counter=0;
    for(int i=0; i<vertexCount; i++){
        result[counter]   = vertices[i].x;
        result[counter+1] = vertices[i].y;
        result[counter+2] = vertices[i].z;
        result[counter+3] = normals[i].x;
        result[counter+4] = normals[i].y;
        result[counter+5] = normals[i].z;
        counter+=6;
    }
    return result;
};
