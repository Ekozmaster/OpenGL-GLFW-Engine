#include"WindowDrawer.hpp"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<GL/glut.h>


WindowDrawer::WindowDrawer(int *width, int *height, GameObject *camera){
    Width = width;
    Height = height;
    mainCamera = camera;
    shaderProgram = glCreateProgram();
}

WindowDrawer::WindowDrawer(){
}

void WindowDrawer::RenderFrame(GLFWwindow *window){
    //XGetWindowAttributes(dpy, win, &gwa);
    glfwGetFramebufferSize(window, Width, Height);
    glViewport(0, 0, *Width, *Height);
    SetupViewMatrix();
    Camera * cam = mainCamera->GetComponent<Camera>();
    CamPose(cam->eyePose, cam->pivotPoint, cam->upDirection);

    ClearScreen();

    GLfloat cube[] = {
            // Back
            -0.5f, -0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
             0.5f, -0.5f, -0.5f,
             // Left
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
             // Front
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
             0.5f, -0.5f,  0.5f,
             // Right
             0.5f, -0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
             0.5f,  0.5f,  0.5f,
             0.5f, -0.5f, -0.5f,
             0.5f,  0.5f,  0.5f,
             0.5f, -0.5f,  0.5f,
             // Down
            -0.5f, -0.5f,  0.5f,
             0.5f, -0.5f,  0.5f,
             0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
             0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            // Up
            -0.5f,  0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
             0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f,  0.5f,
             0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,

    };//*/
    GLfloat colors[] = {
             0.2f,  0.2f,  0.2f,  1.0f,
             0.2f,  0.2f,  0.2f,  1.0f,
             0.2f,  0.2f,  0.2f,  1.0f,
             0.2f,  0.2f,  0.2f,  1.0f,
             0.2f,  0.2f,  0.2f,  1.0f,
             0.2f,  0.2f,  0.2f,  1.0f,

             0.35f,  0.35f,  0.35f,  1.0f,
             0.35f,  0.35f,  0.35f,  1.0f,
             0.35f,  0.35f,  0.35f,  1.0f,
             0.35f,  0.35f,  0.35f,  1.0f,
             0.35f,  0.35f,  0.35f,  1.0f,
             0.35f,  0.35f,  0.35f,  1.0f,

             0.5f,  0.5f,  0.5f,  1.0f,
             0.5f,  0.5f,  0.5f,  1.0f,
             0.5f,  0.5f,  0.5f,  1.0f,
             0.5f,  0.5f,  0.5f,  1.0f,
             0.5f,  0.5f,  0.5f,  1.0f,
             0.5f,  0.5f,  0.5f,  1.0f,

             0.7f,  0.7f,  0.7f,  1.0f,
             0.7f,  0.7f,  0.7f,  1.0f,
             0.7f,  0.7f,  0.7f,  1.0f,
             0.7f,  0.7f,  0.7f,  1.0f,
             0.7f,  0.7f,  0.7f,  1.0f,
             0.7f,  0.7f,  0.7f,  1.0f,

             0.5f,  0.2f,  0.5f,  1.0f,
             0.5f,  0.2f,  0.5f,  1.0f,
             0.5f,  0.2f,  0.5f,  1.0f,
             0.5f,  0.2f,  0.5f,  1.0f,
             0.5f,  0.2f,  0.5f,  1.0f,
             0.5f,  0.2f,  0.5f,  1.0f,

             0.2f,  0.5f,  0.5f,  1.0f,
             0.2f,  0.5f,  0.5f,  1.0f,
             0.2f,  0.5f,  0.5f,  1.0f,
             0.2f,  0.5f,  0.5f,  1.0f,
             0.2f,  0.5f,  0.5f,  1.0f,
             0.2f,  0.5f,  0.5f,  1.0f,
    };//*/

    glVertexPointer(3, GL_FLOAT, 0, cube);
    glColorPointer(4, GL_FLOAT, 0, colors);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glfwSwapBuffers(window);
}

void WindowDrawer::SetupViewMatrix(){
    glm::mat4x4 proj = glm::perspective(45.0f, (float)*Width / *Height, 0.1f, 1000.0f);





    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //float aspectRatio = (float)*Width / *Height;
    //glFrustum(-1.0f * aspectRatio, 1.0f * aspectRatio, -1.0f, 1.0f, 0.01f, 1000);

    //gluPerspective(65, (float)*Width/ *Height, 0.001f, 1000);
    glMatrixMode(GL_MODELVIEW);
};

void WindowDrawer::CamPose(Vector3 eyePose, Vector3 refPose, Vector3 upPose){
    eyePose.PrintCoords();
    //glm::tvec3<float>(eyePose.x, eyePose.y, eyePose.z);
    glm::lookAt(glm::tvec3<float>(eyePose.x, eyePose.y, eyePose.z), glm::tvec3<float>(refPose.x, refPose.y, refPose.z), glm::tvec3<float>(upPose.x, upPose.y, upPose.z));

    //glTranslatef(eyePose.x, eyePose.y, eyePose.z);
    //gluLookAt(eyePose.x, eyePose.y, eyePose.z,
    //    eyePose.x + refPose.x, eyePose.y + refPose.y, eyePose.z + refPose.z,
    //    upPose.x, upPose.y, upPose.z);
};



void WindowDrawer::InitX11OpenGL(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = (float)*Width / *Height;

    //gluPerspective(65, (float)*Width/ *Height, 0.001f, 1000);

    glm::perspective(65.0f, aspectRatio, 0.1f, 1000.0f);

    //glFrustum(0.5f, -0.5f, -0.5f * aspectRatio, 0.5f * aspectRatio, 0.1f, 1000);
    glMatrixMode(GL_MODELVIEW);
    //win = glfwCreateWindow(Width, Height, "Vai Toma No Cu", NULL, NULL);
    /*
    dpy = XOpenDisplay(NULL);

    if(dpy == NULL){
        printf("\n\tCannot Connect to X server\n\n");
        exit(0);
    }
    root = DefaultRootWindow(dpy);

    vi = glXChooseVisual(dpy, 0, att);
    if(vi == NULL){
        printf("\n\tno appropriate visual found\n\n");
        exit(0);
    } else {
        printf("\nvisual %p selected\n", (void *)vi->visualid);
    }
    cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask;

    //win = XCreateWindow(dpy, root, 0, 0, 720, 480, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
    XMapWindow(dpy, win);
    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);
    glEnable(GL_DEPTH_TEST);
    */
}


void WindowDrawer::ClearScreen(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


