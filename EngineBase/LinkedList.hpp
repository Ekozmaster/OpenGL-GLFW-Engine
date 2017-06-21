#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template<class T>
class LinkedList_Node{
    public:
        T * data;
        LinkedList_Node<T> * prev;
        LinkedList_Node<T> * next;
};

template<typename T>
class LinkedList{
    public:
        int Count;
        LinkedList_Node<T> * head;
        LinkedList_Node<T> * tail;

        LinkedList();
        // ADD
        void AddAtTail(LinkedList_Node<T> * obj);
        void AddAtHead(LinkedList_Node<T> * obj);
        void AddAtIndex(LinkedList_Node<T> * obj, int idx);
        // REMOVE
        void RemoveFromTail();
        void RemoveFromHead();
        void RemoveFromIndex(int idx);
        // GET
        LinkedList_Node<T> * GetAtIndex(int idx);
};
//*/
#endif
