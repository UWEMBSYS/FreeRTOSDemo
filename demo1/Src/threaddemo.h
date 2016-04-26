#pragma once
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "FreeRTOS.h"
#include <queue.h>

/* Queue will holds uint32_t  */
typedef uint32_t QueueEntry_t;

extern QueueHandle_t hQueue;

/* monitor the USER button */
extern void task1_entry(void* p);


/*  toggle the LED */
extern void task2_entry(void* p);
