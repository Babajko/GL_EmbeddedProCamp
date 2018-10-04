#include <stdio.h>

void strCopy(char * sIn, char * sOut)
{
    int i = 0;
    while(sIn[i] != 0)
    {
        sOut[i] = sIn[i];
        i++;
    }
    sOut[i] = 0;
}

int main()
{   
    char * sIn = "Hello world!!!";
    char sOut[100];
   
    printf("sIn = %s\n", sIn);
    strCopy(sIn, sOut);
    printf("sOut = %s\n", sOut);
    return 0;
}