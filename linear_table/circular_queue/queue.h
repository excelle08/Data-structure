#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 100

struct _Node {
    int element;
};

class Queue {
public:
    Queue(int size=QUEUE_SIZE);
    ~Queue();
    int append(int value);
    int pop();
    bool isFull();
    bool isEmpty();
private:
    struct _Node *data;
    struct _Node *front, *rear;
    struct _Node *initial;
    int length;
    void moveFrontPtr();
    void moveRearPtr();
};

#endif // QUEUE_H
