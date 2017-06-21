#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>
#include<GL/glext.h>
#include<GLFW/glfw3.h>
#include<unistd.h>

#include"essentials.hpp"

int main(int argc, char *argv[]) {
    Application *app = new Application();
    app->Init();

    //GLFWwindow *window;
    //window = glfwCreateWindow(720, 480, "HUEHEU", NULL, NULL);
    while(1) {
        app->MainLoop();

    }
    return 0;
}
