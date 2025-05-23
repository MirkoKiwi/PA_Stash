#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 128

typedef struct Node {
    int data;
    char word[MAX_SIZE];
    int array[MAX_SIZE];
    struct Node *next;
} Node; 

Node *createNode(int newData, char newWord[], int sizeOfWord, int newArray[], int sizeOfArray) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode -> data = newData;
    strncpy(newNode -> word, newWord, sizeOfWord - 1);
    newNode -> word[sizeOfWord - 1] = '\0';  // Ensure null-termination

    for ( int i = 0; i < sizeOfArray; i++ ) {
        newNode -> array[i] = newArray[i];
    }

    newNode -> next = NULL;
    return newNode;
}

typedef struct Stack {
    Node *top;
} Stack;

void initStack(Stack *stack) {
    stack -> top = NULL;
}

bool isEmpty(Stack *stack) {
    return stack -> top == NULL;
}

void push(Stack *stack, int newData, char newWord[], int sizeOfWord, int newArray[], int sizeOfArray) {
    Node *newNode = createNode(newData, newWord, sizeOfWord, newArray, sizeOfArray);
    if ( !newNode ) {
        printf("Stack overflow\n");
        return;
    }

    newNode -> next = stack -> top;
    stack -> top = newNode;
}

int pop(Stack *stack) {
    if ( isEmpty(stack) ) {
        printf("Stack underflow\n");
        return INT_MIN;
    }

    Node *temp = stack -> top;
    int value = temp -> data;
    stack -> top = stack -> top -> next;
    
    free(temp);
    return value;
}

Node *peek(Stack *stack) {
    if ( !isEmpty(stack) ) {
        return stack -> top;
    }

    printf("Stack empty\n");
    return NULL;
}

int main() {
    Stack s;
    initStack(&s);

    char demoWord[] = "Miaonigga";
    int sizeDemoWord = sizeof(demoWord) / sizeof(demoWord[0]);

    int demoArray[] = {1, 2, 4, 8, 16};
    int sizeDemoArray = sizeof(demoArray) / sizeof(demoArray[0]);

    push(&s, 1, demoWord, sizeDemoWord, demoArray, sizeDemoArray);

    Node *topNode = peek(&s);
    if (topNode) {
        printf("Top Data: %d\n", topNode -> data);
        printf("Top Array:");
        for ( int i = 0; i < sizeDemoArray; i++ ) {
            printf(" %d |", topNode -> array[i]);
        }
        printf("\n");
        printf("Top Word: %s\n", topNode -> word);
    }

    char demoWord1[] = "Second string trial?";
    int sizeDemoWord1 = sizeof(demoWord1) / sizeof(demoWord1[0]);

    int demoArray1[] = {4, 16, 32, 64, 128};
    int sizeDemoArray1 = sizeof(demoArray1) / sizeof(demoArray1[0]);

    push(&s, 66, demoWord1, sizeDemoWord1, demoArray1, sizeDemoArray1);

    topNode = peek(&s);
    if (topNode) {
        printf("Top Data: %d\n", topNode -> data);
        printf("Top Array:");
        for ( int i = 0; i < sizeDemoArray; i++ ) {
            printf(" %d |", topNode -> array[i]);
        }
        printf("\n");
        printf("Top Word: %s\n", topNode -> word);
    }

    return 0;
}
