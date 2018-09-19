#include <stdio.h>
#include <stdint.h>

#define PI 3.14159265


float calcPerimeter(uint16_t r)
{
    return 2 * PI * r;
}

float calcArea(uint16_t r)
{
    return PI * (r * r);
}

int main()
{
    uint8_t r = 6;

    printf("Perimeter = %f \n", calcPerimeter(r));
    printf("Area = %f \n", calcArea(r));
    
    return 0;
}