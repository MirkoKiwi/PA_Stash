#include <stdio.h> 


int binarySearch(int arr[], int left, int right, int x);
void printArray(int arr[], int size);



int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 20, 24, 26};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: \n");
    printArray(arr, size);

    int x = 11;

    int index = binarySearch(arr, 0, size - 1, x);

    printf("%d\n", index);

    ( index != -1 ) ? printf("x pos: %d\n", index) : printf("Not found\n");

    return 0;
}



int binarySearch(int arr[], int left, int right, int x) {
    while ( left <= right ) {
        int mid = left + ( right - left ) / 2;
        
        if ( arr[mid] == x ) {
            return mid;
        }
        else if ( arr[mid] < x ) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }  
    }

    return -1;
}


void printArray(int arr[], int size) {
    for ( int i = 0; i < size; i++ ) {
        printf("Element %d: %d\n", i, arr[i]);
    }
    printf("\n");
}