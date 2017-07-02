#ifndef WINDOWDRAWER_HPP
#define WINDOWDRAWER_HPP
/*
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>
#include<X11/X.h>
#include<X11/Xlib.h>
*/
#include<GLFW/glfw3.h>
#include"Vector3.hpp"
#include"GameObject.hpp"
#include"Camera.hpp"
#include"MeshRenderer.hpp"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
//#include<glm/gtc/quaternion.hpp>

class WindowDrawer {
    public:
        int *Width;
        int *Height;
        GameObject *mainCamera;
        GLint shaderProgram;
        glm::mat4 projMatrix;
        glm::mat4 modelMatrix;
        glm::mat4 transformMatrix;
        GLuint vao, vbo, elementBuffer;
        MeshRenderer meshRend;

        GLchar *vertexSource;
        GLchar *fragmentSource;

        WindowDrawer();
        WindowDrawer(int *width, int *height);
        void InitX11OpenGL();
        void ClearScreen();
        void RenderFrame(GLFWwindow *window);
        void SetupViewMatrix();
        void CamPose(Camera *cam);
};

#endif
