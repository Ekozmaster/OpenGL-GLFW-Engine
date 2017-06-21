#include"Application.hpp"
#include<stdlib.h>
#include<GLFW/glfw3.h>

Application::Application(){

}

void Application::Init(){
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    sceneManager = *(new SceneManager());
    sceneManager.CreateNewScene();
    if(!glfwInit()){
        exit(EXIT_FAILURE);
    }
    SetupSystem();
}

void Application::SetupSystem(){
    Input::Instance()->InitKeysStatePointer();
    Input::Instance()->SetScreenSize(Vector3(defaultWidth, defaultHeight, 0));
    LoadApplicationDefaultWindows();
    eventHandler = EventHandler(windows.head->data);
    eventHandler.RegisterCallbacks();

    //glfwSetKeyCallback(windows.head->data);
}

void Application::LoadApplicationDefaultWindows(){
    WindowObject *defaultWindow = new WindowObject(defaultWidth, defaultHeight, sceneManager.currentScene.mainCamera);
    defaultWindow->InstanceGLFWWindow();
    LinkedList_Node<WindowObject> *node = new LinkedList_Node<WindowObject>();
    node->data = defaultWindow;
    windows.AddAtTail(node);
}

void Application::MainLoop(){
    Input::Instance()->Update();
    LinkedList_Node<WindowObject> * temp = windows.head;
    while(temp != NULL){
        temp->data->MainFrame();
        temp = temp->next;
    }
    sceneManager.currentScene.mainCamera->UpdateBehaviours();
    sceneManager.currentScene.MainUpdate();
    glfwPollEvents();
    if(glfwWindowShouldClose(windows.head->data->glfwInstance)){
        Quit();
    }
}

void Application::Quit(){
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
