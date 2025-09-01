/*
 * sensor.h
 *
 *  Created on: Aug 31, 2025
 *      Author: hendri
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

// sensor.c dan sensor.h
uint8_t sensorDetected(void);
uint8_t sensorDetectedTimeout(void);
uint8_t resetDetected(void);
uint8_t resetDetectedTimeout(void);

#endif /* INC_SENSOR_H_ */
