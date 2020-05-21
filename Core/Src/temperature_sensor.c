/*
 * temperature_sensor.c
 *
 *  Created on: May 21, 2020
 *      Author: Sam
 */

#include "temperature_sensor.h"

/* Variables */
/* Choose which ADC peripheral is connected to the NTC */
extern ADC_HandleTypeDef hadc1;

/* Functions */
/**
 *  @brief 	GEt reading from the temperature sensor.
 *  @param 	void
 *  @retval float temperature in degC.
 */
float read_ntc_temperature(void) {

    float temp_sensor_adc_value = 0;    /* ADC reading in V */
    float temp_sensor_res = 0;          /* NTC resistance in ohm */
    float temp_sensor_reading = 0;      /* Temperature in degC */
    int resolution = 0;

    switch (hadc1.Init.Resolution) {
    case ADC_RESOLUTION_12B:
        resolution = 4096;
        break;
    case ADC_RESOLUTION_10B:
        resolution = 1024;
        break;
    case ADC_RESOLUTION_8B:
        resolution = 256;
        break;
    case ADC_RESOLUTION_6B:
        resolution = 64;
        break;
    default:
        resolution = 1;
    }

    /* Start ADC conversion and compute the temperature using
     * the Steinhart-Hart equation, coefficients A1 to D1 are
     * given in the datasheet. The reading is good from -50degC
     * to 150degC. */
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, MAX_TIME_OUT) == HAL_OK) {
        temp_sensor_adc_value = HAL_ADC_GetValue(&hadc1) * VREF / resolution;
        temp_sensor_res = (VREF / temp_sensor_adc_value - 1) * R_BOT;
        temp_sensor_reading = A1 + B1 * log(temp_sensor_res / R_25)
                + C1 * pow(log(temp_sensor_res / R_25), 2)
                + D1 * pow(log(temp_sensor_res / R_25), 3);
        temp_sensor_reading = 1 / temp_sensor_reading - 273.15;
        return temp_sensor_reading;
    } else {
        return -1;
    }
}
