/*
 * frontend.h
 *
 *  Created on: 22 May 2020
 *      Author: Sam
 */

#ifndef INC_FRONTEND_H_
#define INC_FRONTEND_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"
#include <math.h>

/* Calibration values for load current */
#define CURRENT_OFFSET_1        -0.0006717
#define CURRENT_GAIN_OS_1       0.9423
#define CURRENT_OFFSET_2        0.0015909
#define CURRENT_GAIN_OS_2       0.9396

void set_load_current(float current);

#ifdef __cplusplus
}
#endif

#endif /* INC_FRONTEND_H_ */
