#include"SceneManager.hpp"
#include"../BehaviourScripts/SceneCamera.hpp"

SceneManager* SceneManager::instance = NULL;

SceneManager* SceneManager::Instance(){
    if(!instance) instance = new SceneManager();
    return instance;
};

Scene *SceneManager::GetCurrentScene(){
    return currentScene;
}

void SceneManager::CreateNewScene(){
    currentScene = Scene::CreateDefaultTestScene();
    /*
    currentScene = new Scene();
    currentScene->mainCamera = new GameObject();
    currentScene->mainCamera->AddComponent<Camera>();
    currentScene->mainCamera->transform.position = Vector3(0, 0, -5.0f);
    currentScene->mainCamera->transform.rotation = Quaternion::identity();
    currentScene->mainCamera->AddComponent<SceneCamera>();
    //*/
}
