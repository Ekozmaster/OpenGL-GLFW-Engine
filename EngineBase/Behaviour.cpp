#include"Behaviour.hpp"

Behaviour::Behaviour(Scene * scene){
    started = false;
    //id = scene->GetAvailableID();
    //Setup(scene);
}

Behaviour::Behaviour(){
    started = false;
}

void Behaviour::Setup(){
    started = true;
}

int Behaviour::GetID(){
    return id;
}

void Behaviour::SetID(int ID){
    id = ID;
}

bool Behaviour::IsStarted(){
    return started;
}

void Behaviour::Start(){

}

void Behaviour::Update(){

}

void Behaviour::Render(){

}




BehaviourList::BehaviourList(){
    Count = 0;
}

BehaviourNode * BehaviourList::NewNode(int id){
    Behaviour *bh = new Behaviour();
    bh->SetID(id);
    BehaviourNode * node = new BehaviourNode();
    node->data = bh;
    return node;
}

void BehaviourList::PrintAllNodes(){
    int i=0;
    BehaviourNode * temp = head;
    while(i<Count){
        printf("Node: %d\n", temp->data->GetID());
        temp = temp->next;
        i++;
    }
}

void BehaviourList::AddAtTail(BehaviourNode * beh){
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

void BehaviourList::AddAtHead(BehaviourNode * beh){
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

void BehaviourList::RemoveNode(BehaviourNode * beh){
    int i=0;
    bool found = false;
    BehaviourNode * temp = head;
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

void BehaviourList::RemoveFromTail(){
    if(Count > 0){
        BehaviourNode * temp = tail;
        tail = tail->prev;
        free(temp);
        Count--;
    }
}

void BehaviourList::RemoveFromHead(){
    if(Count > 0){
        BehaviourNode * temp = head;
        head = head->next;
        free(temp);
        Count--;
    }
}

void BehaviourList::RemoveById(int id){
    int i=0;
    bool found = false;
    BehaviourNode * temp = head;
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

BehaviourNode *BehaviourList::GetById(int id){
    int i=0;
    BehaviourNode * temp = head;
    while(i < Count){
        if(temp->data->GetID() != id){
            temp = temp->next;
            i++;
        } else {
            return temp;
        }
    }return NULL;
}
