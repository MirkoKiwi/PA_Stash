#include <stdio.h>

// funzioni di servizio
void printArray(int* v, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");
}

// HEAP - accesso ai nodi

int parent(int i){ return (i-1)/2; }
int left(int i){ return 2*i+1;}
int right(int i){ return 2*(i+1); }

// HEAP - altre funzioni
void max_heapify(int* A, int i, int heap_size){
    int l, r, idx_max, max;
    l=left(i);
    r=right(i);

    if ( l<heap_size && A[l]>A[i] ){ // figlio SX esistente && SX è il massimo
        idx_max=l;
    }
    else{// figlio SX NON esistente OPPURE esiste ma non è  il massimo
        // - > il massimo tra sx e i  è i
        idx_max=i;
    }
    // stesso confronto tra il max attuale e figlio DX, se esiste


    // se r è valido,
    //  se A[r]>MASSIMO,  MASSIMO=A[r]. Altrimenti PASS;
    if ( r<heap_size && A[r]>A[idx_max] ){ // figlio DX esistente && DX è il massimo
        idx_max=r;
    }
    // SE figlio DX NON esistente OPPURE esiste ma non è  il massimo
    // - > il massimo è quello determinato precedentemente

    // -------------------

    // se il massimo  è A[i], non occorre fare nulla (è già un max_heap)

    // se il massimo NON è A[i],
    //  - scambia con il figlio con il valore massimo
    //  -  applica max_heapify al figlio scambiato
    if (idx_max!=i){
        max =  A[idx_max];
        A[idx_max]= A[i];
        A[i]=max;
        max_heapify(A, idx_max,  heap_size);
    }
}


int main() {
    int nEl=13;
    int vett[13]={16, 15, 10, 14, 7, 9, 3, 2, 8, 1, -1, -1, -1};
    int heap_size=10;
    int i=1; // nodo da alterare


    printf("\nvettore originale\n");
    printArray(vett, heap_size);
    printf("\napplico max_heapify al nodo %d ma senza effetti\n", i);
    max_heapify(vett,i ,  heap_size); // nessun effetto
    printArray(vett, heap_size);

    printf("\naltero il valore del nodo %d\n", i);
    vett[i] = 4 ; //ora non è più un max-heap_size
    printArray(vett, heap_size);
    printf("\napplico max_heapify al nodo %d e ripristino la condizione max-heap\n",i);
    max_heapify(vett,i ,  heap_size);
    printArray(vett, heap_size);



    return 0;
}