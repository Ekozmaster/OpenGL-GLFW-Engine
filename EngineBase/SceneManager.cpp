#include"SceneManager.hpp"
#include"../BehaviourScripts/SceneCamera.hpp"

SceneManager::SceneManager(){

}

void SceneManager::CreateNewScene(){
    currentScene = Scene();
    currentScene.mainCamera = new GameObject();
    currentScene.mainCamera->AddComponent<Camera>();
    currentScene.mainCamera->transform.position = Vector3(0, 0, -5.0f);
    currentScene.mainCamera->transform.rotation = Quaternion::identity();
    currentScene.mainCamera->AddComponent<SceneCamera>();
    //currentScene.RegisterObject(currentScene.mainCamera);
}
