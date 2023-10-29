/*
 * LDR_interface.h
 *
 *  Created on: Sep 1, 2023
 *      Authors: Mohamed Abosreea , Ahmed Maher , Kareem Abd Elrasheed , Mohamed Ramadan , Amr Gafer
 */
#ifndef HAL_LDR_LDR_INTERFACE_H_
#define HAL_LDR_LDR_INTERFACE_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "../../LIB/tm4c123gh6pm.h"

#define NULL (void *)(0)


typedef struct {
    uint32_t ldrPort;
    uint8_t  ldrPin;
    uint32_t adcChannel;
    uint32_t sequencer;
}LDR_Sensor_t;


void ADC0SS0_Handler(void);

void ADC0SS1_Handler(void);

/*This function is used to initialize the ultrasonic sensor
 * @param sensor [port , pin , analog channel]
 * @return
 * */
void ldrSensorInit(LDR_Sensor_t *sensor);

/*This function is used to initialize the ultrasonic sensor
 * @param sensor [port , pin , analog channel]
 * @return [ 0 - 4095]
 * */
void ldrSensorReading(LDR_Sensor_t *sensor);


#endif /* HAL_LDR_LDR_INTERFACE_H_ */
