#include <iostream>
#include <string>
#include "hashtable.h"

using namespace std;

int main(int argc, char const *argv[])
{
    HashTable<string, string> table;

    cout << "Demo for hash table" << endl;
    cout << "Please enter key and value. Enter exit to end input" << endl;

    while(true) {
        string key, value;
        cout << "Key >> ";
        getline(cin, key);
        cout << "Value >> ";
        getline(cin, value);
        if(key == "exit" || value == "exit") {
            break;
        }

        table.insert(key, value);
    }

    cout << "Now enter key to search for content. Enter exit to end." << endl;

    while(true) {
        string key;
        cout << "Key >> ";
        getline(cin, key);
        if(key == "exit") {
            break;
        }

        cout << "Value: " << table.get(key) << endl;
    }
    return 0;
}