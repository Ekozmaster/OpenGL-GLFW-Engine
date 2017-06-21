#include"GameObject.hpp"
#include<typeinfo>

GameObject::GameObject(){
    transform = Transform();
};

template<class T>
void GameObject::AddComponent(T * component){
    LinkedList_Node<Behaviour> * node = new LinkedList_Node<Behaviour>();
    component->SetID(GetAvailableID());
    component->gameObject = this;
    node->data = component;
    components.AddAtTail(node);
}

template<typename component>
void GameObject::AddComponent(){
    LinkedList_Node<Behaviour> * node = new LinkedList_Node<Behaviour>();
    Behaviour * comp = new component();
    comp->SetID(GetAvailableID());
    comp->gameObject = this;
    node->data = comp;
    components.AddAtTail(node);
}

template<typename component>
void GameObject::RemoveComponent(){
    LinkedList_Node<Behaviour> * temp = components.head;
    int i=0;
    while(i<components.Count){
        // If the node data has the same type of the required component.
        if(dynamic_cast<component>(temp->data) != 0){
            components.RemoveFromIndex(i);
            return;
        }
        temp = temp->next;
        i++;
    }
}

int GameObject::GetAvailableID(){
    bool found = false;
    int i=0;
    while(!found){
        LinkedList_Node<Behaviour> * temp = components.head;
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

template<typename component>
component *GameObject::GetComponent(){
    LinkedList_Node<Behaviour> * temp = components.head;
    int i=0;
    while(i<components.Count){
        if(dynamic_cast<component *>(temp->data) == 0){
            temp = temp->next;
        } else {
            return (component *)temp->data;
        }
        i++;
    }
    return NULL;
}

int GameObject::GetID(){
    return id;
}

void GameObject::SetID(int ID){
    id = ID;
}

void GameObject::UpdateBehaviours(){
    int i=0;
    LinkedList_Node<Behaviour> * temp = components.head;
    while(i<components.Count){
        if(!temp->data->IsStarted()){
            temp->data->Setup();
        } else {
            temp->data->Update();
        }
        temp = temp->next;
        i++;
    }
}





// DOUBLY LINKED LIST. Used for Scene objects management.
GameObjectList::GameObjectList(){
    Count = 0;
}

GameObjectNode * GameObjectList::NewNode(int id){
    GameObject *gm = new GameObject();
    gm->SetID(id);
    GameObjectNode * node = new GameObjectNode();
    node->data = gm;
    return node;
}

GameObjectNode * GameObjectList::NewEmptyNode(){
    GameObjectNode * node = new GameObjectNode();
    return node;
}

void GameObjectList::PrintAllNodes(){
    int i=0;
    GameObjectNode * temp = head;
    while(i<Count){
        printf("Node: %d\n", temp->data->GetID());
        temp = temp->next;
        i++;
    }
}
void GameObjectList::AddAtTail(GameObjectNode * beh){
    if(Count > 1){
        tail->next = beh;
        beh->prev = tail;
        tail = beh;
    } else if(Count == 1){
        head->next = beh;
        beh->prev = head;
        tail = beh;
    } else {
        head = beh;
        tail = beh;
    }
    Count++;
}
void GameObjectList::AddAtHead(GameObjectNode * beh){
    if(Count >= 1){
        head->prev = beh;
        beh->next = head;
        head = beh;
    } else {
        head = beh;
        tail = beh;
    }
    Count++;
}
void GameObjectList::RemoveNode(GameObjectNode * beh){
    int i=0;
    bool found = false;
    GameObjectNode * temp = head;
    while(i < Count && !found){
        if(temp != beh){
            temp = temp->next;
            i++;
        } else {
            found = true;
        }
    }
    if(found){
        if(i == 0){
            head = temp->next;
        } else if(i == Count-1){
            tail = tail->prev;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);

        Count--;
    }
}
void GameObjectList::RemoveFromTail(){
    if(Count > 0){
        GameObjectNode * temp = tail;
        tail = tail->prev;
        free(temp);
        Count--;
    }
}
void GameObjectList::RemoveFromHead(){
    if(Count > 0){
        GameObjectNode * temp = head;
        head = head->next;
        free(temp);
        Count--;
    }
}
void GameObjectList::RemoveById(int id){
    int i=0;
    bool found = false;
    GameObjectNode * temp = head;
    while(i < Count && !found){
        if(temp->data->GetID() != id){
            temp = temp->next;
            i++;
        } else {
            found = true;
        }
    }
    if(found){
        if(i == 0){
            head = temp->next;
        } else if(i == Count-1){
            tail = tail->prev;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);

        Count--;
    }
}
GameObjectNode *GameObjectList::GetById(int id){
    int i=0;
    GameObjectNode * temp = head;
    while(i < Count){
        if(temp->data->GetID() != id){
            temp = temp->next;
            i++;
        } else {
            return temp;
        }
    }return NULL;
}

