#include "list.h"

List::List(int length){
    data = new int[length];
    this->length = length;
    index = 0;
}

List::~List(){

}

void List::append(int value){
    if(index >= length){
        return;
    }
    data[index] = value;
    index ++;
}

int List::operator[](int index){
    if(index >= length){
        return 0;
    }
    return data[index];
}

int List::getCount(){
    return index;
}

void List::merge(List &source){
    int len = source.getCount();
    for(int i=0; i<len; i++){
        this->append(source[i]);
    }
    this->sort();
}

void List::sort(bool asc){
    for(int i=0; i<index; i++){
        for(int j=0; j<index - i - 1; j++){
            if(data[j] >= data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}