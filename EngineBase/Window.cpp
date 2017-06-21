#include"Window.hpp"
#include<string.h>
#include<GLFW/glfw3.h>

WindowObject::WindowObject(int width, int height, GameObject * camera){
    Width = width;
    Height = height;
    Input::Instance()->SetScreenSize(Vector3(Width, Height,0));
    windowDrawer = WindowDrawer(&width, &height, camera);
};

void WindowObject::InstanceGLFWWindow(){
    glfwInstance = glfwCreateWindow(Width, Height, "GLFW/OpenGL Window", NULL, NULL);
    if(!glfwInstance){
        printf("Null Window!\n");
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(glfwInstance);
}

void WindowObject::MainFrame(){
    windowDrawer.RenderFrame(glfwInstance);
    DealWithEvents();
};

void WindowObject::DealWithEvents(){
    /*
    if(XEventsQueued(windowDrawer.dpy, QueuedAlready)){
        XNextEvent(windowDrawer.dpy, &xev);
        eventHandler.RouteXEvents(&xev, windowDrawer.dpy);
        if(xev.type != Expose){
            //memset(&redrawEvent, 0, sizeof(redrawEvent));
            redrawEvent.type = Expose;
            redrawEvent.xexpose.window = windowDrawer.win;
            //XSendEvent(windowDrawer.dpy, windowDrawer.win, False, ExposureMask, &redrawEvent);
            //XFlush(windowDrawer.dpy);
            eventHandler.RouteXEvents((XEvent *)&redrawEvent, windowDrawer.dpy);
        }
    } else {
        memset(&redrawEvent, 0, sizeof(redrawEvent));
        redrawEvent.type = Expose;
        redrawEvent.xexpose.window = windowDrawer.win;
        XSendEvent(windowDrawer.dpy, windowDrawer.win, False, ExposureMask, &redrawEvent);
        XFlush(windowDrawer.dpy);
        eventHandler.RouteXEvents((XEvent *)&redrawEvent, windowDrawer.dpy);
    }//*/
};
