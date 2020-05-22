/*
 * frontend.c
 *
 *  Created on: 22 May 2020
 *      Author: Sam
 */

#include "frontend.h"
#include "MCP3821.h"

/**
 *  @brief 	Set the load current.
 *  @param 	current
 *  @retval void
 */
void set_load_current(float current) {
	if (current <= 0.1)
		set_dac_voltage(current * CURRENT_GAIN_OS_1 + CURRENT_OFFSET_1);
	else
		set_dac_voltage(current * CURRENT_GAIN_OS_2 + CURRENT_OFFSET_2);
}
