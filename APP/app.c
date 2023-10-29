/*
 * app.c
 *
 *  Created on: Sep 1, 2023
 *      Authors: Mohamed Abosreea , Ahmed Maher , Kareem Abd Elrasheed , Mohamed Ramadan , Amr Gafer
 */

#include "../HAL/LDR/LDR_interface.h"
#include "../HAL/ULTRASONIC/ultrasonic_sensor.h"

#include "driverlib/sysctl.h"

#include "robot.h"
#include "app.h"

extern uint32_t LDR1_Read;
extern uint32_t LDR2_Read;

uint16_t Ultrasonic_distance=0U;

int16_t LDR_diffrance_value =0U;

LDR_Sensor_t LDR1 = {
                     .ldrPort = GPIO_PORTE_BASE,
                     .ldrPin = GPIO_PIN_1,
                     .adcChannel = ADC_CTL_CH1,
                     .sequencer = 0U
};

LDR_Sensor_t LDR2 = {
                     .ldrPort = GPIO_PORTE_BASE,
                     .ldrPin = GPIO_PIN_2,
                     .adcChannel = ADC_CTL_CH2,
                     .sequencer = 1U
};

ultraSonic_t Ultrasonic_Sensor = {
                     .ultrasonicPort = GPIO_PORTC_BASE,
                     .ultrasonicTriggerPin = GPIO_PIN_5,
                     .ultrasonicEchoPin = GPIO_PIN_6
};

void APP_SystemEnableClk(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

}

void APP_SystemSetUp(void)
{

    APP_SystemEnableClk();

    /*LDR init*/
    ldrSensorInit(&LDR1);
    ldrSensorInit(&LDR2);

    /*Ultrasonic init*/
    ultarsonicSensorInit(&Ultrasonic_Sensor);

    /*Motors init*/
    robotInit();
}

void APP_SystemON(void)
{
    //robotMoveForward();
    /*trigger to start conversion*/
    ldrSensorReading(&LDR1);
    ldrSensorReading(&LDR2);
    LDR_diffrance_value = LDR2_Read - LDR1_Read;
    /*check LDRs value*/
    if( (400U > LDR_diffrance_value))
    {
        robotMoveForward();
    }
    else
    {

        if(0<LDR_diffrance_value)
        {
            robotMoveRight();
        }
        else
        {
            robotMoveLeft();
        }
        LDR_diffrance_value = 0U;
    }

    /*get distance*/
    Ultrasonic_distance = ultarsonicSensorReadValue(&Ultrasonic_Sensor);

    /*check the car is blocked*/
    if((10U < Ultrasonic_distance) || (0U ==Ultrasonic_distance ))
    {
        robotMoveForward();

    }
    else
    {
        robotMoveStop();
        robotMoveRotate();
        robotMoveStop();
    }


}
