// 循环队列

#include "queue.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Queue q;
    int input;
    cout << "Enter a positive number to push into the queue." << endl;
    cout << "Enter -1 to pop an element from the queue." << endl;
    cout << "Enter 0 to end the program." << endl;
    while(true){
        cout << "> ";
        cin >> input;
        if(input > 0){
            if(!q.append(input)){
                cout << "Warning: The queue has been full and upperflown." << endl;
            }
        } else if(input == 0){
            break;
        } else {
            int val = q.pop();
            if(!val){
                cout << "Warning: The queue is empty." << endl;
            } else {
                cout << val << endl;
            }
        }
    }
    return 0;
}