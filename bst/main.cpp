#include <iostream>
#include <cstdlib>
#include <cstring>
#include "tree.h"
#include <sys/time.h>
#include <ctime>

using namespace std;

bool verbose = false;

int main(int argc, char const *argv[])
{
    BST<int> tree;
    int *array, numbers;

    for(int i=1; i<argc; i++) {
        if(!strcmp(argv[i], "-v") || !strcmp(argv[i], "--verbose")) {
            verbose = true;
        }
    }

    cout << "How many numbers?" << endl;
    cin >> numbers;

    array = new int[numbers];

    srand(time(nullptr));
    for(int i=0; i<numbers; i++) {
        int r = rand() / 10000000;
        array[i] = r;
        if(verbose) {
            cout << r << ' ';
        }
    }
    cout << endl;

    for(int i=0; i<numbers; i++) {
        tree.insert(array[i]);
    }

    cout << "Traverse the tree:" << endl;
    tree.traverse([](int data){
        cout << data << ' ';
    });
    cout << endl;

    cout << "Search the " << numbers / 2 << "th number: " << array[numbers/2-1] << endl;
    struct treeNode<int> *n = tree.search(array[numbers/2-1]);
    cout << "Addr: " << n << ";Val: " << n->data << ";Left=" << n->leftChild << ";Right=" << n->rightChild << endl;

    cout << "Delete the " << numbers / 2 << "th number" << endl;

    bool state = tree.deleteNode(array[numbers/2-1]);

    tree.traverse([](int data){
        cout << data << ' ';
    });
    cout << endl;

    cout << "Insert 128, 64, 32" << endl;
    tree.insert(128);
    tree.insert(32);
    tree.insert(64);

    tree.traverse([](int data){
        cout << data << ' ';
    });
    cout << endl;

    return 0;
}

