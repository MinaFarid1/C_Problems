#include<stdio.h>
void swap(int *x, int *y);
void printArray(int *array, int size);
int main()
{
    int n = 5;
    int arr1[n], arr2[n];
    int *ptr1 = arr1, *ptr2 =arr2; 
    printf("Enter %d numbers for the first array:\n", n);
    for(int i =0; i<n; i++)
        scanf("%d", ptr1 + i);
    printf("Enter %d numbers for the second array:\n", n);
    for(int i =0; i<n; i++)
        scanf("%d", ptr2 + i);
    printf("First array before swapping: ");
    printArray(arr1, n);
    printf("\nSecond array before swapping: ");
    printArray(arr2, n);
    for(int i =0; i<n; i++)
        swap(ptr1+i, ptr2+i);
    printf("\n\nFirst array after swapping: ");
    printArray(arr1, n);
    printf("\nSecond array after swapping: ");
    printArray(arr2, n);
}
void swap(int *x, int *y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
void printArray(int *array, int size){
    for(int i = 0; i<size; i++)
        printf("%d ", *(array+i));
}