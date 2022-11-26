#include<stdio.h>
int main()  
{  
    int n = 5;
    int a[n], i, *small;  
    printf("Enter %d integer numbers\n", n);  
    for(i = 0; i < n; i++)  
        scanf("%d", &a[i]);
    small = &a[n - 1];
    for(i = 0; i < n - 1; i++)  
    {  
        if( *(a + i) < *small)  
            *small = *(a + i);  
    }  
    printf("Smallest integer in the array: %d\n", *small);  
    return 0;  
}