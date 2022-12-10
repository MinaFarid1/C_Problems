#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Stack.h"
int main(){
    stack *s = initStack();
    int active = 1;
    stackEntry e;
    char choice;
    while(active){
        printf("(a) Clear the stack\n(b) Read an element then Push it\n(c) Pop an element then display it\n(d) Stack size\n(e) Stack top\n(f) Exit\n");
        scanf("%c", &choice);
        printf("\n");
        switch(tolower(choice)){
            case 'a':
                clearStack(s);
                break;
            case 'b':
                printf("Enter an element: ");
                scanf("%d", &e);
                push(s, e);
                break;
            case 'c':
                printf("%d", pop(s));
                break;
            case 'd':
                printf("%d", stackSize(s));
                break;
            case 'e':
                printf("%d", peek(s));
                break;
            case 'f':
                active = 0;
                break;
            default:
                printf("Invalid option");
                break;
        }
        printf("\n\n");
        getchar();
    };
    return 0;
}