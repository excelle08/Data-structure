#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_SIZE 100

class List {
public:
    List(int length = DEFAULT_LIST_SIZE);
    ~List();
    void append(int value);
    int operator[](int index);
    void merge(List &source);
    int getCount();
    void sort(bool asc=true);
private:
    int *data;
    int length;
    int index;
};

#endif // LIST_H
