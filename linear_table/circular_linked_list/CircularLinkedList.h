#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct _Node {
    int value;
    struct _Node *next;    
};

class CircularLinkedListIterator;

class CircularLinkedList
{
public:
    friend class CircularLinkedListIterator;
    CircularLinkedList();
    ~CircularLinkedList();
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
    CircularLinkedListIterator createIterator();
private:
    struct _Node * _head;
    struct _Node * _current;
    struct _Node * _prev;
};

#endif // CIRCULAR_LINKED_LIST_H
