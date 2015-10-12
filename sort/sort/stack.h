#ifndef STACK_H
#define STACK_H


#define DEFAULT_SIZE 1024


struct range{
    int start;
    int end;
    range(int start=0, int end=0){
        this->start = start;
        this->end = end;
    }
};

template <class T>
class Stack
{
public:
    Stack(int size=DEFAULT_SIZE){
        data = new T[size];
        index = 0;
        length = size;
    }

    ~Stack(){
        delete [] data;
    }

    void push(T value){
        data[index] = value;
        index += 1;
    }

    T pop(){
        index --;
        return data[index];
    }

    bool isEmpty(){
        return !index;
    }

    bool isFull(){
        return index == length;
    }
private:
    T *data;
    int index;
    int length;
};

#endif // STACK_H
