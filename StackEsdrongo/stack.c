#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define DATA_SIZE 128


typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    newNode -> data = newData;
    newNode -> next = NULL;

    return newNode;
}

typedef struct Stack {
    Node *head;
} Stack;

void initStack(Stack *stack) {
    stack -> head = NULL;
}

bool isEmpty(Stack *stack) {
    return stack -> head == NULL;
}

void push(Stack *stack, int newValue) {
    Node *newNode = createNode(newValue);

    if ( !newNode ) {
        printf("\nStack overflow\n");
        return;
    }

    newNode -> next = stack -> head;
    stack -> head = newNode;
}

int pop(Stack *stack) {
    if ( isEmpty(stack) ) {
        printf("\nStack underflow\n");
        return INT_MIN;
    }
    else {
        int value = stack -> head -> data;
        Node *temp = stack -> head;
        stack -> head = stack -> head -> next;
        free(temp);

        return value;
    }
}

int peek(Stack *stack) {
    if ( !isEmpty(stack) ) {
        return stack -> head -> data;
    }
    else {
        printf("\nStack is empty");
        return INT_MIN;
    }
}



int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped: %d\n",pop(&stack));
    
    printf("Top element: %d\n", peek(&stack));

    return 0;
}