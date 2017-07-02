#ifndef SCENE_HPP
#define SCENE_HPP

#include"GameObject.hpp"
#include"Mesh.hpp"

class Scene{
    private:
    public:
        GameObjectList activeObjects;
        GameObject * mainCamera;
        Scene();
        static Scene *CreateDefaultTestScene();
        int GetAvailableID();
        void RegisterObject(GameObject * object); // Adds a object to the execution queue.
        void UnregisterObject(int id); // Remove object from execution queue.
        GameObject *GetObjectByID(int id); // Get object from queue with id.
        void MainUpdate(); // Runs everything on scene.
};

#endif
