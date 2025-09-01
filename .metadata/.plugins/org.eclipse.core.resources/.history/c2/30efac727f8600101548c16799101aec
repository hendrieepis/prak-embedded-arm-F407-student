/*
 * sensor.c
 *
 *  Created on: Aug 31, 2025
 *      Author: hendri
 */
#include "main.h"
#include "usb_device.h"

#include <stdio.h>
#include "sensor.h"
// sensor.c dan sensor.h
uint8_t sensorDetected(void){
	uint32_t db_ms=20;
	uint8_t FlagDetect=0;
	if(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_RESET) {
		HAL_Delay(db_ms);
		if(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_RESET) {
			while(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_RESET);
			// tunggu release stabil
			HAL_Delay(db_ms);
			if(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_SET) {
				FlagDetect=1; // valid press
			}
		}
	}
	return FlagDetect;
}

uint8_t sensorDetectedTimeout(void){
	uint32_t db_ms=20;
	uint32_t  Timeout_loop=0;
	uint32_t  Timeout_value=0x7FFFFF;
	uint8_t FlagDetect=0;
	if(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_RESET) {
		HAL_Delay(db_ms);
		if(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_RESET) {
			while((!HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin))&& (Timeout_loop++<=Timeout_value));
			if (Timeout_loop>=Timeout_value)
			{
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_SET);
				HAL_Delay(1000);
				HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);
				HAL_Delay(1000);
				printf("Err:001-btn error \n\r");
			} else
			{
				// tunggu release stabil
				HAL_Delay(db_ms);
				if(HAL_GPIO_ReadPin(BTN_LEFT_GPIO_Port,BTN_LEFT_Pin)== GPIO_PIN_SET) {
					FlagDetect=1; // valid press
				}
			}
		}
	}
	return FlagDetect;
}


uint8_t resetDetected(void){
	uint32_t db_ms=20;
	uint8_t FlagDetect=0;
	if(HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port,BTN_RIGHT_Pin)== GPIO_PIN_RESET) {
		HAL_Delay(db_ms);
		if(HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port,BTN_RIGHT_Pin)== GPIO_PIN_RESET) {
			while(HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port,BTN_RIGHT_Pin)== GPIO_PIN_RESET);
			// tunggu release stabil
			HAL_Delay(db_ms);
			if(HAL_GPIO_ReadPin(BTN_RIGHT_GPIO_Port,BTN_RIGHT_Pin)== GPIO_PIN_SET) {
				FlagDetect=1; // valid press
			}
		}
	}
	return FlagDetect;
}

