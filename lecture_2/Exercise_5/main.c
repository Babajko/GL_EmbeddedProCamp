#include <stdio.h>
#include <stdint.h>

uint64_t calcFactorial(uint16_t n)
{
    uint64_t r = 1;
    for (int i = 2; i <= n; i++)
        r *= i;
    return r;            
}

int main()
{
    uint8_t f = 10;

    printf("Factorial = %u \n", calcFactorial(f));
    
    return 0;
}