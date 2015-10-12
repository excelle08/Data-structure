#include "queue.h"

Queue::Queue(){
	_initNode();
}

Queue::~Queue(){
}

void Queue::append(int value){
	_appendNode(value);
}

Iterator Queue::createIterator(){
	return Iterator(this);
}

int Queue::get(){
	return _popFirstNode();
}

void Queue::_initNode(){
	_head = NULL;
	_current = NULL;
	_prev = NULL;
}

void Queue::_appendNode(int val){
	_current = new struct _Node;
	_current -> value = val;
	_current -> next = NULL;
	if(_head == NULL){
		_head = _current;
	} else {
		_prev -> next = _current;
	}
	_prev = _current;
}

int Queue::_popFirstNode(){
	int value = _head -> value;
	struct _Node *tmp = _head->next;
	delete _head;
	_head = tmp;
	return value;
}
Iterator::Iterator(Queue * q){
	_queue = q;
	_cur = _queue->_head;
}

Iterator::~Iterator(){
}

int Iterator::next(){
	if(_cur == NULL){
		throw "Iteration is over.";
	}
	int value = _cur->value;
	_cur = _cur->next;
	return value;
}