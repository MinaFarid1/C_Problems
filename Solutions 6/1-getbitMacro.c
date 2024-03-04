#include <stdio.h>
// الاسم: مينا فريد سمير - سكشن: 7
/*  
    Right shift the variable n times equal to the bit 
    position to make the target bit the least significant bit
    then use bitwise AND with a 1 to get the bit value               
*/
#define GET_BIT(var, bit_num) (((var) >> (bit_num)) & 1)
int main() {
    unsigned long num = 0b0110110000101111;
    int n = 3; 
    int bit = GET_BIT(num, n);
    printf("Bit at position %d is: %d\n", n, bit);
    return 0;
}
