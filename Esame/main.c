/* ESERCIZIO 1 - PROGRAMMAZIONE AVANZATA, 26/02/2025 */
/* Mirko Cenedese 70/94/00138 */

#include <stdio.h>
#include <stdlib.h>

#include "module.h"

// Versione A


// MAIN
int main() {
    
    int v, k, i;
    
    StackPtr s;
    s = initStack();
    
    // Essendo in First Class ADT, l'accesso diretto agli elementi dello struct risulta impossibile
    // s.top = NULL;

    printf("Push 1 2 3 4 5 6 \n");
    printf("->expected: \n[TOP] [6 5 4 3 2 1] [BASE]");
    for ( i = 1; i < 7; i++) push(s, i);
    printf("\n->obtained:\n");
    show(s);
    printf("--------------------\n");

    k=6;
    v= peek_k(s,k);

    printf("last pos %d  value %d  \n",k, v );
    printf("--------------------\n");

    return 0;
}
