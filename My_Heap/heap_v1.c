#include <stdio.h>



#define NUM_ELEMENTS 100


void printArray(int arr[], int size) {
    printf("[");
    for ( int i = 0; i < size; i++ ) {
        printf("%4d", arr[i]);
    }
    printf("  ]");
}


// Heap - Node access for zero-based binary heaps
int parent(int i) { return ( i - 1 ) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * 2 + 1; }


void exploreHeap(int arr[], int heapSize, int index) {
    int parentIndex, leftIndex, rightIndex;
    if ( index >= heapSize ) {
        printf("Node %d not in heap\n", index);
    }
    else {
        printf("Node %d, Value: %d -> ", index, arr[index]);

        // Parent node
        if ( index > 0 ) {
            parentIndex = parent(index);
            printf("| Parent: %d, Value: %d | ", parentIndex, arr[parentIndex]);
        }
        else {
            printf("| Root, no parent node | ");
        }

        // Left node
        leftIndex = left(index);
        if ( leftIndex < heapSize ) {
            printf("| Left: element %d, Value %d | ", leftIndex, arr[leftIndex]);
        }
        else {
            printf("| No left node | ");
        }

        // Right node
        rightIndex = right(index);
        if ( rightIndex < heapSize ) {
            printf("| Right: element %d, Value %d | ", rightIndex, arr[rightIndex]);
        }
        else {
            printf("| No right node | ");
        }
    }
    printf("\n");
}



int main() {
    int i;
    int vett[NUM_ELEMENTS] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1, -1};
    int heapSize = 11;

    for ( i = 0; i< heapSize + 1; i++ ){
        exploreHeap(vett, heapSize, i);

    }
    i = 11;

    return 0;
}