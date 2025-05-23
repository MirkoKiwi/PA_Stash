#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node, *NodePtr;

NodePtr createNode(int newData) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));

    newNode -> data = newData;
    newNode -> next = NULL;

    return newNode;
}

typedef struct Stack {
    NodePtr head;
} Stack, *StackPtr;

StackPtr initStack() {
    StackPtr stack = (StackPtr)malloc(sizeof(Stack));

    stack -> head = NULL;

    return stack;
}

bool isEmpty(StackPtr stack) {
    return stack -> head == NULL;
}

void push(StackPtr stack, int newData) {
    NodePtr newNode = createNode(newData);

    if ( !newNode ) {
        printf("Stack overflow\n");
        return;
    }

    newNode -> next = stack -> head;
    stack -> head = newNode;
}

int pop(StackPtr stack) {
    if ( isEmpty(stack) ) {
        printf("Stack underflow\n");
        return INT_MIN;
    }

    int value = stack -> head -> data;
    NodePtr temp = stack -> head;
    stack -> head = stack -> head -> next;

    free(temp);
    return value;
}

int peek(StackPtr stack) {
    return ( !isEmpty(stack) ) ? stack -> head -> data : printf("Stack empty\n"), INT_MIN;
}

int main() {
    StackPtr s = initStack();

    push(s, 10);
    push(s, 20);

    int value = pop(s);
    printf("Popped %d\n", value);

    value = pop(s);
    printf("Popped %d\n", value);

    pop(s);


    free(s);
    return 0;
}