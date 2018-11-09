#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"
#include "stm32f3_discovery.h"
#include "stm32f30x_tim.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_usart.h"

void init(void);
void open(void);
uint16_t read(void);
void write(uint8_t b);
void close(void);
void deinit(void);
void writeStr(char * str);
void writeBuffer(uint16_t * data, uint8_t length);

#endif /* __MAIN_H */
