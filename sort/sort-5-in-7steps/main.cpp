#include <iostream>

template <typename T>
void sort5(T array[]);

template <typename T>
void exchange(T *v1, T *v2);

int main(int argc, char const *argv[])
{
    using namespace std;
    int array[5];
    cout << "Enter five numbers: " << endl;
    for(int i=0; i<5; i++){
        cin >> array[i];
    }    
    sort5(array);

    for(int i=0; i<5; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
    return 0;
}


template<typename T>
void sort5(T array[]){

    // Step 1

    if (array[2] > array[1]) {
        exchange(&array[2], &array[1]);
    }
    if (array[0] > array[3]) {
        exchange(&array[0], &array[3]);
    }
    if (array[1] > array[3]) {
        exchange(&array[1], &array[3]);
    }
    // Now we have 0 <= 3, 2 <= 1 <= 3
    // Rest of steps

    if(array[1] <= array[4]) {
        if(array[0] <= array[1]) {
            if(array[0] <= array[2]) {
                if(array[3] <= array[4]){
                    // 0,2,1,3,4
                    exchange(&array[1], &array[2]);
                    return;
                } else {
                    // 0,2,1,4,3
                    exchange(&array[1], &array[2]);
                    exchange(&array[3], &array[4]);
                    return;
                }
            } else {
                if(array[3] <= array[4]){
                    // 2,0,1,3,4
                    T tmp = array[2];
                    array[2] = array[1];
                    array[1] = array[0];
                    array[0] = tmp;
                    return;
                } else {
                    // 2,0,1,4,3
                    T tmp = array[2];
                    array[2] = array[1];
                    array[1] = array[0];
                    array[0] = tmp;
                    exchange(&array[3], &array[4]);
                    return;
                }
            }
        } else {
            if(array[0] <= array[4]) {
                if(array[3] <= array[4]) {
                    // 2,1,0,3,4
                    exchange(&array[0], &array[2]);
                    return;
                } else {
                    // 2,1,0,4,3
                    exchange(&array[0], &array[2]);
                    exchange(&array[3], &array[4]);
                    return;
                }
            } else {
                // 2,1,4,0,3
                T tmp = array[4];
                array[4] = array[3];
                array[3] = array[0];
                array[0] = array[2];
                array[2] = tmp;
                return;
            }
        }
    } else {
        if (array[2] <= array[4]){
            if(array[0] <= array[4]){
                if(array[0] <= array[2]){
                    // 0,2,4,1,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[1];
                    array[1] = array[2];
                    array[2] = tmp;
                    return;
                } else {
                    // 2,0,4,1,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[1];
                    array[1] = array[0];
                    array[0] = array[2];
                    array[2] = tmp;
                    return;
                }
            } else {
                if(array[0] <= array[1]){
                    // 2,4,0,1,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[1];
                    array[1] = tmp;
                    exchange(&array[0], &array[2]);
                    return;
                } else {
                    // 2,4,1,0,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[0];
                    array[0] = array[2];
                    array[2] = array[1];
                    array[1] = tmp;
                    return;
                }
            }
        } else {
            if(array[0] <= array[2]){
                if(array[0] <= array[4]){
                    // 0,4,2,1,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[1];
                    array[1] = tmp;
                    return;
                } else {
                    // 4,0,2,1,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[1];
                    array[1] = array[0];
                    array[0] = tmp;
                    return;
                }
            } else {
                if(array[0] <= array[1]){
                    // 4,2,0,1,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[1];
                    array[1] = array[2];
                    array[2] = array[0];
                    array[0] = tmp;
                    return;
                } else {
                    // 4,2,1,0,3
                    T tmp = array[4];
                    array[4] = array[3];
                    array[3] = array[0];
                    array[0] = tmp;
                    exchange(&array[1], &array[2]);
                    return;
                }
            }
        }
    }
}

template<typename T>
void exchange(T *v1, T *v2) {
    *v1 += *v2;
    *v2 += *v1;
    *v1 = *v2 - *v1;
    *v2 = *v2 - *v1*2;
}
