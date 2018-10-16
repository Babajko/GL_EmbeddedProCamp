#include "main.h"

#define MAX_BUFFER 100

USART_InitTypeDef usart;
USART_ClockInitTypeDef usartClock;
GPIO_InitTypeDef port;

 
/*******************************************************************/



/* Private function prototypes -----------------------------------------------*/


int main(void)
{  	
	init();
	open();
	
	uint16_t data [MAX_BUFFER];
	uint16_t count = 0;
  while (1)
  {
		while (count < MAX_BUFFER)
		{
			data[count] = read();
			if (data[count] == 13) break;
			count++;
		}
		if (data[count] == 13)
		{
			writeBuffer(data, count + 1);
		} else {
			writeStr("Buffer overflow");
			write(13);
		}		
		count = 0;
  }	
	//close();
	//deinit();
}

void open(void)
{
	USART_Cmd(USART1, ENABLE);
}

void init(void)
{		
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	
	
	GPIO_StructInit(&port);	
	port.GPIO_Pin |= GPIO_Pin_4 | GPIO_Pin_5;
	port.GPIO_Mode = GPIO_Mode_AF;
	port.GPIO_Speed = GPIO_Speed_50MHz;
	port.GPIO_OType = GPIO_OType_PP;
	port.GPIO_PuPd = GPIO_PuPd_NOPULL;	
	
	GPIO_Init (GPIOC, &port);	
	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource4, GPIO_AF_7);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource5, GPIO_AF_7);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	USART_StructInit(&usart);
	usart.USART_BaudRate = 9600;	
	USART_Init(USART1, &usart);
	
}

void writeStr(char * str)
{
	uint8_t i = 0;

	while (str[i] != 0)
	{
		//waiting end of transmit
		while (!USART_GetFlagStatus(USART1, USART_FLAG_TC)){}
		write(str[i]);
		i++;
	}
}

void writeBuffer(uint16_t * data, uint8_t length)
{
	for(uint8_t i = 0; i < length; ++i)
	{
		//waiting end of transmit
		while (!USART_GetFlagStatus(USART1, USART_FLAG_TC)){}
		write(data[i]);
	}
}

void write(uint8_t b)
{
	USART_SendData(USART1, b);
}

void close(void)
{
	USART_Cmd(USART1, DISABLE);
}

void deinit(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, DISABLE);
		
	port.GPIO_Pin |= GPIO_Pin_4 | GPIO_Pin_5;
	port.GPIO_Mode = GPIO_Mode_OUT;
	port.GPIO_Speed = GPIO_Speed_50MHz;
	port.GPIO_OType = GPIO_OType_PP;
	port.GPIO_PuPd = GPIO_PuPd_NOPULL;	
	
	GPIO_Init (GPIOC, &port);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, DISABLE);		
}

uint16_t read(void)
{
	//waiting of data
	while(!USART_GetFlagStatus(USART1, USART_FLAG_RXNE)){}
	USART_ClearFlag(USART1, USART_FLAG_RXNE);
	return USART_ReceiveData(USART1);
}
