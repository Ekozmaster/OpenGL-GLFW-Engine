#ifndef INPUTSTATICS_HPP
#define INPUTSTATICS_HPP

//#include<X11/keysym.h>
#include<GLFW/glfw3.h>

struct KeyCodeToIdx {
    public:
        const static int A = 0;
        const static int B = 1;
        const static int C = 2;
        const static int D = 3;
        const static int E = 4;
        const static int F = 5;
        const static int G = 6;
        const static int H = 7;
        const static int I = 8;
        const static int J = 9;
        const static int K = 10;
        const static int L = 11;
        const static int M = 12;
        const static int N = 13;
        const static int O = 14;
        const static int P = 15;
        const static int Q = 16;
        const static int R = 17;
        const static int S = 18;
        const static int T = 19;
        const static int U = 20;
        const static int V = 21;
        const static int W = 22;
        const static int X = 23;
        const static int Y = 24;
        const static int Z = 25;

        const static int Up = 26;
        const static int Down = 27;
        const static int Left = 28;
        const static int Right = 29;

        const static int Space = 30;
        const static int LeftControl = 31;
        const static int RightControl = 32;
        const static int LeftShift = 33;
        const static int RightShift = 34;
        const static int LeftAlt = 35;
        const static int RightAlt = 36;

        const static int Esc = 37;
        const static int F1 = 38;
        const static int F2 = 39;
        const static int F3 = 40;
        const static int F4 = 41;
        const static int F5 = 42;
        const static int F6 = 43;
        const static int F7 = 44;
        const static int F8 = 45;
        const static int F9 = 46;
        const static int F10 = 47;
        const static int F11 = 48;
        const static int F12 = 49;

        const static int PauseBreak = 50;
        const static int Insert = 51;
        const static int Delete = 52;

        const static int LeftMouseButton = 53;
        const static int MiddleMouseButton = 54;
        const static int RightMouseButton = 55;
        const static int WheelUpMouseButton = 56;
        const static int WheelDownMouseButton = 57;
        // 58 Keys Mapped.
};

struct KeyCodeToGLFW {
    public:
        const static int A = GLFW_KEY_A;
        const static int B = GLFW_KEY_B;
        const static int C = GLFW_KEY_C;
        const static int D = GLFW_KEY_D;
        const static int E = GLFW_KEY_E;
        const static int F = GLFW_KEY_F;
        const static int G = GLFW_KEY_G;
        const static int H = GLFW_KEY_H;
        const static int I = GLFW_KEY_I;
        const static int J = GLFW_KEY_J;
        const static int K = GLFW_KEY_K;
        const static int L = GLFW_KEY_L;
        const static int M = GLFW_KEY_M;
        const static int N = GLFW_KEY_N;
        const static int O = GLFW_KEY_O;
        const static int P = GLFW_KEY_P;
        const static int Q = GLFW_KEY_Q;
        const static int R = GLFW_KEY_R;
        const static int S = GLFW_KEY_S;
        const static int T = GLFW_KEY_T;
        const static int U = GLFW_KEY_U;
        const static int V = GLFW_KEY_V;
        const static int W = GLFW_KEY_W;
        const static int X = GLFW_KEY_X;
        const static int Y = GLFW_KEY_Y;
        const static int Z = GLFW_KEY_Z;

        const static int Up = GLFW_KEY_UP;
        const static int Down = GLFW_KEY_DOWN;
        const static int Left = GLFW_KEY_LEFT;
        const static int Right = GLFW_KEY_RIGHT;

        const static int Space = GLFW_KEY_SPACE;
        const static int LeftControl = GLFW_KEY_LEFT_CONTROL;
        const static int RightControl = GLFW_KEY_RIGHT_CONTROL;
        const static int LeftShift = GLFW_KEY_LEFT_SHIFT;
        const static int RightShift = GLFW_KEY_RIGHT_SHIFT;
        const static int LeftAlt = GLFW_KEY_LEFT_ALT;
        const static int RightAlt = GLFW_KEY_RIGHT_ALT;//37

        const static int Esc = GLFW_KEY_ESCAPE;
        const static int F1 = GLFW_KEY_F1;
        const static int F2 = GLFW_KEY_F2;
        const static int F3 = GLFW_KEY_F3;
        const static int F4 = GLFW_KEY_F4;
        const static int F5 = GLFW_KEY_F5;
        const static int F6 = GLFW_KEY_F6;
        const static int F7 = GLFW_KEY_F7;
        const static int F8 = GLFW_KEY_F8;
        const static int F9 = GLFW_KEY_F9;
        const static int F10 = GLFW_KEY_F10;
        const static int F11 = GLFW_KEY_F11;
        const static int F12 = GLFW_KEY_F12;

        const static int PauseBreak = GLFW_KEY_PAUSE;
        const static int Insert = GLFW_KEY_INSERT;
        const static int Delete = GLFW_KEY_DELETE;

