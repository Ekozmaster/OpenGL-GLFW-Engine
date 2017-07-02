#include"Application.hpp"
#include<stdlib.h>
#include<GLFW/glfw3.h>

Application::Application(){

}

void Application::Init(){
    if(!glfwInit()){
        exit(EXIT_FAILURE);
    }
    SetupSystem();
    sceneManager = SceneManager::Instance();
    sceneManager->CreateNewScene();
    windows.head->data->SetRenderingCamera(sceneManager->GetCurrentScene()->mainCamera);
}

void Application::SetupSystem(){
    Input::Instance()->InitKeysStatePointer();
    Input::Instance()->SetScreenSize(Vector3(defaultWidth, defaultHeight, 0));
    LoadApplicationDefaultWindows();
    eventHandler = EventHandler(windows.head->data);
    eventHandler.RegisterCallbacks();
    glfwSwapInterval(1);
}

void Application::LoadApplicationDefaultWindows(){
    WindowObject *defaultWindow = new WindowObject(defaultWidth, defaultHeight);
    defaultWindow->InstantiateGLFWWindow();
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
    sceneManager->GetCurrentScene()->mainCamera->UpdateBehaviours();
    sceneManager->GetCurrentScene()->MainUpdate();
    glfwPollEvents();
    if(glfwWindowShouldClose(windows.head->data->glfwInstance)){
        Quit();
    }
}

void Application::Quit(){
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
