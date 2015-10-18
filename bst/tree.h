#ifndef TREE_H
#define TREE_H

#include "queue.h"

template <class T>
struct treeNode {
    T data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

template <class T>
class BST {
public:
    BST() {
        _root = nullptr;
    }

    virtual ~BST() {

    }

    void insert(T value) {
        _insert(&_root, value);
    }

    void load(Queue<T> q) {
        while(!q.isEmpty()){
            insert(q.get());
        }
    }

    struct treeNode<T> * search(T key) {
        struct treeNode<T> *node;
        bool searchState = _search(_root, key, nullptr, &node);
        return searchState ? node : nullptr;
    }

    bool deleteNode(T key) {
        struct treeNode<T> *node = _root;
        bool searchState = _search(_root, key, nullptr, &node);
        return searchState ? _deleteCurrent(node) : false;
    }

    void traverse(void (*callback)(T value), struct treeNode<T> *ptr=nullptr, bool begin=false) {
        if(!_root) {
            return;
        }
        if(!ptr) {
            if(!begin){
                ptr = _root;
            } else {
                return;
            }
        }
        traverse(callback, ptr->leftChild, true);
        callback(ptr->data);
        traverse(callback, ptr->rightChild, true);
    }
private:
    struct treeNode<T> *_root;

    void _insert(struct treeNode<T> **ptr, T value) {
        if(!(*ptr)) {
            struct treeNode<T> *node = new struct treeNode<T>;
            node->leftChild = node->rightChild = nullptr;
            node->data = value;
            *ptr = node;
        } else {
            if((*ptr)->data == value) {
                return;
            } else if ((*ptr)->data > value) {
                _insert(&((*ptr)->leftChild), value);
            } else {
                _insert(&((*ptr)->rightChild), value);
            }
        }
    }

    bool _search(struct treeNode<T> *ptr, T key, struct treeNode<T> *parent, struct treeNode<T> **buffer) {
        if(!ptr) {
            *buffer = parent;
            return false;
        }
        if(ptr->data == key) {
            *buffer = ptr;
            return true;
        } else if(ptr->data > key) {
            return _search(ptr->leftChild, key, ptr, buffer);
        } else {
            return _search(ptr->rightChild, key, ptr, buffer);
        }
    }

    inline bool _deleteCurrent(struct treeNode<T> *current) {
        if(!(current)) {
            return false;
        }
        if(!(current)->leftChild && !(current)->rightChild) {
            delete current;
            current = nullptr;
        } else if (!(current)->rightChild) {
            struct treeNode<T> *p = (current)->leftChild;
            (current)->data = p->data;
            (current)->leftChild = p->leftChild;
            (current)->rightChild = p->rightChild;
            delete p;
        } else if (!(current)->leftChild) {
            struct treeNode<T> *p = (current)->rightChild;
            (current)->data = p->data;
            (current)->leftChild = p->leftChild;
            (current)->rightChild = p->rightChild;
            delete p;
        } else {
            struct treeNode<T> *p = current;
            struct treeNode<T> *s = (current)->leftChild;
            while(s->rightChild) {
                p = s;
                s = s->rightChild;
            }
            (current)->data = s->data;
            if(p != current) {
                p->rightChild = s->leftChild;
            } else {
                p->leftChild = s->leftChild;
            }
            delete s;
        }

        return true;
    }
};

#endif // TREE_H
