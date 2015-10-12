#include <iostream>
#include <sys/time.h>

using namespace std;

bool verbose = false;

long getCurrentTime();
void arrayCopy(int *, const int *, int);
void printTheArray(int *data, int len);

template <class T>
void testAlgorithm(const T *data, int dataLen, void (*func)(T *, int), string desc){
    int *data2 = new int[dataLen];
    long start, end;

    arrayCopy(data2, data, dataLen);
    cout << desc << endl;

    start = getCurrentTime();
    func(data2, dataLen);
    end = getCurrentTime();
    printTheArray(data2, dataLen);

    cout << "Time elasped: " << (end - start) << " ms" << endl << "------------------" << endl;
}

template <class T>
inline void swap(T *v1, T *v2) {
    T tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

template <class T>
void dualBubbleSort(T *data, int length) {
    int left = 0, right = length - 1, flag = 1;
    while(left < right) {
        for(int i=left; i < right; i++){
            if(data[i] > data[i+1] ) {
                swap(&data[i], &data[i+1]);
                flag = i;
            }
        }
        right = flag;
        for(int i=right-1; i >= left; i--){
            if(data[i] > data[i+1]) {
                swap(&data[i], &data[i+1]);
                flag = i;
            }
        }
        left = flag + 1;
    }
}

void printTheArray(int *data, int len) {
    if(!verbose) {
        return;
    }

    for(int i=0; i<len; i++){
        cout << data[i] << ' ';
    }
    cout << endl;
}

void arrayCopy(int *desc, const int *src, int length){
    for(int i=0; i<length; i++){
        desc[i] = src[i];
    }
}

long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
}    

int main(int argc, char const *argv[])
{
    int dataCounts;
    cout << "How many numbers? ";
    cin >> dataCounts;
    int *data = new int [dataCounts];

    // Parse CLI arguments

    for(int i = 1; i < argc; i++){
        if(!strcmp(argv[i], "--verbose") || !strcmp(argv[i], "-v")) {
            verbose = true;
        }
    }

    // Initialize the random seed and fill the array
    srand(time(nullptr));
    for(int i = 0; i < dataCounts; i ++){
        data[i] = rand() / 1000000;
        if(verbose) {
            cout << data[i] << ' ';
        }
    }

    cout << endl;

    testAlgorithm(data, dataCounts, &dualBubbleSort, "Dual-way bubble sort / Cocktail sort");

    return 0;
}