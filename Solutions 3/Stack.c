#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef int stackEntry;
typedef struct Stack{
    int top;
    stackEntry array[MAX_SIZE];
} stack;
stack* initStack(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    return s;
};
int isFull(stack *s){
    return s->top==(MAX_SIZE - 1);
};
int isEmpty(stack *s){
    return s->top==-1;
};
void push(stack *s, stackEntry data){
    if(isFull(s)){
        printf("Stack is full");
        return;
    }
    s->array[++s->top] = data;
};
stackEntry pop(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty ");
        return 0;
    }
    return s->array[s->top--];
};
void clearStack(stack *s){
    s->top = -1;
};
stackEntry peek(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty ");
        return 0;
    }
    return s->array[s->top];
};
int stackSize(stack *s){
    return (s->top)+1;
}