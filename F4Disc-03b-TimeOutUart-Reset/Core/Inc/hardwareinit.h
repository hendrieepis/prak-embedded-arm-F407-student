/*
 * hardwareinit.h
 *
 *  Created on: Aug 31, 2025
 *      Author: hendri
 */

#ifndef INC_HARDWAREINIT_H_
#define INC_HARDWAREINIT_H_
uint8_t usb_is_configured(void);
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_I2C1_Init(void);
void MX_I2S3_Init(void);
void MX_SPI1_Init(void);


#endif /* INC_HARDWAREINIT_H_ */
