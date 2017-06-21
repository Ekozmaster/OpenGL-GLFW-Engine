#include"EventHandler.hpp"
#include<cstdio>
#include<GLFW/glfw3.h>

EventHandler::EventHandler(WindowObject *mW){
    mainWindow = mW;
}

EventHandler::EventHandler(){
}

void EventHandler::RegisterCallbacks(){
    glfwSetKeyCallback(mainWindow->glfwInstance, KeyPressCallback);
    glfwSetWindowCloseCallback(mainWindow->glfwInstance, WindowShouldCloseCallback);
}
/*
void EventHandler::RouteXEvents(XEvent *event, Display *dpy){
    if(event->type == Expose){
        //windowDrawer.RenderFrame();
    } else if(event->type == KeyPress || event->type == KeyRelease){
        Input::Instance()->UpdateKeysState(event, dpy);
    } else if(event->type == MotionNotify){
        Input::Instance()->UpdateMouseMotion(event, dpy);
    } else if(event->type == ButtonPress || event->type == ButtonRelease){
        Input::Instance()->UpdateMouseButtons(event, dpy);
    }
};
//*/
void EventHandler::KeyPressCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    Input::Instance()->UpdateKeysState(window, key, scancode, action, mods);
};

void EventHandler::WindowShouldCloseCallback(GLFWwindow *window){
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
