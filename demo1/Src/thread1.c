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
  
  while (1) {
    if (a_variable) {
      gpio_on();
    } else {
      gpio_off();
    }
  }
}