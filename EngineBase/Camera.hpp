#ifndef CAMERA_HPP
#define CAMERA_HPP

#include"Vector3.hpp"
#include"Behaviour.hpp"
#include"Input.hpp"

class Camera : public Behaviour{
    public:
        Vector3 eyePose;
        Vector3 pivotPoint;
        Vector3 upDirection;

        Camera(Vector3 eye, Vector3 refPos, Vector3 upPose);
        Camera();
        void Start();
        void Update();
};
#endif
/*
class Camera {
    public:
        Vector3 *eyePose;
        Vector3 *pivotPoint;
        Vector3 *upDirection;

        Camera(Vector3 eye, Vector3 refPos, Vector3 upPose){
            eyePose = &eye;
            pivotPoint = &refPos;
            upDirection = &upPose;
        }

        Camera(){
            Vector3 zero = Vector3::zero();
            eyePose = &zero;
            Vector3 back = Vector3::back();
            pivotPoint = &back;
            Vector3 up = Vector3::up();
            upDirection = &up;
        }
};
*/
