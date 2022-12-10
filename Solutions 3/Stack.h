#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

typedef int stackEntry;
typedef struct Stack{
    size_t top;
    stackEntry array[MAX_SIZE];
} stack;
int isFull(stack *s);
int isEmpty(stack *s);
stack* initStack();
void push(stack *s, stackEntry data);
stackEntry pop(stack *s);
void clearStack(stack *s);
stackEntry peek(stack *s);
int stackSize(stack *s);
#endif