/*
 * Timer0.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef MCAL_TIMER_TIMER_0_TIMER0_H_
#define MCAL_TIMER_TIMER_0_TIMER0_H_

#include "../../../LIB/std_types.h"
#include "../../../LIB/utils.h"

#include "../../../LIB/memmap128.h"
#include"Timer0_config.h"
//PRESCALLER
//PRESCALLER FOR TIMER 0
typedef enum{
	timer0_stop=0,
	timer0_scale_1,
	timer0_scale_8,
	timer0_scale_32,
	timer0_scale_64,
	timer0_scale_128,
	timer0_scale_256,
	timer0_scale_1024
}prescaler0_type;
//..................................
//timer0 mode
typedef enum
{
	Normal_mode=0,
	Phasecorrect_mode,
	CTC_mode,
	FastPWM_mode

}timer0_mode_type;
//.......................

#if oc==normal
typedef enum
{
	disconnected=0,
	Toggle,
	Nin_inverting,
	Inverting

}OC0_mode_type;
//.......................
#elif oc==fastpwm
typedef enum
{
	disconnected=0,
	reserved,
	Non_inverting_clr_oc0_oncompare_set_on_bottom,
	Inverting_set_oc0_oncompare_clr_on_bottom,

}OC0_mode_type;

//.......................
#elif oc==phasepwm
typedef enum
{
	disconnected=0,
	reserved,
	Non_inverting_clr_oc0_oncompare_up_set_oncompare_down,
	Inverting_set_oc0_oncompare_up_clr_oncompare_down,

}OC0_mode_type;
#endif

//.....................................................................................

void Timer0_Init( timer0_mode_type mode,prescaler0_type scaler ,OC0_mode_type oc_mode);
void Timer0_OVInterrupt_Enable(void);
void Timer0_OVInterrupt_Disable(void);
void Timer0_OCInterrupt_Enable(void);
void Timer0_OCInterrupt_Disable(void);
void Timer0_OCI_Set_Value(uint8 oc_value);
void Timer0_TCNT_Set_Value(uint8 TCNT_value);
uint8 Timer0_Get_Value(void);

//....................................................................................
#endif /* MCAL_TIMER_TIMER_0_TIMER0_H_ */
