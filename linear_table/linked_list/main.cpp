#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // Create a list variable, and it initializes automatically when constructing.
    LinkedList list;
    // Append 100 numbers - T=O(n)
    for(int i = 0; i <= 100; i++) {
        list.append(i);
    }
    // Get the length
    cout << "Length: " << list.length() << endl;
    // Retrieve the 45th element. Use operator overload.
    int value = list[45];
    cout << "The 45th item of linked list: " << value << endl;
    // Get prior element
    cout << "Prior element: " << list.getPrior() << endl;
    // Get next element
    cout << "Next element: " << list.getNext() << endl;
    // Insert an element at 50
    list.insert(50, 999);
    cout << "Add an element 999 at 50" << endl;
    // Remove the 25th element
    list.remove(25);
    cout << "Remove 25th element" << endl;
    // Iterate and get all elements
    LinkedListIterator it = list.createIterator();
    while(!it.end()){
        cout << it.next() << ", ";
    }
    cout << endl;
    // Get emptiness, and clear
    cout << "Is empty: " << list.isEmpty() << endl;
    cout << "To be cleared...";
    list.clear();
    cout << "Cleared." << endl;
    cout << "Is empty: " << list.isEmpty() << endl;
    list.destroy();

    return 0;
}