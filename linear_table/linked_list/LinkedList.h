#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef NULL
#define NULL 0
#endif // NULL

struct _Node {
    int value;
    struct _Node *next;    
};

class LinkedListIterator;

class LinkedList {
public:
    friend class LinkedListIterator;
    LinkedList();
    virtual ~LinkedList();
    void append(int value);
    void insert(int position, int value);
    void remove(int position);
    void clear();
    void destroy();
    int length();
    int getPrior();
    int getNext();
    bool isEmpty();
    int operator[](int position);
    LinkedListIterator createIterator();
private:
    struct _Node * _head;
    struct _Node * _current;
    struct _Node * _prev;
};

class LinkedListIterator {
public:
    LinkedListIterator(LinkedList *lst);
    virtual ~LinkedListIterator();
    int next();
    bool end();
private:
    struct _Node * _cur;
    LinkedList * list;
};

#endif // LINKED_LIST_H
