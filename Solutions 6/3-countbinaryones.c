#include <stdio.h>
int countOnes(int num) {
    int count = 0;
    while (num != 0) { // Loop untill no more 1s exist
        count += num & 1; // Add the result of bitwise AND 1 with the least significant bit
        num >>= 1; // Right shift the number to check the next bit
    }
    return count;
}

int main() {
    int number;
    printf("Enter an integer number: ");
    scanf("%d", &number);
    printf("Number of ones in the binary representation: %d\n", countOnes(number));

    return 0;
}