#include"Transform.hpp"

Transform::Transform(){
    position = Vector3::zero();
    rotation = Quaternion::identity();
    scale = Vector3::one();
};

Transform::Transform(Vector3 POS, Quaternion ROT, Vector3 SCL){
    position = POS;
    rotation = ROT;
    scale = SCL;
};
