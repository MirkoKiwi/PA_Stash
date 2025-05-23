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

void explore( int*v, int heap_size, int i){
    int i_p, i_l, i_r;
    if (i>= heap_size)
        printf("Node %d, is not in the HEAP!\n",i);
    else {
        printf("Node %d, val %d ->", i, v[i]);

        // PARENT
        if (i > 0) {
            i_p = parent(i);
            printf("Parent: element %d, val %d - ", i_p, v[i_p]);
        } else printf("It is the ROOT. No parent node! - ");
        // Left
        i_l = left(i);
        if (i_l < heap_size)
            printf(" Left: element %d, val %d - ", i_l, v[i_l]);
        else printf("No left node! ");

        //Right
        i_r = right(i);
        if (i_r < heap_size)
            printf("Right: element %d, val %d\n", i_r, v[i_r]);
        else printf("No right node!\n");

    }
    printf("\n");



}

int main() {
    int i;
    const int nEl=100;
    int vett[nEl]={16,14, 10, 8,7,9, 3,2, 4,1, -1};
    int heap_size=11;
    printArray(vett, heap_size);

    for (i =0; i< heap_size+1; i++ ){
        explore( vett,  heap_size,  i);

    }
    i=11;


    return 0;
}