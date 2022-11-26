#include<stdio.h>
void printArr(int *arr, int size);
int main()
{
    int size = 5, i;
    int arr1[size], arr2[size];
    int *p1 = arr1;
    int *p2 = arr2;
    printf("Enter %d array elements:\n", size);
    for(int i =0; i<size; i++)
        scanf("%d", p1 + i);
    printf("Second array before copying: ");
    printArr(arr2,size);
    for(int i = 0; i<size; i++)
        *(p2 + i) = *(p1 + i);
    printf("\nSecond array after copying: ");
    printArr(arr2,size);
}
void printArr(int *arr, int size){
    for(int i = 0; i<size; i++)
        printf("%d ", *(arr+i));
}