#include "queue.h"

Queue::Queue(int size){
    data = new struct _Node[size+1];
    front = data;
    rear = data + 1;
    initial = data;
    length = size;
}

Queue::~Queue(){

}

int Queue::append(int value){
    if(rear == front){
        return 0;
    }
    rear->element = value;
    moveRearPtr();
    return 1;
}

int Queue::pop(){
    int result;
    if(front + 1 == rear){
        return 0;
    }
    result = (front+1)->element;
    moveFrontPtr();
    return result;
}

bool Queue::isFull(){
    return front == rear;
}

bool Queue::isEmpty(){
    return front + 1 == rear;
}

void Queue::moveFrontPtr(){
    front = initial + (front + 1 - initial) % length;
}

void Queue::moveRearPtr(){
    rear = initial + (rear + 1 - initial) % length;
}