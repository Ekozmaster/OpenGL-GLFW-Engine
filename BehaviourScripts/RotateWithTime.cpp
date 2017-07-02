#include"RotateWithTime.hpp"
#include"../EngineBase/GameObject.hpp"

void RotateWithTime::Start(){


};

void RotateWithTime::Update(){
    angle += 1.0f;
    gameObject->transform.rotation = Quaternion::Euler(0.0f, angle, 0.0f);
};
