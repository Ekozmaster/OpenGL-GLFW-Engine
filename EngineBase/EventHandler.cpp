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
    glfwSetMouseButtonCallback(mainWindow->glfwInstance, MouseButtonPressCallback);

    glfwSetCursorPosCallback(mainWindow->glfwInstance, MouseMotionCallback);
}

void EventHandler::KeyPressCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    Input::Instance()->UpdateKeysState(window, key, scancode, action, mods);
};

void EventHandler::MouseButtonPressCallback(GLFWwindow *window, int button, int action, int mods){
    Input::Instance()->UpdateKeysState(window, button, 0, action, mods);
};

void EventHandler::WindowShouldCloseCallback(GLFWwindow *window){
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void EventHandler::MouseMotionCallback(GLFWwindow *window, double xPos, double yPos){
    Input::Instance()->UpdateMouseMotion(window, xPos, yPos);
}
