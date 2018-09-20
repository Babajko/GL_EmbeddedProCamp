#include <stdio.h>
#include <stdint.h>

uint16_t convertRgb888ToRgb656(uint32_t rgb)
{
    uint8_t r = (uint8_t)(rgb >> 16) >> 2;
    uint8_t g = (uint8_t)(rgb >> 8) >> 3;
    uint8_t b = (uint8_t)(rgb >> 0) >> 2;
    
    return (r << 12) | (g << 6) | b;
}

int main()
{
    printf("rgb = %x", convertRgb888ToRgb656(26880));
    
    return 0;
}