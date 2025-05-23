#include <stdio.h>

#define MAX 100

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int arrSize) {
    printf("[ ");
    for ( int i = 0; i < arrSize; i++ ) {
        printf(" %d ", arr[i]);
    }
    printf(" ]\n");
}


int merge(int arr[], int left, int mid, int right);
int mergeSort(int arr[], int left, int right);

int binSearch(int arr[], int left, int right, int x);


int main() {
    int arr[] = { 9, 91, 8, 44, 7, 22, 6, 5, 11, 4, 3, 54, 2, 1, 17 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printArray(arr, arrSize);

    int x = 2;
    int index = binSearch(arr, 0, arrSize , x);


    printf("Index at %d\n", index);

    return 0;
}



int merge(int arr[], int left, int mid, int right) {
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
        if ( leftArr[i] < rightArr[j] ) {
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

int mergeSort(int arr[], int left, int right) {
    if ( left < right ) {
        int mid = left + ( right - left ) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}



int binSearch(int arr[], int left, int right, int x) {
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