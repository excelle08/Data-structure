#include <iostream>
#include "list.h"
#include "set.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Set s1, s2;
    cout << "Plz enter 10 numbers to form a set: " << endl;
    for(int i=0; i<10; i++){
        int value;
        cin >> value;
        s1.append(value);
    }
    cout << "Plz enter 10 numbers to form a set: " << endl;
    for(int i=0; i<10; i++){
        int val;
        cin >> val;
        s2.append(val);
    }
    s2.merge(s1);
    cout << "Result of merge: " << endl;
    int count = s2.getCount();
    for(int i=0; i<count; i++){
        cout << s2[i] << ' ';
    }
    cout << endl;

    List l1, l2;
    cout << "Plz enter 10 numbers to form a list: " << endl;
    for(int i=0; i<10; i++){
        int value;
        cin >> value;
        l1.append(value);
    }
    cout << "Plz enter 10 numbers to form a set: " << endl;
    for(int i=0; i<10; i++){
        int val;
        cin >> val;
        l2.append(val);
    }
    l2.merge(l1);
    int cnt = l2.getCount();
    for(int i=0; i<cnt; i++){
        cout << l2[i] << ' ';
    }
    cout << endl;
    return 0;
}