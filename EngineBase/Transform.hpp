#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Vector3.hpp"
#include"Quaternion.hpp"
class Transform {
    public:
        Vector3 position;
        Quaternion rotation;
        Vector3 scale;
        Transform();
        Transform(Vector3 POS, Quaternion ROT, Vector3 SCL);
        glm::mat4 GetTransformMatrix();
};

#endif
