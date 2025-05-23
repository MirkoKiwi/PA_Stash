#include <stdio.h>


void printArray(int* v, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");
}


int parent(int i){
    return (i-1)/2;
}


int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*(i+1);
}


void max_heapify(int* A, int i, int heap_size){
    int l, r, idx_max, max;
    l=left(i);
    r=right(i);
    // se l è valido,
    //  se A[l]>A[i],  MASSIMO=A[l] . Altrimenti MASSIMO=A[i]
    if ( l<heap_size && A[l]>A[i] ){
        idx_max=l;
        max=A[idx_max];
    }
    else{
        idx_max=i;
        max=A[idx_max];
    }
    // se r è valido,
    //  se A[r]>MASSIMO,  MASSIMO=A[r]. Altrimenti PASS;
    if ( r<heap_size && A[r]>max ){
        idx_max=r;
        max=A[idx_max];
    }

    // nota: posso fare a meno di assegnare  max=A[idx_max]
    // lo uso solo per semplicità di notazione

    // se il massimo NON è A[i],
    //  scambia, e applica max_heapify al nodo scambiato
    //  altrimenti la procedura si conclude (è già un max_heap)
    if (idx_max!=i){
        A[idx_max]= A[i];
        A[i]=max;
        max_heapify(A, idx_max,  heap_size);
    }
}


void build_max_heap(int* A, int heap_size){
    for (int i=(heap_size-1)/2; i>=0; i--){
        max_heapify(A, i,  heap_size);
        printf("%d\n",i);
    }
}

void heapsort(int* A, int heap_size){
    int tmp;

    build_max_heap(A, heap_size);
    //printArray(A, heap_size);

    for (int i=heap_size; i>1; i--){
        printf("%d\n",i);
        // swap radice con ultimo elemento
        tmp=A[i-1];
        A[i-1]= A[0];
        A[0]=tmp;

        max_heapify(A, 0,  i-1);
    }
}



int main() {

    int nEl=13;
    int vett[13] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1, -1};
    //int vett[13]={4,1,3,2,16,9,10, 14,8,7, -1, -1, -1};
    int heap_size=10;

    printArray(vett, heap_size);

    build_max_heap(vett, heap_size);
    printArray(vett, heap_size);

    heapsort(vett, heap_size);

    printArray(vett, heap_size);



    getchar();
    return 0;
}