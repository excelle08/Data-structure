#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "hash.h"
#include "LinkedList.h"

#include <sstream>
#include <string>

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

private:
    LinkedList<HashElement<KeyType, DataType> > *hTable;
    int_16 __getHashCode(KeyType key);
    const std::string __convertKey(KeyType key);
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
    std::cout << std::endl << "Addr=" <<  addr << std::endl;
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

using namespace std;
template <class KeyType, class DataType>
int_16 HashTable<KeyType, DataType>::__getHashCode(KeyType key) {
    string keyStr = __convertKey(key);
    Hash hashObj(keyStr.c_str(), keyStr.length());
    return hashObj.crc16();
}

template <class KeyType, class DataType>
const std::string HashTable<KeyType, DataType>::__convertKey(KeyType key) {
    ostringstream oss;
    oss << key;
    return oss.str();
}

#endif // HASHTABLE_CPP