/*
 * ULTRASONIC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_


//to define pin of trigger
#include "../../LIB/Std_types.h"
#include "../../MCAL/DIO/DIO.h"
#include"../../MCAL/TIMER/TIMER_1/Timer1.h"
#include <util/delay.h>
#include"../LCD_V2/LCD_V2.h"
#define trig0 PIN0 //FRONT
#define trig1 PIN1 //FRONT RIGHT
#define trig2 PIN3 //RIGHT BACK
#define trig3 PIN4  //
#define trig4 PIN5

#define trig_port  PORTA_ID
uint32 Ultrasonic_front_Get_Distance(void);
uint32 Ultrasonic_right_front_Get_Distance(void);
uint32 Ultrasonic_right_back_Get_Distance(void);
uint32 Ultrasonic_back_Get_Distance(void);
uint32 Ultrasonic_back2_Get_Distance(void);
void Ultrasonic_init(void);
#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
