#include <stdio.h>
#include <stdint.h>

float convertMeterToInches(uint16_t valeu)
{
    return valeu * 39.37008;
}

float calcPerimeter(uint16_t a, uint16_t b)
{
    return convertMeterToInches(2 * (a + b));
}

float calcArea(uint16_t a, uint16_t b)
{
    return convertMeterToInches(a * b);
}

int main()
{
    uint8_t a = 2;
    uint8_t b = 5;

    printf("Perimeter = %f \n", calcPerimeter(a, b));
    printf("Area = %f \n", calcArea(a, b));
    
    return 0;
}