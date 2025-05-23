#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "module.h"

// Versione A


typedef struct Node {
    int data;
    int nodeID;
    struct Node *next;
} Node, *NodePtr;

NodePtr createNode(int newData) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    
    newNode -> data = newData;
    newNode -> next = NULL;
    
    return newNode;
}

struct stack {
    int numOfElements;
    NodePtr top;
}; 

StackPtr initStack() {
    StackPtr newStack = (StackPtr)malloc(sizeof(Stack));

    newStack -> numOfElements = 0;
    newStack -> top = NULL;
    
    return newStack;
}

int isEmpty(StackPtr stack) {
    return stack -> top == NULL;
}

void push(StackPtr stack, int newData) {
    NodePtr newNode = createNode(newData);
    
    if ( !newNode ) {
        printf("Stack overflow\n");
        return;
    }
    
    stack -> numOfElements += 1;
    
    newNode -> nodeID = stack -> numOfElements;
    newNode -> next = stack -> top;
    
    stack -> top = newNode;
}


int pop(StackPtr stack) {
    if ( isEmpty(stack) ) {
        printf("Stack underflow\n");
        return INT_MIN;
    }

    NodePtr temp = stack -> top;
    int value = temp -> data;
    stack -> top = stack -> top -> next;
    
    free(temp);
    return value;
}

int peek(StackPtr stack) {
    if ( !isEmpty(stack) ) {
        return stack -> top -> data;
    }

    printf("Stack empty\n");
    return INT_MIN;
}

void show(StackPtr stack) {
    if ( isEmpty(stack) ) {
        printf("Stack empty.\n");
        return;
    }
    
    NodePtr current = stack -> top;
    printf("Elementi in stack:\n");
    while ( current != NULL ) {
        printf("[ID: %d, Data: %d] -> ", current -> nodeID, current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

// Aggiungere allo stack un valore intero che tiene traccia degli elementi (incrementato ad ogni push(), decrementato ad ogni pop())
// iterare attraverso ogni nodo, se quel nodo ha un numero identificativo pari a k allora estrarne il valore dal campo "data" dello struct
int peek_k(StackPtr stack, int k) {
    if ( isEmpty(stack) ) {
        printf("Stack empty.\n");
        return INT_MIN;
    }
    
    NodePtr current = stack -> top;
    while ( current != NULL ) {
        if ( current -> nodeID == k ) {
            return current -> data;
        }
        current = current -> next;
    }
    
    printf("Elemento %d non trovato.\n", k);
    return INT_MIN;
}

// La complessità computazionale e' O(n), dato che attraversare lo stack è un'operazione O(n)
// mentre raccogliere il valore contenuto in un nodo è O(1) visto che richiede solo il recupero di valori puntati