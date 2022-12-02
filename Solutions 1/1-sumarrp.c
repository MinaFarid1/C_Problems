#include <stdio.h>
int main(){
    int n = 4;
    float arr[] = {12.5, 13.9, 5.1, 2.5};
    float sum = 0;
    for(int i = 0; i<n; i++){
        sum += *(arr + i);
    }
    printf("%f", sum);
    return 0;
}

