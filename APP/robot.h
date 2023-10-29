/*
 * robot.h
 *
 *  Created on: Sep 1, 2023
 *     Authors: Mohamed Abosreea , Ahmed Maher , Kareem Abd Elrasheed , Mohamed Ramadan , Amr Gafer ,Ahmed saeed
 */

#ifndef APP_ROBOT_H_
#define APP_ROBOT_H_

/******************************************************************************
* \Syntax          : robotInit
* \Description     : init robot
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void robotInit(void);
/******************************************************************************
* \Syntax          : robotMoveForward
* \Description     : move to forward direction
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void robotMoveForward(void);
/******************************************************************************
* \Syntax          : robotMoveStop
* \Description     : stop robot
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void robotMoveStop(void);
/******************************************************************************
* \Syntax          : robotMoveRotate
* \Description     : move to reverse direction
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void robotMoveRotate(void);
/******************************************************************************
* \Syntax          : robotMoveLeft
* \Description     : move to left direction
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void robotMoveLeft(void);
/******************************************************************************
* \Syntax          : robotMoveRight
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Non in
* \Parameters (out): Non out   void
* \Return value:   : void
*******************************************************************************/
void robotMoveRight(void);


#endif /* APP_ROBOT_H_ */
