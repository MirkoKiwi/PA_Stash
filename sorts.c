#include <stdio.h>


void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);

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

    mergeSort(arr, 0, size - 1);
    // insertionSort(arr, size);
    // selectionSort(arr, size);
    // bubbleSort(arr, size);

    printf("\nSorted array is \n");
    printArray(arr, size);

    int x = 32;
    int index = binarySearch(arr, 0, size, x);
    printf("\nElement %d found at index %d (zero-based)\n", x, index);

    return 0;
}

// ------------------------------------------------


void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize], rightArr[rightSize];

    for ( i = 0; i < leftSize; i++ ) {
        leftArr[i] = arr[left + i];
    }
    for ( j = 0; j < rightSize; j++ ) {
        rightArr[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = left;
    while ( i < leftSize && j < rightSize ) {
        if ( leftArr[i] <= rightArr[j] ) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

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


void mergeSort(int arr[], int left, int right) {
    if ( left < right ) {
        int mid = left + ( right - left ) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void bubbleSort(int arr[], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = i + 1; j < size; j++ ) {
            if ( arr[i] > arr[j] ) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}


void insertionSort(int arr[], int size) {
    for ( int i = 1; i < size; i++ ) {
        int value = arr[i];
        int j = i - 1;

        while ( j >= 0 && value < arr[j] ) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = value;
    }
}


void selectionSort(int arr[], int size) {
    for ( int i = 0; i < size - 1; i++ ) {
        int minIdx = i;

        for ( int j = i + 1; j < size; j++ ) {
            if ( arr[j] < arr[minIdx] ) {
                minIdx = j;
            }
        }
    
        swap(&arr[i], &arr[minIdx]);
    }
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