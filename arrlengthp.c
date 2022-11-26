#include <stdio.h>
int main(){
    int len = 0;
    char c[100];
    char *p = &c[0];
    printf("Enter string: ");
    gets(c);
    while(*p != '\0'){
        p++;
        len++;
    }
    printf("The length of the string = %d", len);
    return 0;
}
