#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include<vector>

class SceneManager{
    public:
        SceneManager();
        Scene currentScene;
        void CreateNewScene();
};

#endif
