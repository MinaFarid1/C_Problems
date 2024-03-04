#include <stdio.h>
unsigned char reverseBinary(unsigned char num) {
    unsigned char reversed = 0;

    for (int i = 0; i < 8; i++) {
        reversed <<= 1;             // Left shift the result to make room for the next bit
        reversed |= num & 1;        // OR operation with the least significant bit of num
        num >>= 1;                  // Right shift num to process the next bit
    }

    return reversed;
}

int main() {
    unsigned char number = 0b10001101;  // 0x8D
    unsigned char reversed = reverseBinary(number); // Result should be 1011 0001 (0xB1)
    
    printf("Number: 0x%02X\n", number);
    printf("Reversed: 0x%02X\n", reversed);

    return 0;
}
