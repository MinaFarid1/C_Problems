#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100
typedef char stackEntry;
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
int main(){
    stack *s = initStack();
    char word[100];
    stackEntry l;
    int choice, temp, i, wordLength, isPalindrome;
    while(1){
        printf("1-Enter word\n2-Exit\n");
        scanf("%d", &choice);
        if(choice == 2) break;
        else if(choice != 1){
            printf("Enter a valid option\n");
            continue;
        }
        wordLength = 0; temp = 0, isPalindrome = 1;
        clearStack(s);
        printf("Enter your word: ");
        scanf("%s", word);
        for (i = 0;word[i] != '\0';i++){
            l = word[i];
            push(s, l);
            wordLength++;
        }
        for(i = 0;i<(wordLength/2);i++){
            if(peek(s) == s->array[temp]){
                pop(s);
                temp++;
            }
            else{
                printf("%s is not a palindrome\n",word);
                isPalindrome = 0;
                break;
            }
        }
        if(isPalindrome)
            printf("%s is a palindrome\n",word);
    }
    return 0;
}
