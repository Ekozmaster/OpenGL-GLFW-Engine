#include"SceneCamera.hpp"
#include"../EngineBase/Vector3.hpp"
#include"../EngineBase/Quaternion.hpp"
#include"../EngineBase/Camera.hpp"
#include"../EngineBase/Mathf.hpp"

SceneCamera::SceneCamera(){

}

void SceneCamera::Start(){

}

void SceneCamera::Update(){
    Camera * cam = gameObject->GetComponent<Camera>();
    Vector3 input = Vector3(Input::Instance()->GetAxis("Horizontal"), Input::Instance()->GetAxis("Vertical"), 0);
    gameObject->transform.position += (cam->pivotPoint * input.y + Vector3::Cross(cam->pivotPoint, cam->upDirection) * input.x)*0.2f;
    if(Input::Instance()->GetKey(KeyCodeToIdx::RightMouseButton)){
        mouseX = Mathf::RepeatAround(mouseX + (float)Input::Instance()->GetAxis("Mouse X")*0.2f, 0, 360);
        mouseY = Mathf::RepeatAround(mouseY + (float)Input::Instance()->GetAxis("Mouse Y")*0.2f, 0, 360);
        gameObject->transform.rotation = Quaternion::Euler(-mouseY, mouseX, 0);
        //printf("%f\n", (gameObject->transform.rotation * Vector3::forward()).z);
    }
}


