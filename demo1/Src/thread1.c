#include "threaddemo.h"

/* GPIO lives at PA5 */

static void gpio_on(void)
{
  /* LED is on when high */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

static void gpio_off(void)
{
  /* LED is off when low */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

/* Set the LED to be off when a_variable is zero, and on otherwise */
void task1_entry(void* p)
{
  /* should verify q handle is valid */
  while (1) {
    QueueEntry_t a_variable;
    if (pdTRUE == xQueueReceive(hQueue, &a_variable, portMAX_DELAY)) {
      if (a_variable) {
        gpio_on();
      } else {
        gpio_off();
      }
    }
  }
}