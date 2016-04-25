#pragma once
#include <stdint.h>
#include "stm32f4xx_hal.h"

extern volatile uint32_t a_variable;

/* monitor the USER button */
extern void task1_entry(void* p);


/*  toggle the LED */
extern void task2_entry(void* p);
