#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

#include<stddef.h>

class Scene;
#ifndef GAMEOBJECT_HPP
class GameObject;
#endif


class Behaviour{
    private:
        int id;
        bool started=false;
    public:
        GameObject * gameObject;
        Behaviour(Scene * scene);
        Behaviour();
        void Setup();
        int GetID();
        void SetID(int ID);
        bool IsStarted();

        virtual void Start();
        virtual void Update();
};

typedef struct bh {
    Behaviour * data;
    struct bh * prev=NULL;
    struct bh * next=NULL;
} BehaviourNode;

class BehaviourList {
    public:
        int Count;
        BehaviourNode * head=NULL;
        BehaviourNode * tail=NULL;
        BehaviourList();
        static BehaviourNode * NewNode(int id);
        void PrintAllNodes();
        void AddAtTail(BehaviourNode * beh);
        void AddAtHead(BehaviourNode * beh);
        void RemoveNode(BehaviourNode * beh);
        void RemoveFromTail();
        void RemoveFromHead();
        void RemoveById(int id);
        BehaviourNode *GetById(int id);
};

#endif
