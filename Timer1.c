#include"Timer1.h"
void Timer1_Init(timer1_mode_type timer_mode,prescaler1_type scaler,OC1_mode_type oc1_mode,OC1_ch_type channel_t)
{
switch (timer_mode)
 {

case timer1_Normal_mode:                          CLR_BIT(TCCR1A,WGM10);
						                          CLR_BIT(TCCR1A,WGM11);
						                          CLR_BIT(TCCR1B,WGM12);
						                          CLR_BIT(TCCR1B,WGM13);
                                                  break;
case timer1_PWM_Phase_Correct_8bit:               SET_BIT(TCCR1A,WGM10);
							                      CLR_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_PWM_Phase_Correct_9bit:               CLR_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_PWM_Phase_Correct_10bit:              SET_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_CTC_mode_ocr_top:                     CLR_BIT(TCCR1A,WGM10);
							                      CLR_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_Fast_PWM_8_bit:                       SET_BIT(TCCR1A,WGM10);
							                      CLR_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_Fast_PWM_9_bit:                       CLR_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_Fast_PWM_10_bit:                      SET_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      CLR_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_PWM_Phase_and_Freq_Correct_icr_top:   CLR_BIT(TCCR1A,WGM10);
							                      CLR_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_PWM_Phase_and_Freq_Correct_ocr_top:   SET_BIT(TCCR1A,WGM10);
							                      CLR_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_PWM_Phase_Correct_icr_top:            CLR_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_PWM_Phase_Correct_ocr_top:            SET_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      CLR_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_CTC_mode_icr_top:                     CLR_BIT(TCCR1A,WGM10);
							                      CLR_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_Fast_PWM_icr_top:                     CLR_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
case timer1_Fast_PWM_ocr_top:                     SET_BIT(TCCR1A,WGM10);
							                      SET_BIT(TCCR1A,WGM11);
							                      SET_BIT(TCCR1B,WGM12);
							                      SET_BIT(TCCR1B,WGM13);
	                                              break;
}


#if  oc_1==normal_1
switch (oc1_mode)
{
case disconnected_1:
						CLR_BIT(TCCR1A,COM1A0);
						CLR_BIT(TCCR1A,COM1A1);

						CLR_BIT(TCCR1A,COM1B0);
						CLR_BIT(TCCR1A,COM1B1);

						CLR_BIT(TCCR1A,COM1C0);
						CLR_BIT(TCCR1A,COM1C1);
						break;
case Toggle_1:switch(channel_t)
                  {
                      case disconnected_channel:break;
                      case A_Channel:SET_BIT(TCCR1A,COM1A0);
						             CLR_BIT(TCCR1A,COM1A1);
						             break;
                      case B_Channel:SET_BIT(TCCR1A,COM1B0);
                      				 CLR_BIT(TCCR1A,COM1B1);
                      		         break;
                      case C_Channel:SET_BIT(TCCR1A,COM1C0);
                      			     CLR_BIT(TCCR1A,COM1C1);
                      				 break;
                    }
						break;
case Non_inverting_1:switch(channel_t)
                        {
                          case disconnected_channel:break;
                          case A_Channel:CLR_BIT(TCCR1A,COM1A0);
						                 SET_BIT(TCCR1A,COM1A1);
						                 break;
                          case B_Channel:CLR_BIT(TCCR1A,COM1B0);
                          				 SET_BIT(TCCR1A,COM1B1);
                          				 break;
                          case C_Channel:CLR_BIT(TCCR1A,COM1C0);
                          				 SET_BIT(TCCR1A,COM1C1);
                          				 break;
                         }
						break;
case Inverting_1:switch(channel_t)
                     {

                       case disconnected_channel:break;
                       case A_Channel:SET_BIT(TCCR1A,COM1A0);
                                      SET_BIT(TCCR1A,COM1A1);
                                      break;
                       case B_Channel:SET_BIT(TCCR1A,COM1B0);
  				                      SET_BIT(TCCR1A,COM1B1);
  			                       	  break;
                       case C_Channel:SET_BIT(TCCR1A,COM1C0);
  				                      SET_BIT(TCCR1A,COM1C1);
  				                       break;
                      }

						break;
}
#elif oc_1==fastpwm_1

switch (oc_mode)
{
case disconnected:CLR_BIT(TCCR1A,COM1A0);
                  CLR_BIT(TCCR1A,COM1A1);

                  CLR_BIT(TCCR1A,COM1B0);
                  CLR_BIT(TCCR1A,COM1B1);

                  CLR_BIT(TCCR1A,COM1C0);
                  CLR_BIT(TCCR1A,COM1C1);
				  break;
case reserved:break;
case Non_inverting_clr_oc0_oncompare_set_on_bottom:
	switch(channel_t)
	   {
	     case disconnected_channel:break;
	     case A_Channel:CLR_BIT(TCCR1A,COM1A0);
					    SET_BIT(TCCR1A,COM1A1);
						break;
	    case B_Channel:CLR_BIT(TCCR1A,COM1B0);
	                   SET_BIT(TCCR1A,COM1B1);
	                   break;
	   case C_Channel:CLR_BIT(TCCR1A,COM1C0);
	                  SET_BIT(TCCR1A,COM1C1);
	                  break;
	   }
        break;
case Inverting_set_oc0_oncompare_clr_on_bottom:
	switch(channel_t)
	   {
	     case disconnected_channel:break;
	      case A_Channel:SET_BIT(TCCR1A,COM1A0);
	                     SET_BIT(TCCR1A,COM1A1);
	                     break;
	      case B_Channel:SET_BIT(TCCR1A,COM1B0);
	  				     SET_BIT(TCCR1A,COM1B1);
	  			         break;
	      case C_Channel:SET_BIT(TCCR1A,COM1C0);
	  				     SET_BIT(TCCR1A,COM1C1);
	  				     break;
	   }

	break;
}

#elif oc_1==phasepwm_1

switch (oc_mode)
{
case disconnected:CLR_BIT(TCCR1A,COM1A0);
                  CLR_BIT(TCCR1A,COM1A1);

                  CLR_BIT(TCCR1A,COM1B0);
                  CLR_BIT(TCCR1A,COM1B1);

                  CLR_BIT(TCCR1A,COM1C0);
                  CLR_BIT(TCCR1A,COM1C1);
                  break;

case reserved:break;
case Non_inverting_clr_oc0_oncompare_up_set_oncompare_down:
								switch(channel_t)
	                        {
								case disconnected_channel:break;
	                          case A_Channel:CLR_BIT(TCCR1A,COM1A0);
							                 SET_BIT(TCCR1A,COM1A1);
							                 break;
	                          case B_Channel:CLR_BIT(TCCR1A,COM1B0);
	                          				 SET_BIT(TCCR1A,COM1B1);
	                          				 break;
	                          case C_Channel:CLR_BIT(TCCR1A,COM1C0);
	                          				 SET_BIT(TCCR1A,COM1C1);
	                          				 break;
	                         }
							break;
case Inverting_set_oc0_oncompare_up_clr_oncompare_down:

	switch(channel_t)
	                     {
	                       case disconnected_channel:break;
	                       case A_Channel:SET_BIT(TCCR1A,COM1A0);
	                                      SET_BIT(TCCR1A,COM1A1);
	                                      break;
	                       case B_Channel:SET_BIT(TCCR1A,COM1B0);
	  				                      SET_BIT(TCCR1A,COM1B1);
	  			                       	  break;
	                       case C_Channel:SET_BIT(TCCR1A,COM1C0);
	  				                      SET_BIT(TCCR1A,COM1C1);
	  				                       break;
	                      }

							break;

}

#endif
	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void Timer1_InputCaptureEdge(Edge_type edge)
{
	if(edge==Rising)
		SET_BIT(TCCR1B,ICES1);


	else if(edge==Falling)
		CLR_BIT(TCCR1B,ICES1);

}

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}
void Timer1_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}

