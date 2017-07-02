#include"Input.hpp"
#include<cstdlib>
#include<string.h>
#include<GLFW/glfw3.h>

Input* Input::instance = NULL;

void Input::Update(){
    deltaMouseX = lastMouseX - mouseX;
    deltaMouseY = lastMouseY - mouseY;
    lastMouseX = mouseX;
    lastMouseY = mouseY;
    AxisLogic(GetKey(KeyCodeToIdx::W), GetKey(KeyCodeToIdx::S), GetKey(KeyCodeToIdx::A), GetKey(KeyCodeToIdx::D));
};

Input* Input::Instance(){
    if(!instance) instance = new Input();
    return instance;
};
void Input::SetScreenSize(Vector3 scSize){
    screenSize = scSize;
};
void Input::InitKeysStatePointer(){
    keysState = (bool*)malloc(sizeof(bool) * keysStateSize);
    for(int i=0; i<keysStateSize; i++){
        keysState[i] = false;
    }
};

void Input::AxisLogic(bool up, bool down, bool left, bool right){
    // VerticalAxis
    if(up){
        verticalAxis += axisAcceleration;
    } else if (down){
        verticalAxis -= axisAcceleration;
    } else {
        if(Mathf::Abs(verticalAxis) > axisAcceleration-0.01){
            verticalAxis += (-verticalAxis / Mathf::Abs(verticalAxis))*axisAcceleration;
        } else {verticalAxis = 0;}
    }

    // HorizontalAxis
    if(left){
        horizontalAxis -= axisAcceleration;
    } else if (right){
        horizontalAxis += axisAcceleration;
    } else {
        if(Mathf::Abs(horizontalAxis) > axisAcceleration-0.01){
            horizontalAxis += (-horizontalAxis / Mathf::Abs(horizontalAxis))*axisAcceleration;
        } else {horizontalAxis = 0;}
    }
    verticalAxis = Mathf::Clamp(verticalAxis, -1, 1);
    horizontalAxis = Mathf::Clamp(horizontalAxis, -1, 1);
};

bool Input::GetKey(int keycode){
    return keysState[keycode];
};

float Input::GetAxis(char axisName[]){
    if(strcmp(axisName, "Mouse X") == 0){
        return deltaMouseX;
    } if(strcmp(axisName, "Mouse Y") == 0){
        return deltaMouseY;
    } if(strcmp(axisName, "Vertical") == 0){
        return verticalAxis;
    } if(strcmp(axisName, "Horizontal") == 0){
        return horizontalAxis;
    } else {
        return 0;
    }
};

void Input::UpdateKeysState(GLFWwindow *window, int key, int scancode, int action, int mods){

    if(action == GLFW_PRESS){
        keysState[GLFWToKeyCodeIdx(key)] = true;
    } else if(action == GLFW_RELEASE){
        keysState[GLFWToKeyCodeIdx(key)] = false;
    }
};

void Input::UpdateMouseMotion(GLFWwindow *window, double xPos, double yPos){
    mouseX = xPos;
    mouseY = yPos;
}
