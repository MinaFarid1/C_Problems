#include <stdio.h>
// الاسم: مينا فريد سمير - سكشن: 7
// Use type parameter to work with different types
#define ARRAY_SUM(arr, n, type) ({ \
    type sum = 0; \
    for (int i = 0; i < (n); i++) { \
        sum += (arr)[i]; \
    } \
    sum; \
})

int main() {
    int array[] = {1, 2, 3, 4};
    int size = sizeof(array) / sizeof(array[0]);
    int sum = ARRAY_SUM(array, size, int);

    printf("Sum of the array elements: %d\n", sum);

    return 0;
}
