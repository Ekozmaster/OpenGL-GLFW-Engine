#include"LinkedList.hpp"


template<typename T>
LinkedList<T>::LinkedList(){
    Count = 0;
    head = NULL;
    tail = NULL;
}
// ADD
template<typename T>
void LinkedList<T>::AddAtTail(LinkedList_Node<T> * obj){
    if(Count > 1){
        tail->next = obj;
        obj->prev = tail;
        tail = obj;
    } else if(Count == 1){
        head->next = obj;
        obj->prev = head;
        tail = obj;

    } else {
        head = obj;
        tail = obj;
    }
    Count++;
}

template<typename T>
void LinkedList<T>::AddAtHead(LinkedList_Node<T> * obj){
    if(Count >= 1){
        head->prev = obj;
        obj->next = head;
        head = obj;
    } else {
        head = obj;
        tail = obj;
    }
    Count++;
}

template<typename T>
void LinkedList<T>::AddAtIndex(LinkedList_Node<T> * obj, int idx){
    int i=0;
    LinkedList_Node<T> * temp = head;
    if(idx == 0){
        AddAtHead(obj);
    } else if (idx == Count){
        AddAtTail(obj);
    } else {
        while(i < idx && temp != NULL && i < Count){
            temp = temp->next;
            i++;
        }
        if(temp != NULL){
            obj->next = temp;
            obj->prev = temp->prev;
            temp->prev = obj;
            obj->prev->next = obj;
            Count++;
        }
    }

}
// REMOVE
template<typename T>
void LinkedList<T>::RemoveFromTail(){
    if(Count > 1){
        tail = tail->prev;
        tail->next = NULL;
        //free(temp);
        Count--;
    } else if(Count == 1){
        head = NULL;
        tail = NULL;
        Count--;
    }
}

template<typename T>
void LinkedList<T>::RemoveFromHead(){
    if(Count > 1){
        head = head->next;
        head->prev = NULL;
        Count--;
    } else if(Count == 1){
        head = NULL;
        tail = NULL;
        Count--;
    }
}

template<typename T>
void LinkedList<T>::RemoveFromIndex(int idx){
    int i=0;
    LinkedList_Node<T> * temp = head;
    if(idx == 0){
        RemoveFromHead();
        return;
    } else if(idx == Count-1){
        RemoveFromTail();
        return;
    }


    while(i < idx && temp != NULL && i < Count){
        temp = temp->next;
        i++;
    }

    if(temp != NULL && i == idx){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        Count--;
    }
}

// GET
template<typename T>
LinkedList_Node<T> * LinkedList<T>::GetAtIndex(int idx){
    int i=0;
    LinkedList_Node<T> * temp = head;
    if(idx == 0){
        return temp;
    }

    while(i < idx && temp != NULL && i < Count){
        temp = temp->next;
        i++;
    }

    if(temp != NULL){
        return temp;
    }
}
//*/
