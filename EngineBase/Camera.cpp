#include"Camera.hpp"
#include<GL/glu.h>
#include"GameObject.hpp"
#include"Quaternion.hpp"

Camera::Camera(Vector3 eye, Vector3 refPos, Vector3 upPose){
    eyePose = eye;
    pivotPoint = refPos;
    upDirection = upPose;
};

Camera::Camera(){
    eyePose = Vector3::zero();
    pivotPoint = Vector3::back();
    upDirection = Vector3::up();
};

void Camera::Start(){

}

void Camera::Update(){
    eyePose = gameObject->transform.position;
    pivotPoint = gameObject->transform.rotation * Vector3::forward();
}
