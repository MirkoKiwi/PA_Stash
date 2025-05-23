
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


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

typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q -> front = NULL;
    q -> rear = NULL;

    return q;
}

bool isEmpty(Queue *q) {
    if ( q -> front == NULL && q -> rear == NULL ) {
        return true;
    }

    return false;
}

void enqueue(Queue *q, int newData) {
    Node *newNode = createNode(newData);

    if ( q -> rear == NULL ) {
        q -> front = newNode;
        q -> rear = newNode;
        return;
    }

    q -> rear -> next = newNode;
    q -> rear = newNode;
}

void dequeue(Queue *q) {
    if ( isEmpty(q) ) {
        printf("Queue underflow\n");
        return;
    }

    Node *temp = q -> front;    
    q -> front = q -> front -> next;

    if ( q -> front == NULL ) {
        q -> rear = NULL;  
    }

    free(temp);
}

int getFront(Queue *q) {
    if ( isEmpty(q) ) {
        printf("Empty queue\n");
        return INT_MIN;
    }

    return q -> front -> data;
}

int getRear(Queue *q) {
    if ( isEmpty(q) ) {
        printf("Empty queue\n");
        return INT_MIN;
    }

    return q -> rear -> data;
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);

    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);

    getFront(q);
    getRear(q);

    enqueue(q, 69);

    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));

    enqueue(q, 420);

    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));

    return 0;
}