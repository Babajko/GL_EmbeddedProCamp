
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "ChipInit.h"
#include "queue.h"


TaskHandle_t Task1Handle, Task2Handle;


//=================================================================
//=================================================================
void Task_2(void * argument)
{
  volatile int i;
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
		HAL_GPIO_TogglePin(GPIOE, LD6_Pin);
		osDelay(100);
  }
  /* USER CODE END 5 */ 
}

//=================================================================
//=================================================================
void Task_1(void * argument)
{
  volatile int i = 1000;
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    if (i == 500){
			xTaskCreate(Task_2, "Task 2", 128, 0, osPriorityNormal, &Task2Handle);
			vTaskPrioritySet ( NULL, osPriorityNormal + 1 );
		} else if (i == 100){
			vTaskDelete(Task2Handle);
		} else if (i == 0){
			i = 1000;
			vTaskPrioritySet ( NULL, osPriorityNormal);
		}
    i--;
		osDelay(10);
  }
  /* USER CODE END 5 */ 
}

//=================================================================
//=================================================================
void vApplicationIdleHook(void)
{
	if (Task2Handle == NULL)
	{
		HAL_GPIO_WritePin(GPIOE, LD10_Pin, GPIO_PIN_SET);
	}
	else 
	{
		HAL_GPIO_WritePin(GPIOE, LD10_Pin, GPIO_PIN_RESET);
	}
		
}

//=================================================================
//=================================================================
int main(void)
{
  ChipInit ();
	
	xTaskCreate(Task_1, "Task 1", 128, 0, osPriorityNormal, &Task1Handle);
  
  vTaskStartScheduler();
  /* We should never get here as control is now taken by the scheduler */
  while (1)
  {

  }

}

