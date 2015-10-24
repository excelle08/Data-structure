#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <deque>
#include <iostream>
using namespace std;

template <class T>
class Heap {
public:
    Heap();
    virtual ~Heap();
    void insert(T element);
    void print() {
        for(int i=0; i<tree.size(); i++) {
            cout << tree[i] << ' ';
        }
        cout << endl;
    }
    T popTop();
private:
    deque<T> tree;
    T getTopElement();
    void removeTop();
    void update(int i=0);
};

template <class T>
void heapSort(T *data, int length);

template <class T>
void __swap(T &v1, T &v2);

/********** Implementation ************/
template <class T>
Heap<T>::Heap() {

}

template <class T>
Heap<T>::~Heap() {
    tree.clear();
}

template <class T>
void Heap<T>::insert(T element) {
    tree.push_back(element);
    for(int i = tree.size() - 1; i >= 0 && tree[i/2] > tree[i]; i /= 2) {
        __swap(tree[i], tree[i/2]);
    }
}

template <class T>
T Heap<T>::popTop() {
    T e = getTopElement();
    removeTop();
    return e;
}

template <class T>
T Heap<T>::getTopElement() {
    return tree[0];
}

template <class T>
void Heap<T>::removeTop() {
    T tmp = tree.back();
    tree[0] = tmp;
    tree.pop_back();
    update();
}

// Re-order the tree to make it a heap from the top
template <class T>
void Heap<T>::update(int i) {
    int minimum = i;        // Initial suppose
    int left = 2*i, right = 2*i+1;
    if(left < tree.size() && tree[left] < tree[minimum]) {
        minimum = left;
    }
    if(right < tree.size() && tree[right] < tree[minimum]) {
        minimum = right;
    }
    if(minimum != i) {
        __swap(tree[i], tree[minimum]);
        update(minimum);
    }
}


template <class T>
void __swap(T &v1, T &v2) {
    T tmp = v2;
    v2 = v1;
    v1 = tmp;
}

template <class T>
void heapSort(T *data, int length) {
    Heap<T> heap;
    for(int i=0; i<length; i++) {
        heap.insert(data[i]);
    }

    for(int i=0; i<length; i++) {
        data[i] = heap.popTop();
    }
}

#endif // HEAP_SORT_H
