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

glm::mat4 Transform::GetTransformMatrix(){
    glm::mat4 trans;
    trans = glm::scale(trans, scale.ToGLMVec3());
    trans *= rotation.ToGLMMat4();
    trans = glm::translate(trans, position.ToGLMVec3());
    return trans;
};
