/*
 * Timer1.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef MCAL_TIMER_TIMER_1_TIMER1_H_
#define MCAL_TIMER_TIMER_1_TIMER1_H_

#include "../../../LIB/std_types.h"
#include "../../../LIB/utils.h"
#include "../../../LIB/memmap128.h"
#include"Timer1_config.h"

//PRESCALLER FOR TIMER 1 OR TIMER3
typedef enum{
	timer_stop=0,
	timer_scale_1,
	timer_scale_8,
	timer_scale_64,
	timer_scale_256,
	timer_scale_1024,
	timer_EXT_CLK_T1_OR_T3_PIN_FALLING_EDGE,
	timer_EXT_CLK_T1_OR_T3_PIN_RISING_EDGE
}prescaler1_type;
//.............................................
typedef enum{
	Falling,
	Rising
}Edge_type;

//............................................
//timer1 mode
typedef enum
{
	timer1_Normal_mode=0,                               //0xffff top
	timer1_PWM_Phase_Correct_8bit,                      //0x00ff top
	timer1_PWM_Phase_Correct_9bit,                      //0x01ff top
	timer1_PWM_Phase_Correct_10bit,                     //0x03ff top
	timer1_CTC_mode_ocr_top,                            //ocr top
	timer1_Fast_PWM_8_bit,                              //0x00ff top
	timer1_Fast_PWM_9_bit,                              //0x01ff top
	timer1_Fast_PWM_10_bit,                             //0x03ff top
	timer1_PWM_Phase_and_Freq_Correct_icr_top,          //ICR  top
	timer1_PWM_Phase_and_Freq_Correct_ocr_top,          //ocr  top
	timer1_PWM_Phase_Correct_icr_top,                   //ICR  top
	timer1_PWM_Phase_Correct_ocr_top,                    //ocr  top
	timer1_CTC_mode_icr_top,                             //icr top
	timer1_Fast_PWM_icr_top=13,                          //icr top
	timer1_Fast_PWM_ocr_top                              //ocr top
}timer1_mode_type;
//.......................
typedef enum
{
	disconnected_channel,
	A_Channel,
	B_Channel,
	C_Channel
}OC1_ch_type;
#if oc_1==normal_1
typedef enum
{
	disconnected_1=0,
	//oca,ocb,occ
	Toggle_1,
	//oca,ocb,occ
	Non_inverting_1,
	//oca,ocb,occ
	Inverting_1

}OC1_mode_type;
//.......................
#elif oc_1==fastpwm_1
typedef enum
{
	disconnected_1=0,
	//oca,ocb,occ
	toggle_1,
	//oca,ocb,occ
	Non_inverting_clr_oc0_oncompare_set_on_bottom_1,
	//oca,ocb,occ
	Inverting_set_oc0_oncompare_clr_on_bottom_1,

}OC1_mode_type;

//.......................
#elif oc_1==phasepwm_1
typedef enum
{
	disconnected_1=0,
	//oca
	toggle_1,
	//oca,ocb,occ
	Non_inverting_clr_oc0_oncompare_up_set_oncompare_down_1,
	//oca,ocb,occ
	Inverting_set_oc0_oncompare_up_clr_oncompare_down_1,

}OC1_mode_type;
#endif

void Timer1_Init(timer1_mode_type timer_mode,prescaler1_type scaler,OC1_mode_type oc1_mode,OC1_ch_type channel_t);


void Timer1_InputCaptureEdge(Edge_type edge);

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OV_InterruptEnable(void);
void Timer1_OV_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OCC_InterruptEnable(void);
void Timer1_OCC_InterruptDisable(void);
uint16  TMR1_uint16_GetICUValue(void);
uint16  TMR1_uint16_GetTimerValue(void);
void  TMR1_void_SetTimerValue(uint16 tmr_val);
void  TMR1_void_Set_OCR_TimerValue(uint16 oc_val,OC1_ch_type ch);
#endif /* MCAL_TIMER_TIMER_1_TIMER1_H_ */
