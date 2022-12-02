#include <stdio.h>
int main(){
    int arr[10];
    int *p = arr;
    printf("Enter array elements:\n");
    for(int i = 0; i<10; i++)
        scanf("%d", &arr[i]);
    for(int i = 9; i>=0; i--)
        printf("%d ", *(p+i));
    return 0;   
}
