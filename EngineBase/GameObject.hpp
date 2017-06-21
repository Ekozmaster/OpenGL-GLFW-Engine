#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include"Vector3.hpp"
#include"Quaternion.hpp"
#include"Transform.hpp"
#include"Behaviour.hpp"
#include"LinkedList.hpp"

class GameObject{
    private:
        int id;
        LinkedList<Behaviour> components;
    public:
        Transform transform;
        GameObject();
        template<class T>
        void AddComponent(T * component);
        template<typename component>
        void AddComponent();
        template<typename component>
        void RemoveComponent();
        int GetAvailableID();
        template<typename component>
        component *GetComponent();
        int GetID();
        void SetID(int ID);
        void UpdateBehaviours();
};

typedef struct gm {
    GameObject * data;
    struct gm * prev=NULL;
    struct gm * next=NULL;
} GameObjectNode;

class GameObjectList {
    public:
        int Count;
        GameObjectNode * head=NULL;
        GameObjectNode * tail=NULL;
        GameObjectList();
        static GameObjectNode * NewNode(int id);
        static GameObjectNode * NewEmptyNode();
        void PrintAllNodes();
        void AddAtTail(GameObjectNode * beh);
        void AddAtHead(GameObjectNode * beh);
        void RemoveNode(GameObjectNode * beh);
        void RemoveFromTail();
        void RemoveFromHead();
        void RemoveById(int id);
        GameObjectNode *GetById(int id);
};

#endif
/*
class Transform{
    public:
        Vector3 position;
        Quaternion rotation;
        Vector3 scale;
        Transform(Vector3 POS, Quaternion ROT, Vector3 SCL){
            position = POS;
            rotation = ROT;
            scale = SCL;
        }

        Transform(){
            position = Vector3::zero();
            rotation = Quaternion::identity();
            scale = Vector3::one();
        }

};

#include<list>
class GameObject{
    public:
        Transform transform;
        GameObject(){
            transform = Transform();
        }
        Camera cam;

        void updateCamera(){
            Vector3 pivotPoint = (transform.rotation * Vector3::forward());
            cam.eyePose = &transform.position;
            cam.pivotPoint = &pivotPoint;
        }
};
*/