void Timer1_OCC_InterruptEnable(void)
{
	SET_BIT(ETIMSK,OCIE1C);
}
void Timer1_OCC_InterruptDisable(void)
{
	CLR_BIT(ETIMSK,OCIE1C);
}


uint16  TMR1_uint16_GetICUValue(void)
{
	uint16 ret_val;
		ret_val=ICR1L|(ICR1H<<8);
		return ret_val;
}

uint16  TMR1_uint16_GetTimerValue(void)
{

	uint16 ret_val;
	ret_val=TCNT1L|(TCNT1H<<8);
	return ret_val;
}


void  TMR1_void_SetTimerValue(uint16 tmr_val)
{
TCNT1L=(uint8)tmr_val;
TCNT1H=(uint8)(tmr_val>>8);
}

void  TMR1_void_Set_OCR_TimerValue(uint16 oc_val,OC1_ch_type ch)
{
	switch(ch){
	case disconnected_channel:break;
	case A_Channel:OCR1AL=(uint8)oc_val;
	               OCR1AH=(uint8)(oc_val>>8);
	               break;
	case B_Channel:OCR1BL=(uint8)oc_val;
		           OCR1BH=(uint8)(oc_val>>8);
		           break;
	case C_Channel:OCR1CL=(uint8)oc_val;
		           OCR1CH=(uint8)(oc_val>>8);
		           break;
	}

}
