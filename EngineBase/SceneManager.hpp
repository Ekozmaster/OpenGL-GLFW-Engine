#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include<vector>

class SceneManager{
        SceneManager(){};
        SceneManager(SceneManager const&){};
        SceneManager& operator =(SceneManager const&){};
        static SceneManager *instance;
        Scene *currentScene;
    public:
        static SceneManager* Instance();
        void CreateNewScene();
        Scene *GetCurrentScene();
        void SetCurrentScene();
};

#endif
