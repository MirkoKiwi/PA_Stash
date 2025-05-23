#include <stdio.h>
#include <stdbool.h>

typedef bool (*Compare)(int, int);

bool ascending(int x, int y) { return x < y; }
bool descending(int x, int y) { return x > y; }


void merge(int arr[], int left, int mid, int right, Compare comp);
void mergeSort(int arr[], int left, int right, Compare comp);

void bubbleSort(int arr[], int size, Compare comp);
void insertionSort(int arr[], int size, Compare comp);
void selectionSort(int arr[], int size, Compare comp);

int binarySearch(int arr[], int left, int right, int x);


void printArray(int arr[], int size);
void swap(int *x, int *y);


// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 32, 12, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1, ascending);

    // insertionSort(arr, size, ascending);
    // selectionSort(arr, size, ascending);
    // bubbleSort(arr, size, descending);

    printf("\nSorted array is \n");
    printArray(arr, size);

    int x = 32;
    int index = binarySearch(arr, 0, size, x);
    printf("\nElement %d found at index %d (zero-based)\n", x, index);

    return 0;
}

// ------------------------------------------------


void merge(int arr[], int left, int mid, int right, Compare comp) {
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize], rightArr[rightSize];

    // Copy data into temp arrays leftArr[] and rightArr[]
    for ( i = 0; i < leftSize; i++ ) {
        leftArr[i] = arr[left + i];
    }
    for ( j = 0; j < rightSize; j++ ) {
        rightArr[j] = arr[mid + j + 1];
    }

    // Merge temp arrays into arr[]
    i = 0;
    j = 0;
    k = left;
    while ( i < leftSize && j < rightSize ) {
        if ( comp(leftArr[i], rightArr[j]) ) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of leftArr[] and rightArr[], if there are any
    while ( i < leftSize ) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while ( j < rightSize ) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
}


void mergeSort(int arr[], int left, int right, Compare comp) {
    if ( left < right ) {
        // Computes midpoint
        int mid = left + ( right - left ) / 2;

        // Sort left and right halves
        mergeSort(arr, left, mid, comp);
        mergeSort(arr, mid + 1, right, comp);

        merge(arr, left, mid, right, comp);
    }
}


void bubbleSort(int arr[], int size, Compare comp) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = i + 1; j < size; j++ ) {
            if ( comp(arr[j], arr[i]) ) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}


void insertionSort(int arr[], int size, Compare comp) {
    for ( int i = 1; i < size; i++ ) {
        int value = arr[i];
        int j = i - 1;

        while ( j >= 0 && comp(value, arr[j]) ) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = value;
    }
}


void selectionSort(int arr[], int size,  Compare comp) {
    for ( int i = 0; i < size - 1; i++ ) {
        int minIdx = i;

        for ( int j = i + 1; j < size; j++ ) {
            if ( comp(arr[j], arr[minIdx]) ) {
                minIdx = j;
            }
        }
    
        swap(&arr[i], &arr[minIdx]);
    }
}


int binarySearch(int arr[], int left, int right, int x) {
    while ( left < right ) {
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


// ------------------------------------------------


// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for ( i = 0; i < size; i++ ) {
        printf("%d ", arr[i]);
    }    
    printf("\n");
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}