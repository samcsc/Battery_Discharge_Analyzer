/*
 * MCP3821.h
 *
 *  Created on: 21 May 2020
 *      Author: Sam
 */

#ifndef INC_MCP3821_H_
#define INC_MCP3821_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"
#include <math.h>

void set_dac_voltage(float volt);

#ifdef __cplusplus
}
#endif

#endif /* INC_MCP3821_H_ */
