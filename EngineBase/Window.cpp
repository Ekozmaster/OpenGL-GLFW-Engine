#include"Window.hpp"
#include<string.h>
#include<GLFW/glfw3.h>

WindowObject::WindowObject(int width, int height){
    Width = width;
    Height = height;
    //Input::Instance()->SetScreenSize(Vector3(Width, Height,0));
    windowDrawer = WindowDrawer(&Width, &Height);
};

void WindowObject::InstantiateGLFWWindow(){
    glfwInstance = glfwCreateWindow(Width, Height, "GLFW/OpenGL Window", NULL, NULL);
    if(!glfwInstance){
        printf("Null GLFW Window!\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(glfwInstance);
    glewInit();
    windowDrawer.InitX11OpenGL();
}

void WindowObject::MainFrame(){
    windowDrawer.RenderFrame(glfwInstance);
};

void WindowObject::SetRenderingCamera(GameObject *camera){
    windowDrawer.mainCamera = camera;
}


