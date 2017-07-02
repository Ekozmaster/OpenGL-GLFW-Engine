#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include"SceneManager.hpp"
#include"Window.hpp"
#include"LinkedList.hpp"
#include"EventHandler.hpp"

class Application {
    private:
        int defaultWidth = 720;
        int defaultHeight = 480;
        SceneManager *sceneManager;
        EventHandler eventHandler;
        LinkedList<WindowObject> windows = *(new LinkedList<WindowObject>());

    public:
        Application();
        void Init();
        void SetupSystem();
        void LoadApplicationDefaultWindows();
        void MainLoop();
        void Quit();
};

#endif
