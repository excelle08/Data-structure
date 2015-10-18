#include <iostream>
#include "hashtable.h"

using namespace std;

int main(int argc, char const *argv[])
{
    HashTable<string, string> table;

    cout << "Demo for hash table" << endl;
    cout << "Please enter key and value. Enter exit to end input" << endl;

    while(true) {
        string key, value;
        cout << "Key >>";
        cin >> key;
        cout << "Value >>";
        cin >> value;
        if(key == "exit" || value == "exit") {
            break;
        }

        table.insert(key, value);
    }

    cout << "Now enter key to search for content. Enter exit to end." << endl;

    while(true) {
        string key;
        cout << "Key >>";
        cin >> key;
        if(key == "exit") {
            break;
        }

        cout << "Value: " << table.get(key) << endl;
    }
    return 0;
}