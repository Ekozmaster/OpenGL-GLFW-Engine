#ifndef INPUT_HPP
#define INPUT_HPP

#include"Vector3.hpp"
#include"InputStatics.hpp"
#include<GLFW/glfw3.h>

class Input{
    private:
        bool * keysState;
        Vector3 screenSize;
        const static int keysStateSize = 58;
        Input(){};
        Input(Input const&){};
        Input& operator =(Input const&){};
        static Input* instance;

        float mouseX, lastMouseX;
        float mouseY, lastMouseY;
        float deltaMouseX;
        float deltaMouseY;
        float verticalAxis;
        float horizontalAxis;
        float axisAcceleration = 0.1f;

    public:
        static Input* Instance();
        void SetScreenSize(Vector3 scSize);
        void InitKeysStatePointer();

        // Axis Getters
        float GetDeltaMouseX();
        float GetDeltaMouseY();

        void UpdateKeysState(GLFWwindow *window, int key, int scancode, int action, int mods);
        void UpdateMouseMotion(GLFWwindow *window, double xPos, double yPos);
        void Update();
        void AxisLogic(bool up, bool down, bool left, bool right);
        bool GetKey(int keycode);
        float GetAxis(char axisName[]);
};
#endif
