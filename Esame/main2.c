/* ESERCIZIO 2 - PROGRAMMAZIONE AVANZATA, 26/02/2025 */
/* Mirko Cenedese 70/94/00138 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int ore_lavorate;
    int stipendio;
    int paga_oraria;
} Data;

// Puntatore a funzione
typedef bool (*compareBy)(Data x, Data y);

bool compareByOre(Data x, Data y) { x.ore_lavorate <= y.ore_lavorate; }
bool compareByPaga(Data x, Data y) { x.paga_oraria <= y.paga_oraria; }

// Sort by stipendio
void merge(Data arr[], int left, int mid, int right) {
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Data leftArr[leftSize], rightArr[rightSize];

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
        if ( leftArr[i].stipendio <= rightArr[j].stipendio ) {
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


void sort(Data arr[], int left, int right) {
    if ( left < right ) {
        int mid = left + ( right - left ) / 2;

        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Merge dinamico, il campo viene deciso dalla funzione puntata da "comp"
void merge2(Data arr[], int left, int mid, int right, compareBy comp) {
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Alloco spazio per gli array di struct
    Data leftArr[leftSize], rightArr[rightSize];

    // Copio i dati dall'array originale ai due array dichiarati in precedenza
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
        // Qui i due valori dello struct vengono comparati dinamicamente in base al valore (booleano) passato da compareBy
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

    // Copia gli ultimi elementi, se sono presenti
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

void sort2(Data arr[], int left, int right, compareBy comp) {
    if ( left < right ) {
        int mid = left + ( right - left ) / 2;

        // Esegue il sort delle due meta' dell'array
        sort2(arr, left, mid, comp);
        sort2(arr, mid + 1, right, comp);

        merge2(arr, left, mid, right, comp);
    }
}

// Funzione di servizio
void printArray(Data array[], int dimArray) {
    for (int i = 0; i < dimArray; i++) {
        printf("%d %d %d\n", array[i].ore_lavorate, array[i].paga_oraria, array[i].stipendio);
    }
    printf("\n");
}


int main()
{
    Data array[4] = {
        {1, 11, 12},    // First element
        {10, 8, 9 },    // Second element
        {7, 5, 6 },     // Third element
        {4, 2, 3 }      // Fourth element
    };
    int dimArray = 4;
    
    
    sort(array, 0, dimArray - 1);
    printArray(array, dimArray);
    
    sort2(array, 0, dimArray - 1, compareByOre);
    printArray(array, dimArray);

    sort2(array, 0, dimArray - 1, compareByPaga);
    printArray(array, dimArray);

    return EXIT_SUCCESS;
}


/*
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


void sort(int arr[], int left, int right) {
    if ( left < right ) {
        int mid = left + ( right - left ) / 2;

        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
*/
