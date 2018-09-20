#include <stdio.h>
#include <stdint.h>

uint16_t swap16(uint16_t value){
    uint16_t result;
    result = (value >> 8);
    result |= (value & 0xff) << 8;
    return result;
}
uint32_t swap32(uint32_t value){
    uint32_t result;
    
    result = swap16((uint16_t)(value >> 16));
    result |= swap16((uint16_t)value) << 16;
    return result;
}
uint64_t swap64(uint64_t value){
    uint64_t result;
    
    result = swap32((uint32_t)value);
    result = result << 32;
    result |= swap32((uint32_t)(value >> 32));
    return result;
}

int main()
{
    printf("swap16 = %x\n", swap16(0x1122));
    printf("swap32 = %x\n", swap32(0x11223344));
    printf("swap64 = %x %x\n", (uint32_t)(swap64(0x1122334455667788) >> 32), 
            (uint32_t)(swap64(0x1122334455667788)));
    return 0;
}