#include <stdio.h>
#include <stdlib.h>


int *mergeThreeSortedArrays(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3, int *resultSize) {
    int i = 0, j = 0, k = 0, index = 0;
    int totalSize = size1 + size2 + size3;
    
    int *mergedArray = (int *)malloc(totalSize * sizeof(int));
    if ( mergedArray == NULL ) {
        printf("Malloc error\n");
        return -1;
    }

    // Merge 3 arrays until there are only 2 remaining arrays to check
    while ( i < size1 && j < size2 && k < size3 ) {
        // Check if arr1[i] is min value
        if ( arr1[i] <= arr2[j] && arr1[i] <= arr3[k] ) {
            mergedArray[index] = arr1[i];
            i++;
        } 
        // Check if arr2[j] is min value
        else if ( arr2[j] <= arr1[i] && arr2[j] <= arr3[k] ) {
            mergedArray[index] = arr2[j];
            j++;
        } 
        // Otherwise arr3[k] is the lesser value
        else {
            mergedArray[index] = arr3[k];
            k++;
        }

        index++;
    }

    // Compare arr1 and arr2
    while ( i < size1 && j < size2 ) {
        if ( arr1[i] <= arr2[j] ) {
            mergedArray[index] = arr1[i];
            i++;
        }
        else {
            mergedArray[index] = arr2[j];
            j++;
        }
        index++;
        // mergedArray[index++] = ( arr1[i] <= arr2[j] ) ? arr1[i++] : arr2[j++];
    }
    // Compare arr1 and arr3
    while ( i < size1 && k < size3 ) {
        if ( arr1[i] <= arr3[j] ) {
            mergedArray[index] = arr1[i];
            i++;
        }
        else {
            mergedArray[index] = arr3[j];
            j++;
        }
        index++;
        // mergedArray[index++] = ( arr1[i] <= arr3[k] ) ? arr1[i++] : arr3[k++];
    }
    // Compare arr2 and arr3
    while ( j < size2 && k < size3 ) {
        if ( arr2[i] <= arr3[j] ) {
            mergedArray[index] = arr2[i];
            i++;
        }
        else {
            mergedArray[index] = arr3[j];
            j++;
        }
        index++;
        // mergedArray[index++] = ( arr2[j] <= arr3[k] ) ? arr2[j++] : arr3[k++];
    }

    // Copy remaining elements, if any
    while ( i < size1 ) {
        mergedArray[index] = arr1[i];
        index++;
        i++;
    }
    while ( j < size2 ) { 
        mergedArray[index] = arr2[j];
        index++;
        j++;
    }
    while ( k < size3 ) {
        mergedArray[index] = arr3[k];
        index++;
        k++;
    }
    
    *resultSize = index;
    return mergedArray;
}


void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}

int main() {

    //int arr1[] = {0, 1, 1, 4, 7, 9};
    //int arr2[] = {0, 1, 1, 2, 2, 5, 5, 8, 9};
    //int arr3[] = {1, 1, 1, 1, 3, 6, 7};
    int arr1[] = { 4, 7, 10, 19 };
    int arr2[] = { 2, 5, 9, 15, 18, 20 };
    int arr3[] = { 1, 3, 6, 11, 17};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    int resultSize;
    int *mergedArray = mergeThreeSortedArrays(arr1, size1, arr2, size2, arr3, size3, &resultSize);
    
    printf("INPUT:\n");
    printArray(arr1, size1);
    printArray(arr2, size2);
    printArray(arr3, size3);
    
    printf("OUTPUT:\n");
    printArray(mergedArray, resultSize);
    
    free(mergedArray);
    return 0;
}