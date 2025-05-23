/* ESERCIZIO 3 - PROGRAMMAZIONE AVANZATA, 26/02/2025 */
/* Mirko Cenedese 70/94/00138 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define NUM_ELEMENTS 100

// ----------------------------------------------
int pow2i(int exponent);
// Prints binary tree in a cute format
void displayTree(const int *arr, int arrlen); 
// ----------------------------------------------


// Funzione di servizio per stampare un array
void printArray(const int arr[], int size) {
    int i;
    printf("[");
    for ( i = 0; i < size; i++ ) {
        printf("%4d", arr[i]);
    }
    printf("  ]\n\n");
}

// Funzione di servizio per scambiare due elementi
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Accesso ai nodi
int parent(int i) { return ( i - 1 ) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }



void min_heapify(int arr[], int index, int heapSize) {
    int leftIndex, rightIndex, minIndex;
    leftIndex = left(index);
    rightIndex = right(index);

    // Il figlio a sinistra esiste ed è minore del nodo padre  
    if ( leftIndex < heapSize && arr[leftIndex] < arr[index] ) { 
        minIndex = leftIndex;
    }
    else {   // Il figlio non esiste o non ha valore minimo
        minIndex = index;
    }

    // Il figlio a destra esiste ed ha valore minore del padre
    if ( rightIndex < heapSize && arr[rightIndex] < arr[minIndex] ) {
        minIndex = rightIndex;
    }
    // Se il figlio a destra non esiste, il minIndex sara' l'indice corrente

    // Se arr[index] e' gia' il minimo abbiamo finito, altrimenti applichiamo uno scambio
    if ( minIndex != index ) {
        swap(&arr[minIndex], &arr[index]);

        // Ristabilisce le condizioni di min heap
        min_heapify(arr, minIndex, heapSize);
    }
}

void build_min_heap(int arr[], int heapSize){
    int i;
    for ( i = parent(heapSize - 1); i >= 0; i-- ) {
        min_heapify(arr, i,  heapSize);
    }
}

void heapSort(int arr[], int heapSize){
    int i;
    build_min_heap(arr, heapSize);
    for ( i = heapSize; i > 1; i-- ) {
        // Scambia la radice con l'ultimo elemento
        swap(&arr[i - 1], &arr[0]);

        // Ristabilisce le condizioni di min heap
        min_heapify(arr, 0, i - 1);
    }
}

int valore_path_nodo(int arr[], int heapSize, int i) {
    int sum = 0;

    // Itera risalendo l'heap fino alla radice
    while ( i >= 0 ) {
                sum += arr[i];
        i = parent(i - 1); // Risaliamo all'elemento padre
    }

    return sum;
}

int main() {
    int arr[NUM_ELEMENTS] = {16, 14, 10, 8, 7, 21, 3, 2, 9, 1, -1};
    int heapSize = 10;

    printArray(arr, heapSize);
    
    build_min_heap(arr, heapSize);
    printArray(arr, heapSize);
    displayTree(arr, heapSize);

    heapSort(arr, heapSize);
    printArray(arr, heapSize);

    displayTree(arr, heapSize);
    
    // Test valore_path_nodo
    int nodoIndex = 6;
    printf("Somma percorso dal nodo %d alla radice: %d\n", arr[nodoIndex], valore_path_nodo(arr, heapSize, nodoIndex));

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
    printf("\n");
}
