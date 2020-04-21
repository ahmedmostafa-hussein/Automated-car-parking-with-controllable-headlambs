/*
 * Timer3.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef MCAL_TIMER_TIMER_3_TIMER3_H_
#define MCAL_TIMER_TIMER_3_TIMER3_H_

#include "../../../LIB/std_types.h"
#include "../../../LIB/utils.h"
#include "../../../LIB/memmap128.h"
#include"Timer3_config.h"

//PRESCALLER FOR TIMER 3 OR TIMER3
typedef enum{
	timer3_stop=0,
	timer3_scale_1,
	timer3_scale_8,
	timer3_scale_64,
	timer3_scale_256,
	timer3_scale_1024,
	timer3_EXT_CLK_T1_OR_T3_PIN_FALLING_EDGE,
	timer3_EXT_CLK_T1_OR_T3_PIN_RISING_EDGE
}prescaler3_type;
//.............................................
typedef enum{
	Falling_3,
	Rising_3
}Edge3_type;

//............................................
//timer3 mode
typedef enum
{
	timer3_Normal_mode=0,                               //0xffff top
	timer3_PWM_Phase_Correct_8bit,                      //0x00ff top
	timer3_PWM_Phase_Correct_9bit,                      //0x01ff top
	timer3_PWM_Phase_Correct_10bit,                     //0x03ff top
	timer3_CTC_mode_ocr_top,                            //ocr top
	timer3_Fast_PWM_8_bit,                              //0x00ff top
	timer3_Fast_PWM_9_bit,                              //0x01ff top
	timer3_Fast_PWM_10_bit,                             //0x03ff top
	timer3_PWM_Phase_and_Freq_Correct_icr_top,          //ICR  top
	timer3_PWM_Phase_and_Freq_Correct_ocr_top,          //ocr  top
	timer3_PWM_Phase_Correct_icr_top,                   //ICR  top
	timer3_PWM_Phase_Correct_ocr_top,                    //ocr  top
	timer3_CTC_mode_icr_top,                             //icr top
	timer3_Fast_PWM_icr_top=13,                          //icr top
	timer3_Fast_PWM_ocr_top                              //ocr top
}timer3_mode_type;
//.......................
typedef enum
{
	disconnected_channel_3,
	A_Channel_3,
	B_Channel_3,
	C_Channel_3
}OC3_ch_type;
#if oc_3==normal_3
typedef enum
{
	disconnected_3=0,
	//oca,ocb,occ
	Toggle_3,
	//oca,ocb,occ
	Non_inverting_3,
	//oca,ocb,occ
	Inverting_3

}OC3_mode_type;
//.......................
#elif oc_3==fastpwm_3
typedef enum
{
	disconnected_3=0,
	//oca,ocb,occ
	toggle_3,
	//oca,ocb,occ
	Non_inverting_clr_oc0_oncompare_set_on_bottom_3,
	//oca,ocb,occ
	Inverting_set_oc0_oncompare_clr_on_bottom_3,

}OC3_mode_type;

//.......................
#elif oc_3==phasepwm_3
typedef enum
{
	disconnected_3=0,
	//oca
	toggle_3,
	//oca,ocb,occ
	Non_inverting_clr_oc0_oncompare_up_set_oncompare_down_3,
	//oca,ocb,occ
	Inverting_set_oc0_oncompare_up_clr_oncompare_down_3,

}OC3_mode_type;
#endif

void Timer3_Init(timer3_mode_type timer_mode,prescaler3_type scaler,OC3_mode_type oc3_mode,OC3_ch_type channel_t);


void Timer3_InputCaptureEdge(Edge3_type edge);

void Timer3_ICU_InterruptEnable(void);
void Timer3_ICU_InterruptDisable(void);
void Timer3_OV_InterruptEnable(void);
void Timer3_OV_InterruptDisable(void);
void Timer3_OCA_InterruptEnable(void);
void Timer3_OCA_InterruptDisable(void);
void Timer3_OCB_InterruptEnable(void);
void Timer3_OCB_InterruptDisable(void);
void Timer3_OCC_InterruptEnable(void);
void Timer3_OCC_InterruptDisable(void);
uint16  TMR3_uint16_GetICUValue(void);
uint16  TMR3_uint16_GetTimerValue(void);
void  TMR3_void_SetTimerValue(uint16 tmr_val);
void  TMR3_void_Set_OCR_TimerValue(uint16 oc_val,OC3_ch_type ch);


#endif /* MCAL_TIMER_TIMER_3_TIMER3_H_ */
