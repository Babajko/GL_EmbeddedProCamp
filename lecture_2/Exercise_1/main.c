#include <stdio.h>
#include <stdint.h>

uint16_t swap16(uint16_t value){
    uint16_t result;
   
    result = (value >> 8);
    result |= (value & 0xff) << 8;
    return result;
}
uint32_t swap32(uint32_t value){
    uint8_t *p = &value;
    uint32_t result = 0;
    for (int i = sizeof(value)-1; i >= 0; i--){
        result |= *p << (i * 8); 
        *p++;
    }
    return result;
}
uint64_t swap64(uint64_t value){
    uint8_t *p = &value;
    uint64_t result = 0;
    for (int i = sizeof(value) - 1; i >= 0; i--){
        result |= *p << (i * 8); 
        *p++;
    }
    return result;
}

int main()
{
    return 0;
}