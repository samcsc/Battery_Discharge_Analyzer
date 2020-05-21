/*
 * temperature_sensor.h
 *
 *  Created on: May 21, 2020
 *      Author: Sam
 */

#ifndef INC_TEMPERATURE_SENSOR_H_
#define INC_TEMPERATURE_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"
#include <math.h>

/* Temperature sensor parameters*/
#define MAX_TIME_OUT	500
#define VREF            3.3
#define R_BOT           2000
#define R_25            10000
#define A1              3.354016E-03
#define B1              2.56524E-04
#define C1              2.60597E-06
#define D1              6.32926E-08

float read_ntc_temperature(void);

#ifdef __cplusplus
}
#endif



#endif /* INC_TEMPERATURE_SENSOR_H_ */
