#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 128

enum StackOptStatus{
    Ok,
    UpperFlow,
    UnderFlow
};

template <class Type>
class Stack
{
public:
    Stack(int length=STACK_CAPACITY);
    ~Stack();
    int push(Type element);
    Type pop();
    bool isEmpty();
    bool isFull();
private:
    Type *data;
    int length;
    int index;
};

template <class Type>
Stack<Type>::Stack(int length){
    data = new Type[length];
    this->length = length;
    this->index = 0;
}

template <class Type>
Stack<Type>::~Stack(){

}

template <class Type>
int Stack<Type>::push(Type element) {
    if(index >= length){
        return UpperFlow;
    }
    data[index] = element;
    index ++;
    return Ok;
}

template <class Type>
Type Stack<Type>::pop() {
    Type result;
    if(index < 0){
        return UnderFlow;
    }
    result = data[index-1];
    index --;
    return result;
}

template <class Type>
bool Stack<Type>::isEmpty() {
    return index == 0;
}

template <class Type>
bool Stack<Type>::isFull() {
    return index == length;
}


#endif // STACK_H
