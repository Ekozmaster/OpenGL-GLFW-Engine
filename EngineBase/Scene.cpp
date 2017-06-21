#include"Scene.hpp"

Scene::Scene(){
}
int Scene::GetAvailableID(){
    bool found = false;
    int i=0;
    while(!found){
        GameObjectNode * temp = activeObjects.head;
        bool alreadyInList=false;
        while(!alreadyInList && temp != NULL){
            if(temp->data->GetID() != i){
                temp = temp->next;
            } else {
                alreadyInList = true;
                i++;
            }
        }
        if(!alreadyInList){
            return i;
        }
    }return -1;

}
void Scene::RegisterObject(GameObject * object){
    GameObjectNode * node = GameObjectList::NewEmptyNode();
    object->SetID(GetAvailableID());
    node->data = object;
    activeObjects.AddAtTail(node);
}

void Scene::UnregisterObject(int id){
    activeObjects.RemoveById(id);
}

GameObject * Scene::GetObjectByID(int id){
    GameObjectNode * temp = activeObjects.GetById(id);
    return temp != NULL ? temp->data : NULL;
}

void Scene::MainUpdate(){
    int i=0;
    GameObjectNode * temp = activeObjects.head;
    while(i < activeObjects.Count){
        temp->data->UpdateBehaviours();


        i++;
        temp = temp->next;
    }
}

