/*
 * MCP3821.c
 *
 *  Created on: 21 May 2020
 *      Author: Sam
 */

#include "MCP3821.h"

/* Select the correct SPI handler */
extern 	SPI_HandleTypeDef 	hspi2;
/* Define the cs pin */
#define MCP3821_CS_Pin 		GPIO_PIN_6
#define MCP3821_CS_Port 	GPIOC

/* Functions */
/**
 *  @brief 	Set MCP3821 output voltage.
 *  @param 	DAC output voltage
 *  @retval void
 */
void set_dac_voltage(float volt) {

	uint8_t dac_cmd[2] = { 0 };
	uint16_t dac_code = 0;

	/* set volt to 0V if it is outside (0-2.048V) */
	if ((volt < 0) | (volt > 2.048)) {
		volt = 0;
	}

	/* This compute the DAC input code from the target voltage.
	 * (Calculation in mV) */
	dac_code = 4096 / 2048 * volt * 1000;
	dac_cmd[0] = 0b00110000 | (dac_code >> 8);
	dac_cmd[1] = (uint8_t) dac_code;

	/* Send the command through SPI. */
	HAL_GPIO_WritePin(MCP3821_CS_Port, MCP3821_CS_Pin, 0);
	HAL_Delay(1);
	HAL_SPI_Transmit(&hspi2, dac_cmd, 2, 100);
	HAL_Delay(1);
	HAL_GPIO_WritePin(MCP3821_CS_Port, MCP3821_CS_Pin, 1);

}
