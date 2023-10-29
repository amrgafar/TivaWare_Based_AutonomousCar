/*
 * robot.c
 *
 *  Created on: Sep 1, 2023
 *      Authors: Mohamed Abosreea , Ahmed Maher , Kareem Abd Elrasheed , Mohamed Ramadan , Amr Gafer , Ahmed saeed
 */

#include "../HAL/MOTOR/motor.h"
#include "robot.h"

carSide_t LEFT_SIDE  = {
                        .carSidePort = GPIO_PORTB_BASE,
                        .carSideDir1Pin = GPIO_PIN_7,
                        .carSideDir2Pin = GPIO_PIN_1,
                        .carSideEnPin = GPIO_PIN_6,
                        .carSideSpeed = 30

};
carSide_t RIGHT_SIDE = {
                        .carSidePort = GPIO_PORTB_BASE,
                        .carSideDir1Pin = GPIO_PIN_4,
                        .carSideDir2Pin = GPIO_PIN_5,
                        .carSideEnPin = GPIO_PIN_0,
                        .carSideSpeed = 30
};

void robotInit()
{
    carSideInit(&LEFT_SIDE , &RIGHT_SIDE);
}

void robotMoveForward(void)
{
    carSideConfig(&LEFT_SIDE , forward);
    carSideConfig(&RIGHT_SIDE , forward);
}

void robotMoveStop(void)
{
    carSideConfig(&LEFT_SIDE , stop);
    carSideConfig(&RIGHT_SIDE , stop);
    SysCtlDelay(200000);
}

void robotMoveRotate(void)
{
    carSideConfig(&LEFT_SIDE , backward);
    carSideConfig(&RIGHT_SIDE , forward);
    SysCtlDelay(5000000);
    SysCtlDelay(2500000);
}

void robotMoveRight(void)
{
    carSideConfig(&LEFT_SIDE , stop);
    //carSideConfig(&LEFT_SIDE , backward);
    carSideConfig(&RIGHT_SIDE , forward);
}

void robotMoveLeft(void)
{
    carSideConfig(&LEFT_SIDE , forward);
    carSideConfig(&RIGHT_SIDE , stop);
    //carSideConfig(&RIGHT_SIDE , backward);
}