        const static int LeftMouseButton = GLFW_MOUSE_BUTTON_1;
        const static int MiddleMouseButton = GLFW_MOUSE_BUTTON_2;
        const static int RightMouseButton = GLFW_MOUSE_BUTTON_3;
        const static int WheelUpMouseButton = GLFW_MOUSE_BUTTON_4;
        const static int WheelDownMouseButton = GLFW_MOUSE_BUTTON_5;

        // 58 Keys Mapped.
};

inline int GLFWToKeyCodeIdx(int key) {
    switch(key){
        case GLFW_KEY_A: return KeyCodeToIdx::A;
        case GLFW_KEY_B: return KeyCodeToIdx::B;
        case GLFW_KEY_C: return KeyCodeToIdx::C;
        case GLFW_KEY_D: return KeyCodeToIdx::D;
        case GLFW_KEY_E: return KeyCodeToIdx::E;
        case GLFW_KEY_F: return KeyCodeToIdx::F;
        case GLFW_KEY_G: return KeyCodeToIdx::G;
        case GLFW_KEY_H: return KeyCodeToIdx::H;
        case GLFW_KEY_I: return KeyCodeToIdx::I;
        case GLFW_KEY_J: return KeyCodeToIdx::J;
        case GLFW_KEY_K: return KeyCodeToIdx::K;
        case GLFW_KEY_L: return KeyCodeToIdx::L;
        case GLFW_KEY_M: return KeyCodeToIdx::M;
        case GLFW_KEY_N: return KeyCodeToIdx::N;
        case GLFW_KEY_O: return KeyCodeToIdx::O;
        case GLFW_KEY_P: return KeyCodeToIdx::P;
        case GLFW_KEY_Q: return KeyCodeToIdx::Q;
        case GLFW_KEY_R: return KeyCodeToIdx::R;
        case GLFW_KEY_S: return KeyCodeToIdx::S;
        case GLFW_KEY_T: return KeyCodeToIdx::T;
        case GLFW_KEY_U: return KeyCodeToIdx::U;
        case GLFW_KEY_V: return KeyCodeToIdx::V;
        case GLFW_KEY_W: return KeyCodeToIdx::W;
        case GLFW_KEY_X: return KeyCodeToIdx::X;
        case GLFW_KEY_Y: return KeyCodeToIdx::Y;
        case GLFW_KEY_Z: return KeyCodeToIdx::Z;

        case GLFW_KEY_UP: return KeyCodeToIdx::Up;
        case GLFW_KEY_DOWN: return KeyCodeToIdx::Down;
        case GLFW_KEY_LEFT: return KeyCodeToIdx::Left;
        case GLFW_KEY_RIGHT: return KeyCodeToIdx::Right;

        case GLFW_KEY_SPACE: return KeyCodeToIdx::Space;
        case GLFW_KEY_LEFT_CONTROL: return KeyCodeToIdx::LeftControl;
        case GLFW_KEY_RIGHT_CONTROL: return KeyCodeToIdx::RightControl;
        case GLFW_KEY_LEFT_SHIFT: return KeyCodeToIdx::LeftShift;
        case GLFW_KEY_RIGHT_SHIFT: return KeyCodeToIdx::RightShift;
        case GLFW_KEY_LEFT_ALT: return KeyCodeToIdx::LeftAlt;
        case GLFW_KEY_RIGHT_ALT: return KeyCodeToIdx::RightAlt;

        case GLFW_KEY_ESCAPE: return KeyCodeToIdx::Esc;
        case GLFW_KEY_F1: return KeyCodeToIdx::F1;
        case GLFW_KEY_F2: return KeyCodeToIdx::F2;
        case GLFW_KEY_F3: return KeyCodeToIdx::F3;
        case GLFW_KEY_F4: return KeyCodeToIdx::F4;
        case GLFW_KEY_F5: return KeyCodeToIdx::F5;
        case GLFW_KEY_F6: return KeyCodeToIdx::F6;
        case GLFW_KEY_F7: return KeyCodeToIdx::F7;
        case GLFW_KEY_F8: return KeyCodeToIdx::F8;
        case GLFW_KEY_F9: return KeyCodeToIdx::F9;
        case GLFW_KEY_F10: return KeyCodeToIdx::F10;
        case GLFW_KEY_F11: return KeyCodeToIdx::F11;
        case GLFW_KEY_F12: return KeyCodeToIdx::F12;

        case GLFW_KEY_PAUSE: return KeyCodeToIdx::PauseBreak;
        case GLFW_KEY_INSERT: return KeyCodeToIdx::Insert;
        case GLFW_KEY_DELETE: return KeyCodeToIdx::Delete;

        case GLFW_MOUSE_BUTTON_1: return KeyCodeToIdx::LeftMouseButton;
        case GLFW_MOUSE_BUTTON_2: return KeyCodeToIdx::MiddleMouseButton;
        case GLFW_MOUSE_BUTTON_3: return KeyCodeToIdx::RightMouseButton;
        case GLFW_MOUSE_BUTTON_4: return KeyCodeToIdx::WheelUpMouseButton;
        case GLFW_MOUSE_BUTTON_5: return KeyCodeToIdx::WheelDownMouseButton;
    }
    return -1;
};
#endif
