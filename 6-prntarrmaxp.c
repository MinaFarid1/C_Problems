#include<stdio.h>
int main()
{
    int size = 5, max = 0;
    int arr[size];
    int (*p)[size] = &arr;
    printf("Enter %d array elements:\n", size);
    for(int i =0; i<size; i++)
        scanf("%d", p[i]);
    printf("Array elements: ");
    for(int i = 0;i<size; i++){
        printf("%d ", *(p[i]));;
        if(*(p[i]) >= max){
            max = *(p[i]);
        }
    }
    printf("\nMaximum number: %d", max);    
}
