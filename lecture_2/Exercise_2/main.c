#include <stdio.h>
#include <stdint.h>

void convertRgb888ToRgb656(uint8_t *r,
                           uint8_t *g,
                           uint8_t *b)
{
    *r = *r >> 2;
    *g = *g >> 3;
    *b = *b >> 2;
}

int main()
{
    uint8_t r, g, b;
    r = g = b =255;
    convertRgb888ToRgb656(&r, &g, &b);
    printf("r=%x g=%x b=%x", r, g, b);
    
    return 0;
}