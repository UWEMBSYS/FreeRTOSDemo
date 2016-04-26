#include "threaddemo.h"
#include <stdbool.h>
#include <semphr.h>

static SemaphoreHandle_t semaBin;

/* Return true when button is pressed */
static bool get_button(void)
{
  bool pressed = true;
  if (GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)) {
    pressed = false;
  }     
  return pressed;
}

void task2_entry(void* p)
{
  /*  */ 
  semaBin = xSemaphoreCreateBinary();
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
  while (1) {
    xSemaphoreTake(semaBin, portMAX_DELAY);
    QueueEntry_t a_variable;
    if (get_button()) {
      a_variable = 1;
    } else {
      a_variable = 0;
    }
     xQueueSend(hQueue, &a_variable, portMAX_DELAY);

    
  }
  
}

void EXTI15_10_IRQHandler(void) {

  if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_13) != RESET)
  {
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
    xSemaphoreGiveFromISR(semaBin, NULL);
    
  }
}
