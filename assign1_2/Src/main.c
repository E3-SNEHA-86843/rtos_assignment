/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "led.h"
#include"FreeRTOSConfig.h"
#include"FreeRTOS.h"
#include"task.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void vMainLedTask1(void * pvParam)
{
	int *ptr= pvParam;
	while(1){
		led_toggle(ptr,100);
		vTaskDelay(1000/portTICK_RATE_MS);
	}
	vTaskDelete(NULL);
}

int main(void)
{
	led_init();

	xTaskCreate(vMainLedTask1, "Aperiodic", configMINIMAL_STACK_SIZE, LED_GREEN, 4, NULL);
	xTaskCreate(vMainLedTask1, "Aperiodic", configMINIMAL_STACK_SIZE, LED_ORANGE, 4, NULL);
	xTaskCreate(vMainLedTask1, "Aperiodic", configMINIMAL_STACK_SIZE, LED_RED, 4, NULL);
	xTaskCreate(vMainLedTask1, "Aperiodic", configMINIMAL_STACK_SIZE, LED_BLUE, 4, NULL);

	vTaskStartScheduler();
	while(1);
}













