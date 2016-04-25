#include "threaddemo.h"
#include <stdbool.h>

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
  while (1) {
    if (get_button()) {
      a_variable = 1;
    } else {
      a_variable = 0;
    }
  }
  
}