/* ESERCIZIO 3 - PROGRAMMAZIONE AVANZATA, 26/02/2025 */
/* Mirko Cenedese 70/94/00138 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define NUM_ELEMENTS 100


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
    int leftIndex, rightIndex, minIndex, max;
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

    // Se arr[index] e' gia' il massimo abbiamo finito, altrimenti applichiamo uno scambio
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
        swap(&arr[i-1], &arr[0]);

        // Ristabilisce le condizioni di min heap
        min_heapify(arr, 0, i-1);
    }
}

int valore_path_nodo(int arr[], int heapSize, int i) {
    int sum = 0;

    // Itera risalendo l'heap fino alla radice
    while (i >= 0) {
        sum += arr[i];
        i = parent(i); // Risaliamo all'elemento padre
    }

    return sum;
}

int main() {
    
    int arr[NUM_ELEMENTS] = {16, 14, 10, 8, 7, 21, 3, 2, 9, 1, -1};
    int heapSize = 10;
    


    printArray(arr, heapSize);

    build_min_heap(arr, heapSize);
    printArray(arr, heapSize);


    heapSort(arr, heapSize);
    printArray(arr, heapSize);

    return 0;
}



