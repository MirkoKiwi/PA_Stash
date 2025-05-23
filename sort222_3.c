#include <stdio.h>


void printArray(int arr[], int arrSize) {
    printf("[ ");
    for ( int i = 0; i < arrSize; i++ ) {
        printf(" %d ", arr[i]);
    }
    printf(" ]\n");
}


int merge(int a[], int l, int m, int r) {
    int i, j, k;
    int ls = m - l + 1;
    int rs = r - m;

    int la[ls], ra[rs];

    for ( i = 0; i < ls; i++ ) {
        la[i] = a[l + i];
    }
    for ( j = 0; j < rs; j++ ) {
        ra[j] = a[m + j + 1];
    }

    i = 0;
    j = 0;
    k = l;
    while ( i < ls && j < rs ) {
        if ( la[i] < ra[j] ) {
            a[k] = la[i];
            i++;
        }
        else {
            a[k] = ra[j];
            j++;
        }

        k++;
    }

    while ( i < ls ) {
        a[k] = la[i];
        i++;
        k++;
    }
    while ( j < rs ) {
        a[k] = ra[j];
        j++;
        k++;
    }
}

int mergeSort(int a[], int l, int r) {
    if ( l < r ) {
        int m = l + ( r - l ) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int binarySearch(int a[], int l, int r, int x) {
    while ( l <= r ) {
        int m = l + ( r - l ) / 2;

        if ( a[m] == x ) {
            return m;
        }
        else if ( a[m] < x ) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return -1;
}



int main() {
    int arr[] = { 9, 91, 8, 44, 7, 22, 6, 5, 11, 4, 3, 54, 2, 1, 17 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printArray(arr, arrSize);

    int x = 2;
    int index = binarySearch(arr, 0, arrSize , x);


    printf("Index at %d\n", index + 1);

    return 0;
}