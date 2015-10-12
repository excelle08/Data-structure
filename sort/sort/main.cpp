#include <iostream>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/time.h>   
#include "sort.cpp"   

void printTheArray(int *data, int len);
void arrayCopy(int *, const int *, int);
long getCurrentTime();

using namespace std;

bool verbose = false;
bool noBubble = false;
bool noInsertion = false;
bool noShell = false;


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

int main(int argc, char const *argv[])
{
    int dataCounts;
    long int start, end;
    cout << "How many numbers? ";
    cin >> dataCounts;
    int *data = new int [dataCounts];

    // Parse CLI arguments

    for(int i = 1; i < argc; i++){
        if(!strcmp(argv[i], "--verbose") || !strcmp(argv[i], "-v")) {
            verbose = true;
        }
        if(!strcmp(argv[i], "--no-bubble") || !strcmp(argv[i], "-nb")) {
            noBubble = true;
        }
        if(!strcmp(argv[i], "--no-insertion") || !strcmp(argv[i], "-ni")) {
            noInsertion = true;
        }
        if(!strcmp(argv[i], "--no-shell") || !strcmp(argv[i], "-ns")) {
            noShell = true;
        }
    }

    // Initialize the random seed and fill the array
    srand(time(nullptr));
    for(int i = 0; i < dataCounts; i ++){
        data[i] = rand() / 1000000;
        //data[i] = i;
        if(verbose) {
            cout << data[i] << ' ';
        }
    }

    cout << endl;

    if(!noInsertion) {
        testAlgorithm(data, dataCounts, &insertionSort, "Insertion sort");
        testAlgorithm(data, dataCounts, &binaryInsertionSort, "Binary insertion sort");
    }

    if(!noBubble) {
        testAlgorithm(data, dataCounts, &bubbleSort, "Bubble sort");
        testAlgorithm(data, dataCounts, &bubbleSortEnhanced, "Enhanced bubble sort");
        testAlgorithm(data, dataCounts, &cocktailSort, "Cocktail / Dual-way bubble sort");
    }

    //testAlgorithm(data, dataCounts, &simpleSelectionSort, "Simple selection sort");

    testAlgorithm(data, dataCounts, &binaryMergingSort, "Binary merging sort");

    testAlgorithm(data, dataCounts, &quickSortR, "Quick sort / recursive");

    testAlgorithm(data, dataCounts, &quickSortI, "Quick sort / iterative");

    if(!noShell) {
        int *data6 = new int[dataCounts];
        int steps[] = {5,3,1};
        arrayCopy(data6, data, dataCounts);
        // Shell sort - with fixed steps
        cout << "Shell sort - With 5,3,1 steps:" << endl;
        start = getCurrentTime();
        shellSort(data6, dataCounts, steps, 3);
        end = getCurrentTime();
        printTheArray(data6, dataCounts);
        cout << "Time elasped: " << (end - start) << " ms" << endl << "--------------------" << endl;
    
        testAlgorithm(data, dataCounts, &shellSort, "Shell sort with automated steps");
    }

    int *data100 = new int[dataCounts];
    arrayCopy(data100, data, dataCounts);
    // System qsort
    cout << "QSort in C library:" << endl;
    start = getCurrentTime();
    // This is a C++11 feature - anonymous function.
    qsort(data100, dataCounts, sizeof(int), [](const void *a, const void *b){
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        if(arg1 == arg2){
            return 0;
        } else {
            return (arg1 > arg2) ? 1 : -1;
        }
    });
    end = getCurrentTime();
    printTheArray(data100, dataCounts);
    cout << "Time elasped: " << (end - start) << " ms" << endl  << "--------------------" << endl;
    return 0;
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
