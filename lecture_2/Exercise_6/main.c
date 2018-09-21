#include <stdio.h>
#include <stdint.h>

void divider(uint32_t value)
{
    for (int  i = 1; i <= 500; ++i)
    {
        printf("result %d / %d = %.3f\n", i, value,  (float) i / value);
    }

}

int main()
{
    divider(15);
    
    return 0;
}