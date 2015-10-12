#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    // Initialize
    _head = NULL;
    _current = NULL;
    _prev = NULL;
}

LinkedList::~LinkedList() {

}

void LinkedList::append(int value) {
    _current = new struct _Node;
    _current->value = value;
    _current->next = NULL;

    if(!_head) {
        _head = _current;
    } else {
        _prev->next = _current;
    }
    _prev = _current;
}

// Insert: T(n)=O(n)
void LinkedList::insert(int position, int value){
    struct _Node * item = new struct _Node;
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

void LinkedList::remove(int position) {
    _current = _head;
    struct _Node * now;
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

void LinkedList::clear() {
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
    _current = NULL;
    _prev = _head;
}

void LinkedList::destroy() {
    clear();
    delete _head;
}

int LinkedList::length() {
    struct _Node * ptr = _head;
    int len = 0;
    while(ptr->next){
        len ++;
        ptr = ptr->next;
    }
    return len;
}

int LinkedList::getPrior() {
    return _prev->value;
}

int LinkedList::getNext() {
    return _current->next->value;
}

// Search: T(n)=O(n)
int LinkedList::operator[](int position) {
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

bool LinkedList::isEmpty() {
    return (_head->next == NULL);
}

LinkedListIterator LinkedList::createIterator() {
    LinkedListIterator it(this);
    return it;
}

LinkedListIterator::LinkedListIterator(LinkedList * lst){
    list = lst;
    _cur = lst->_head;
}

LinkedListIterator::~LinkedListIterator(){

}

int LinkedListIterator::next(){
    if(!_cur){
        return 0;
    }
    int value = _cur->value;
    _cur = _cur->next;
    return value;
}

bool LinkedListIterator::end() {
    if(!_cur) {
        return true;
    } else {
        return false;
    }
}