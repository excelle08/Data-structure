#ifndef QUEUE_H
#define QUEUE_H


template <class T>
struct _Node{
    T value;
    struct _Node<T> *next;
};

template <class T>
class Iterator;

template <class T>
class Queue
{
public:
    friend class Iterator<T>;
    Queue() {
        _initNode();
    }

    virtual ~Queue() {

    }

    void append(T value) {
        _appendNode(value);
    }

    Iterator<T> createIterator() {
        return Iterator<T>(this);
    }

    T get() {
        return _popFirstNode();
    }

    bool isEmpty() {
        return _head == _prev;
    }

private:
    struct _Node<T> *_head;
    struct _Node<T> *_current;
    struct _Node<T> *_prev;
    void _initNode() {
        // nullptr is a C++11 feature
        _head = _current = _prev = nullptr;
    }

    void _appendNode(T val) {
        _current = new struct _Node<T>;
        _current->value = val;
        _current->next = nullptr;
        if(!_head) {
            _head = _current;
        } else {
            _prev->next = _current;
        }

        _prev = _current;
    }

    T _popFirstNode() {
        T value = _head->value;
        struct _Node<T> *tmp = _head->next;
        delete _head;
        _head = tmp;
        return value;
    }
};

template <class T>
class Iterator
{
public:
    Iterator(Queue<T> * q) {
        _queue = q;
        _cur = _queue->_head;
    }

    virtual ~Iterator() {

    }

    T next() {
        if(!_cur) {
            return false;
        }
        T value = _cur->value;
        _cur = _cur->next;

        return value;
    }
private:
    Queue<T> *_queue;
    struct _Node<T> *_cur;
};


#endif // QUEUE_H
