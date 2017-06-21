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

class WindowDrawer {
    public:
        int *Width;
        int *Height;
        GameObject *mainCamera;
        GLint shaderProgram;

        WindowDrawer();
        WindowDrawer(int *width, int *height, GameObject * camera);
        void InitX11OpenGL();
        void ClearScreen();
        void RenderFrame(GLFWwindow *window);
        void SetupViewMatrix();
        void CamPose(Vector3 eyePose, Vector3 refPose, Vector3 upPose);
};

#endif
