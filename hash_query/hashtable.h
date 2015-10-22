#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "hash.h"
#include "LinkedList.h"

#include <cstring>

template <class KeyType, class DataType>
struct HashElement{
    KeyType key;
    DataType data;
};

typedef unsigned short int_16;

template <class KeyType, class DataType>
class HashTable
{
public:
    HashTable();
    virtual ~HashTable();
    void insert(KeyType key, DataType data);
    DataType get(KeyType key);
    bool remove(KeyType key);

private:
    LinkedList<HashElement<KeyType, DataType> > *hTable;
    int_16 __getHashCode(KeyType key);
    const char * __convertKey(KeyType key);
};



template <class KeyType, class DataType>
HashTable<KeyType, DataType>::HashTable() {
    hTable = new LinkedList<struct HashElement<KeyType, DataType> > [65536];
}

template <class KeyType, class DataType>
HashTable<KeyType, DataType>::~HashTable() {
    delete [] hTable;
}

template <class KeyType, class DataType>
void HashTable<KeyType, DataType>::insert(KeyType key, DataType data) {
    struct HashElement<KeyType, DataType> element;
    element.key = key;
    element.data = data;
    int_16 addr = __getHashCode(key);
    std::cout << std::endl << "Addr=" <<  addr << std::endl << std::endl;
    hTable[addr].append(element);
}

template <class KeyType, class DataType>
DataType HashTable<KeyType, DataType>::get(KeyType key) {
    int_16 addr = __getHashCode(key);
    LinkedList<struct HashElement<KeyType, DataType> > elementList = hTable[addr];

    DataType empty;

    if(elementList.isEmpty()) {
        return empty;
    }

    LinkedListIterator<HashElement<KeyType, DataType> > it = elementList.createIterator();
    while(!it.end()) {
        struct HashElement<KeyType, DataType> item = it.next();
        if(item.key == key) {
            return item.data;
        }
    }
    return empty;
}

template <class KeyType, class DataType>
bool HashTable<KeyType, DataType>::remove(KeyType key) {
    int_16 addr = __getHashCode(key);
    LinkedList<struct HashElement<KeyType, DataType> > elementList = hTable[addr];

    if(elementList.isEmpty()) {
        return false;
    }

    for(int i=0; i<elementList.length(); i++) {
        if(elementList[i].key == key) {
            elementList.remove(i);
            return true;
        }
    }
    return false;
}

using namespace std;
template <class KeyType, class DataType>
int_16 HashTable<KeyType, DataType>::__getHashCode(KeyType key) {
    const char * keyStr = __convertKey(key);
    Hash hashObj(keyStr, sizeof(key));
    return hashObj.crc16();
}

template <class KeyType, class DataType>
const char * HashTable<KeyType, DataType>::__convertKey(KeyType key) {
    size_t keySize = sizeof(key);
    char *keyStr = new char[keySize];
    memcpy(keyStr, &key, keySize);
    return keyStr;
}

#endif // HASHTABLE_CPP