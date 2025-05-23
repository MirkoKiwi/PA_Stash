#ifndef MODULE_H
#define MODULE_H

// Versione A

typedef struct stack Stack, *StackPtr;

StackPtr initStack();

int isEmpty(StackPtr stack);
void push(StackPtr stack, int newData);
int pop(StackPtr stack);
int peek(StackPtr stack);
void show(StackPtr stack);
int peek_k(StackPtr stack, int k);

#endif  // MODULE_H