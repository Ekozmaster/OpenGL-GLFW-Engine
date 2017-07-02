#ifndef ROTATEWITHTIME_HPP
#define ROTATEWITHTIME_HPP

#include"../EngineBase/Behaviour.hpp"

class RotateWithTime : public Behaviour {
    public:
        float angle = 0.0f;
        void Start();
        void Update();

};

#endif
