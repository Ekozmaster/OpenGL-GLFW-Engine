#ifndef WINDOW_HPP
#define WINDOW_HPP

#include"Vector3.hpp"
#include"Input.hpp"
#include"GameObject.hpp"
#include"WindowDrawer.hpp"

class WindowObject {
    private:
        WindowDrawer windowDrawer;

    public:
        GLFWwindow *glfwInstance;
        int Width;
        int Height;
        Vector3 mouseAxis;

        WindowObject(int width, int height, GameObject * camera);
        void InstanceGLFWWindow();
        void MainFrame();
        void DealWithEvents();
};

#endif
/*
class WindowObject {
    public:
        SDL_Surface screen;
        SDL_Event events;
        Input input;
        int Width;
        int Height;
        GameObject mainCamera;
        Vector3 mouseAxis;

        WindowObject(int width, int height, GameObject camera){
            Width = width;
            Height = height;
            input = Input(Vector3(Width, Height));
            mainCamera = camera;
            SDL_Init(SDL_INIT_EVERYTHING);

            unsigned int flags = SDL_OPENGL;
            screen = *SDL_SetVideoMode(Width, Height, 16, flags);
        }

        void MainFrame(){
            DealWithEvents();
            input.Update();
            KeepMouseOnCenter();

            if(input.GetKey(Keycode::P)){
                SDL_Quit();
            }

            Vector3 navInput = Vector3(input.GetAxis("Horizontal"), input.GetAxis("Vertical"));


            mouseAxis = mouseAxis + Vector3(input.GetAxis("Mouse X"),input.GetAxis("Mouse Y"));
            AdjustCameraRotation(mouseAxis.x, mouseAxis.y);

            Vector3 cameraLeft = Vector3::Cross(*mainCamera.cam.pivotPoint, Vector3::up()).normalized();
            mainCamera.transform.position = mainCamera.transform.position + (mainCamera.cam.pivotPoint->normalized() * navInput.y * 0.3f) + (cameraLeft * navInput.x * 0.3f);
            mainCamera.updateCamera();
            RenderFrame();
        }


        void AdjustCameraRotation(int mouseX, int mouseY){
            Vector3 cameraYawAxis = Vector3::Cross(*mainCamera.cam.pivotPoint, Vector3::up());
            //float test1 = (float)mouseX/100;
            //Vector3 test = Vector3::up() * ((float)mouseX/100);
            mainCamera.transform.rotation = Quaternion::Euler(Vector3((float)mouseY/100, (float)mouseX/100, 0.0f));
        }

        void KeepMouseOnCenter(){
            SDL_WarpMouse(Width/2, Height/2);
        }

        void DealWithEvents(){
            while(SDL_PollEvent(&events)){
                if(events.type == SDL_QUIT){ SDL_Quit(); }
            }
        }

        void RenderFrame(){
            glViewport(0, 0, Width, Height);

            // Setup Matrix (should be done every frame)
            SetupViewMatrix();
            CamPose(*mainCamera.cam.eyePose, *mainCamera.cam.pivotPoint, *mainCamera.cam.upDirection);

            // Clear Screen
            ClearScreen();
            SDL_GL_SwapBuffers();
        }

        void SetupViewMatrix(){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(50, (float)Width/Height, 0.1, 100);
        }

        void CamPose(Vector3 eyePose, Vector3 refPose, Vector3 upPose){
            gluLookAt(eyePose.x, eyePose.y, eyePose.z,
                eyePose.x + refPose.x, eyePose.y + refPose.y, eyePose.z + refPose.z,
                upPose.x, upPose.y, upPose.z);
        }

        void ClearScreen(){
            glClearColor(0.85, 0.85, 0.85, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
};
*/
