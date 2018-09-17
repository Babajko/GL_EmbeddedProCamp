#include "main.h"

GPIO_InitTypeDef GPIO_InitStructure;

static volatile uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
void Delay(volatile uint32_t nTime);


int main(void)
{  
  /* Initialize Leds mounted on STM32F3-discovery */
  STM_EVAL_LEDInit(LED10); 
	SysTick_Config(SystemCoreClock / 1000);

  while (1)
  {
    STM_EVAL_LEDToggle(LED10);
    Delay(150);
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(volatile uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

