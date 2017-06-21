#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include<X11/Xlib.h>
#include"Window.hpp"
#include"Input.hpp"

class EventHandler {
    private:
        WindowObject * mainWindow;
    public:
        static void KeyPressCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void WindowShouldCloseCallback(GLFWwindow *window);
        EventHandler();
        EventHandler(WindowObject *mW);
        void RegisterCallbacks();
        void RouteXEvents(XEvent *event, Display *dpy);
};


#endif
