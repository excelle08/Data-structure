#include "set.h"

Set::Set(int length){
    data = new int[length];
    this->length = length;
    index = 0;
}

Set::~Set(){

}

void Set::append(int value){
    if(index >= length){
        return;
    }
    for(int i=0; i<=index; i++){
        if(value == data[i]){
            return;
        }
    }
    data[index] = value;
    index ++;
}

int Set::operator[](int index){
    if(index >= length){
        return 0;
    }
    return data[index];
}

int Set::getCount(){
    return index;
}

void Set::merge(Set &source){
    int len = source.getCount();
    for(int i=0; i<len; i++){
        this->append(source[i]);
    }   
}
