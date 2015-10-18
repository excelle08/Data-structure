#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef NULL
#define NULL 0
#endif // NULL

#include <iostream>

template <class T>
struct _Node {
    T value;
    struct _Node<T> *next;    
};

template <class T>
class LinkedListIterator;

template <class T>
class LinkedList {
public:
    friend class LinkedListIterator<T>;
    LinkedList();
    virtual ~LinkedList();
    void append(T value);
    void insert(int position, T value);
    void remove(int position);
    void clear();
    void destroy();
    int length();
    T getPrior();
    T getNext();
    bool isEmpty();
    T operator[](int position);
    LinkedListIterator<T> createIterator();
private:
    struct _Node<T> * _head;
    struct _Node<T> * _current;
    struct _Node<T> * _prev;
};

template <class T>
class LinkedListIterator {
public:
    LinkedListIterator(LinkedList<T> *lst);
    virtual ~LinkedListIterator();
    T next();
    bool end();
private:
    struct _Node<T> * _cur;
    LinkedList<T> * list;
};

// -------IMPLEMENTATION------------

template <class T>
LinkedList<T>::LinkedList() {
    // Initialize
    _head = nullptr;
    _current = nullptr;
    _prev = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {

}

template <class T>
void LinkedList<T>::append(T value) {
    _current = new struct _Node<T>;
    _current->value = value;
    _current->next = nullptr;

    if(!_head) {
        _head = _current;
    } else {
        _prev->next = _current;
    }
    _prev = _current;
}

// Insert: T(n)=O(n)
template <class T>
void LinkedList<T>::insert(int position, T value){
    struct _Node<T> * item = new struct _Node<T>;
    _current = _head;
    int i;
    item -> value = value;
    for(i=0; i<position; i++) {
        _prev = _current;
        _current = _current->next;
        if(!_current->next){
            break;
        }
    }
    item->next = _current->next;
    _current->next = item;
}

template <class T>
void LinkedList<T>::remove(int position) {
    _current = _head;
    struct _Node<T> * now;
    int i;
    for(i=0; i<position-1; i++) {
        _prev = _current;
        _current = _current->next;
        if(!_current->next){
            return;
        }
    }
    now = _current->next;
    _current->next = now->next;
    delete now;
}

template <class T>
void LinkedList<T>::clear() {
    _prev = _head;
    _current = _head->next;
    if(!_head){
        return;
    }
    while(_prev->next){
        _prev->next = _current->next;
        delete _current;
        _current = _prev->next;
    }
    _current = nullptr;
    _prev = _head;
}

template <class T>
void LinkedList<T>::destroy() {
    clear();
    delete _head;
}

template <class T>
int LinkedList<T>::length() {
    struct _Node<T> * ptr = _head;
    int len = 0;
    while(ptr->next){
        len ++;
        ptr = ptr->next;
    }
    return len;
}

template <class T>
T LinkedList<T>::getPrior() {
    return _prev->value;
}

template <class T>
T LinkedList<T>::getNext() {
    return _current->next->value;
}

// Search: T(n)=O(n)
template <class T>
T LinkedList<T>::operator[](int position) {
    _current = _head;
    int i;
    for(i=0; i<position; i++){
        _prev = _current;
        _current = _current->next;
        if(!_current->next){
            break;
        }
    }
    return _current->value;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return (_head == nullptr);
}

template <class T>
LinkedListIterator<T> LinkedList<T>::createIterator() {
    LinkedListIterator<T> it(this);
    return it;
}

template <class T>
LinkedListIterator<T>::LinkedListIterator(LinkedList<T> * lst){
    list = lst;
    _cur = lst->_head;
}

template <class T>
LinkedListIterator<T>::~LinkedListIterator(){

}

template <class T>
T LinkedListIterator<T>::next(){
    if(!_cur){
        T empty;
        return empty;
    }
    T value = _cur->value;
    _cur = _cur->next;
    return value;
}

template <class T>
bool LinkedListIterator<T>::end() {
    if(!_cur) {
        return true;
    } else {
        return false;
    }
}

#endif // LINKED_LIST_H
