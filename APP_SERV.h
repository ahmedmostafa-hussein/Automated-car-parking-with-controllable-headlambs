/*
 * APP_SERV.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef HAL_APP_SERV_APP_SERV_H_
#define HAL_APP_SERV_APP_SERV_H_
//ALGORITHMS FUNCTION
#include"std_types.h"
#include"ULTRASONIC.h"
#include"LCD_V2.h"
#include"DIO.h"
#include"TIMER_0/Timer0.h"
#include"TIMER_1/Timer1.h"
#include"TIMER_3/Timer3.h"
#include"../BUZZER/BUZZER.h"
#include"../HAL/LCD_V2/LCD_V2.h"
//WE LEAVE FIRST PINS TO BE ABLE TO WORK WITH UART
#define forward          PIN3  //OC3A
#define backword         PIN5  //OC3C
#define left_wheel       PIN6 //
#define right_wheel      PIN7  //
#define stop             PIN2  //
#define car_control      PORTE_ID
#define auto_park_pin    PIN0
#define no_park_pin    PIN1
#define auto_park_port   PORTD_ID
void project_init(void);
void STOP_CAR(void);
void start_parking(void);
void LCD_LIGHT(void);
void forward_move(void);
void backward_move(void);
void right_move(void);
void right_half_move(void);
void right_QUARTER_move(void);
void left_move(void);
void left_half_move(void);
void left_QUARTER_move(void);
uint64 distance_rf(void);
uint64 distance_rb2(void);
uint8 CAR_Length_Check(void);
void CAR_Length_Check2(void);
void CAR_Length_Check3(void);
void CAR_Length_Check4(void);
void CAR_Width_Check(void);
void unparking(void);
#endif /* HAL_APP_SERV_APP_SERV_H_ */
