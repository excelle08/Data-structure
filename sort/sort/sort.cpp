#include "stack.h"

template <class T>
inline void swap(T *v1, T *v2) {
    T tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

template <class T>
void bubbleSort(T *data, int length) {
    for(int i = 0; i < length; i ++) {
        bool swapFlag = false;
        for(int j = 0; j < length - i - 1; j++) {
            if(data[j] > data[j+1]) {
                swap(&data[j], &data[j+1]);
                swapFlag = true;
            }
        }
        if(!swapFlag){
            // If swap did not happend in this loop, the array is already in order.
            break;
        }
    }
}


template <class T>
void bubbleSortEnhanced(T *data, int length) {
    // Enhanced bubble sort
    // Sort a n-length array by means of bubble sort
    // If elements after [x] have been in order, stop comparing them.
    int i = length - 1;
    while(i > 1) {
        int lastSwappedIndex = 1;
        for(int j = 0; j < i ; j++) {
            if(data[j] > data[j+1]){
                swap(&data[j], &data[j+1]);
                lastSwappedIndex = j;
            }
        }
        i = lastSwappedIndex;
    }
}

template <class T>
void cocktailSort(T *data, int length) {
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

template <class T>
void __quickSort_r(T *data, int start, int end) {
    if(start >= end){
        return;
    }
    T pivot = data[end];
    int left = start, right = end - 1;
    while(left < right) {
        while(left < right && data[left] < pivot) {
            left += 1;
        }
        while(left < right && data[right] >= pivot) {
            right -= 1;
        }
        swap(&data[left], &data[right]);
    }

    if(data[left] >= data[end]) {
        swap(&data[left], &data[end]);
    } else {
        left += 1;
    }

    __quickSort_r(data, start, left-1);
    __quickSort_r(data, left+1, end);
}

template <class T>
void quickSortR(T *data, int length){
    __quickSort_r(data, 0, length-1);
}

template <class T>
void quickSortI(T *data, int length){
    if(length <= 0){
        return;
    }

    Stack<struct range> rangeStack(length);
    rangeStack.push(range(0, length-1));
    while(!rangeStack.isEmpty()) {
        range r = rangeStack.pop();
        int left = r.start, right = r.end - 1;
        if(r.start >= r.end) {
            continue;
        }

        T pivot = data[r.end];
        while(left < right) {
            while(data[left] < pivot && left < right) {
                left ++;
            } 
            while(data[right] >= pivot && left < right) {
                right --;
            }
            swap(&data[left], &data[right]);           
        }

        if(data[left] >= data[r.end]) {
            swap(&data[left], &data[r.end]);
        } else {
            left ++;
        }

        rangeStack.push(range(r.start, left-1));
        rangeStack.push(range(left+1, r.end));
    }
}

inline int max(int x, int y) {
    return (x>=y)?x:y;
}

inline int min(int x, int y) {
    return (x<=y)?x:y;
}

template <class T>
inline void moveElementInArray(T *data, int prev_index, int new_index, int length) {
    int x = min(prev_index, new_index);
    int y = max(prev_index, new_index);
    for(int i=0; i<length; i++){
        if(i == x) {
            T tmp = data[prev_index];
            for(int j=y-1; j>=x; j--){
                data[j] = data[j+1];
            }
        }
         break;
    }
}

template <class T>
void insertionSort(T *data, int length) {
    for(int i = 1; i < length; i++) {
        if(data[i] < data[i-1]) {
            T tmp = data[i];
            int j;
            for(j = i - 1; j >= 0 && data[j] >= tmp; j --) {
                data[j+1] = data[j];
            }
            data[j+1] = tmp;
        }
    }
}

template <class T>
int binarySearch(T *data, int lowAddr, int highAddr, T key) {
    int mid = (lowAddr + highAddr) / 2;

    if(lowAddr >= highAddr) {
        return (data[lowAddr] < key) ? (lowAddr + 1) : lowAddr;
    }

    if(key > data[mid]) {
        return binarySearch(data, mid+1, highAddr, key);
    } else if(key < data[mid]) {
        return binarySearch(data, lowAddr, mid-1, key);
    } else {
        return mid+1;
    }

    return mid;
}

template <class T>
void binaryInsertionSort(T *data, int length) {
    for(int i = 1; i < length; i++) {
        int pos = binarySearch(data, 0, i, data[i]);
        T tmp = data[i];
        for(int j = i - 1; j >= pos; j --) {
            data[j+1] = data[j];
        }
        data[pos] = tmp;
    }
}

template <class T>
void shellSort(T *data, int length, int *stepsArray, int stepsCount) {
    if(stepsArray[stepsCount-1] != 1){
        return;
    }

    for(int k = 0; k < stepsCount; ++k){
        int step = stepsArray[k];
        for(int i = step; i < length; i++) {
            if(data[i] < data[i-step]) {
                T tmp = data[i];
                int j;
                for(j = i-step; j >= 0 && tmp < data[j]; j -= step) {
                    data[j + step] = data[j];
                }
                data[j+step] = tmp;
            }
        }
    }
}

template <class T>
void shellSort(T *data, int length) {
    for(int l = length >> 1; l > 0; l >>= 1) {
        int step = l;
        for(int i = step; i < length; i++) {
            if(data[i] < data[i-step]) {
                T tmp = data[i];
                int j;
                for(j = i-step; j >= 0 && tmp < data[j]; j -= step) {
                    data[j + step] = data[j];
                }
                data[j+step] = tmp;
            }
        }
    }
}


template <class T>
void simpleSelectionSort(T *data, int length) {
    for(int i = 0; i < length; i++) {
        T min = data[i];
        int minIndex = i;
        for(int j = i; j < length; j++) {
            if(data[j] < min) {
                min = data[j];
                minIndex = j;
            }
        }
        if(minIndex > i) {
            swap(&data[i], &data[minIndex]);
        }
    }
}

template <class T>
void __merge_sort(T *data, T *reg, int start, int end) {
    if(start >= end) {
        return;
    }

    int length = end - start;
    int mid = (end + start) / 2;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    __merge_sort(data, reg, start1, end1);
    __merge_sort(data, reg, start2, end2);

    int index = start;
    while(start1 <= end1 && start2 <= end2) {
        reg[index ++] = (data[start1] < data[start2]) ? data[start1 ++] : data[start2 ++];
    }
    while(start1 <= end1) {
        reg[index ++] = data[start1 ++];
    }
    while(start2 <= end2) {
        reg[index ++] = data[start2 ++];
    }
    for(index = start; index <= end; index ++) {
        data[index] = reg[index];
    }
}

template <class T>
void binaryMergingSort(T *data, int length){
    T *reg = new T[length];
    __merge_sort(data, reg, 0, length-1);
}