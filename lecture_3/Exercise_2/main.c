
#include <stdio.h>
#include <stdint.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxInArr(int * arr, uint16_t len)
{
    int result = arr[0];
    for (uint16_t i = 1; i < len; ++i)
    {
        result = max(result, arr[i]);
    }
    return result;
}

int main()
{

    int arr[5] = {0, -5, -4, -10, 0};
    
    printf("max = %d\n", maxInArr(arr, 5));

    return 0;
}