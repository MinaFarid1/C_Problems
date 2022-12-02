#include<stdio.h>
void swap(int *x, int *y);
int main()
{
    int x, y;
    int *p1 = &x, *p2 = &y;
    void (*swap_ptr)(int *, int *) = &swap;
    printf("Enter first number: "); 
    scanf("%d", p1);
    printf("Enter second number: ");
    scanf("%d", p2);
    printf("\nFirst number before swapping: %d \nSecond number before swapping: %d \n\n", x, y);
    (*swap_ptr)(p1, p2);
    printf("First number after swapping: %d \nSecond number after swapping: %d", x, y);
}
void swap(int *x, int *y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}