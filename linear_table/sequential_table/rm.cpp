#include <iostream>
#include "list.h"

using namespace std;

int main(int argc, char const *argv[])
{
    List list;
    int start, length;
    cout << "Please enter a series of positive numbers. Enter zero or a negative number to end." << endl;
    while(true) {
        int value;
        cout << "> ";
        cin >> value;
        if (value <= 0) {
            break;
        }
        list.append(value);
    }

    cout << "Start index to remove - Less than " << list.getCount() << ":" << endl;
    cin >> start;
    if(start >= list.getCount()){
        cout << "Index out of range." << endl;
        return 1;
    }
    cout << "How many to delete - 1 to " << list.getCount() - start << ":" << endl;
    cin >> length;
    if(length + start >= list.getCount()) {
        cout << "Index out of range." << endl;
        return 1;
    }
    // Remove [length] elements from [start]
    list.remove(start, length);
    // Print
    cout << "Result: " << endl;
    for(int i=0; i<list.getCount(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}