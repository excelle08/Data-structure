#ifndef SET_H
#define SET_H

#define DEFAULT_SET_SIZE 100

class Set
{
public:
    Set(int length = DEFAULT_SET_SIZE);
    ~Set();
    void append(int value);
    void merge(Set &source);
    int operator[](int index);
    int getCount();
private:
    int *data;
    int length;
    int index;
};

#endif // SET_H
