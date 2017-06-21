#ifndef SCENECAMERA_HPP
#define SCENECAMERA_HPP

#include"../EngineBase/Behaviour.hpp"
#include"../EngineBase/GameObject.hpp"

class SceneCamera : public Behaviour {
    private:
        float mouseX;
        float mouseY;
    public:
        SceneCamera();
        void Start();
        void Update();
};

#endif
