#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define NUM_ELEMENTS 100



int pow2i(int exponent);

// Prints binary tree in a cute format
void displayTree(const int *arr, int arrlen); 


void printArray(const int arr[], int size) {
    printf("[");
    for ( int i = 0; i < size; i++ ) {
        printf("%4d", arr[i]);
    }
    printf("  ]\n\n");
}


// Function pointer
typedef bool (*Compare)(int, int);

bool maxBuild(int x, int y) { return x < y; }
bool minBuild(int x, int y) { return x > y; }


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Heap - Node access for zero-based binary heaps
int parent(int i) { return ( i - 1 ) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }



void heapify(int arr[], int index, int heapSize, Compare comp) {
    int leftIndex, rightIndex, maxIndex, max;
    leftIndex = left(index);
    rightIndex = right(index);

    // Left child existing and being of "compare" value    
    if ( leftIndex < heapSize && comp(arr[leftIndex], arr[index]) ) { 
        maxIndex = leftIndex;
    }
    else {   // Left child non-existant or has not "compare" value
        maxIndex = index;
    }

    // Right child existing and being of "compare" value
    if ( rightIndex < heapSize && comp(arr[rightIndex], arr[maxIndex]) ) {
        maxIndex = rightIndex;
    }
    // If right child is non-existant, the resulting maxIndex will be the current index as computed earlier


    // If arr[index] is already max, we're done, otherwise:
    if ( maxIndex != index ) {
        swap(&arr[maxIndex], &arr[index]);

        // Apply heapify() after the swap
        heapify(arr, maxIndex, heapSize, comp);
    }
}

void buildHeap(int arr[], int heapSize, Compare comp){
    for ( int i = parent(heapSize - 1); i >= 0; i-- ) {
        heapify(arr, i,  heapSize, comp);
    }
}

void heapSort(int arr[], int heapSize, Compare comp){
    buildHeap(arr, heapSize, comp);
    for ( int i = heapSize; i > 1; i-- ) {
        // Swap root with last element
        swap(&arr[i-1], &arr[0]);

        heapify(arr, 0, i-1, comp);
    }
}

int main() {
    int nEl = 13;
    int arr[NUM_ELEMENTS] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1, -1};
    // int arr[13] = {16, 15, 10, 14, 7, 9, 3, 2, 8, 1, -1, -1, -1};
    int heapSize = 10;
    int i = 1; // nodo da alterare


    printArray(arr, heapSize);
    displayTree(arr, heapSize);

    buildHeap(arr, heapSize, minBuild);
    printArray(arr, heapSize);
    displayTree(arr, heapSize);

    heapSort(arr, heapSize, maxBuild);
    printArray(arr, heapSize);
    displayTree(arr, heapSize);

    return 0;
}



// ----------------------------------------------
// Helper functions for printing heap in tree format


int pow2i(int exponent) {
    int result = 1;
    while ( exponent-- ) {
        result *= 2;
    }
    return result;
}

void displayTree(const int arr[], int arrSize) {
    int longestDigits = 0;
    int treeDepth = 0;

    int pos = 0;
    int depth = 0;
    for ( int i = 0; i < arrSize; ++i ) {
        if ( arr[i] != -1 ) {
            const int len = snprintf(NULL, 0, "%d", arr[i]);
            if ( longestDigits < len ) {
                longestDigits = len;
            }
        }
        
        if ( pos == 0 ) {
            treeDepth++;
            pos = pow2i(depth++);
        }
        pos--;      
    }

    //printf("%d %d\n", longestDigits, treeDepth);

    pos = 0;
    depth = 0;
    const int additionalOffset = 3;
    int maxWidth = pow2i(treeDepth) * (longestDigits + additionalOffset);
    for ( int i = 0; i < arrSize; ++i ) {
        const bool first = ( pos == 0 );
        if ( first ) {
            pos = pow2i(depth);
            depth++;
        }
        const int countElems = pow2i(depth);
        const int chunk = maxWidth / countElems;
        const int width = chunk + ( first ? -chunk / 2 : 0 );
        const int preSpaces = width - longestDigits;

        printf("%*s", preSpaces, "");
        if ( arr[i] == -1 ) {
            printf("%*s", longestDigits, "-");
        } 
        else {
            printf("%*d", longestDigits, arr[i]);
        }

        if ( pos == 1 ) {
            printf("\n");
        }
        pos--;
    }
    printf("\n\n");
}
