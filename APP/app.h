/*
 * app.h
 *
 *  Created on: Sep 1, 2023
 *     Authors: Mohamed Abosreea , Ahmed Maher , Kareem Abd-Elrasheed , Mohamed Ramadan , Amr Gafer , Ahmed Saeed
 */

#ifndef APP_APP_H_
#define APP_APP_H_

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

/******************************************************************************
* \Syntax          : APP_SystemEnableClk
* \Description     : enable sys clock
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void APP_SystemEnableClk(void);
/******************************************************************************
* \Syntax          : APP_SystemSetUp
* \Description     : init all devices
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void APP_SystemSetUp(void);
/******************************************************************************
* \Syntax          : APP_SystemON
* \Description     : go to application
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void APP_SystemON(void);


#endif /* APP_APP_H_ */
