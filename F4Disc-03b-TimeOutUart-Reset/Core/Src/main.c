#include "main.h"
#include "usb_device.h"
#include <stdio.h>
#include "hardwareinit.h"
#include "counter.h"
#include "sensor.h"
#include "utility.h"


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_I2C1_Init();
	MX_I2S3_Init();
	MX_SPI1_Init();
	MX_USB_DEVICE_Init();
	uint32_t t0 = HAL_GetTick();
	while (!usb_is_configured() && (HAL_GetTick() - t0) < 2000) {
		HAL_Delay(10);
	}
	HAL_Delay(700); //fix auto connect serial app
	checkBoard();

	while (1)
	{

		if(sensorDetectedTimeout()){
			counterUpdate();
			printf("nilai counter: %d \n\r",counterShow());
		}

		if(resetDetectedTimeout()){
			counterZero();
			printf("nilai counter: %d \n\r",counterShow());
		}
	}
}
