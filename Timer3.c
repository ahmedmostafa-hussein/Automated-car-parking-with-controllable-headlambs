#include"Timer3.h"
void Timer3_Init(timer3_mode_type timer_mode,prescaler3_type scaler,OC3_mode_type oc3_mode,OC3_ch_type channel_t)
{
switch (timer_mode)
 {

case timer3_Normal_mode:                          CLR_BIT(TCCR3A,WGM30);
						                          CLR_BIT(TCCR3A,WGM31);
						                          CLR_BIT(TCCR3B,WGM32);
						                          CLR_BIT(TCCR3B,WGM33);
                                                  break;
case timer3_PWM_Phase_Correct_8bit:               SET_BIT(TCCR3A,WGM30);
							                      CLR_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_PWM_Phase_Correct_9bit:               CLR_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_PWM_Phase_Correct_10bit:              SET_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_CTC_mode_ocr_top:                     CLR_BIT(TCCR3A,WGM30);
							                      CLR_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_Fast_PWM_8_bit:                       SET_BIT(TCCR3A,WGM30);
							                      CLR_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_Fast_PWM_9_bit:                       CLR_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_Fast_PWM_10_bit:                      SET_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      CLR_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_PWM_Phase_and_Freq_Correct_icr_top:   CLR_BIT(TCCR3A,WGM30);
							                      CLR_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_PWM_Phase_and_Freq_Correct_ocr_top:   SET_BIT(TCCR3A,WGM30);
							                      CLR_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_PWM_Phase_Correct_icr_top:            CLR_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_PWM_Phase_Correct_ocr_top:            SET_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      CLR_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_CTC_mode_icr_top:                     CLR_BIT(TCCR3A,WGM30);
							                      CLR_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_Fast_PWM_icr_top:                     CLR_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
case timer3_Fast_PWM_ocr_top:                     SET_BIT(TCCR3A,WGM30);
							                      SET_BIT(TCCR3A,WGM31);
							                      SET_BIT(TCCR3B,WGM32);
							                      SET_BIT(TCCR3B,WGM33);
	                                              break;
}


#if  oc_3==normal_3
switch (oc3_mode)
{
case disconnected_3:
						CLR_BIT(TCCR3A,COM3A0);
						CLR_BIT(TCCR3A,COM3A1);

						CLR_BIT(TCCR3A,COM3B0);
						CLR_BIT(TCCR3A,COM3B1);

						CLR_BIT(TCCR3A,COM3C0);
						CLR_BIT(TCCR3A,COM3C1);
						break;
case Toggle_3:switch(channel_t)
                  {  case disconnected_channel_3:break;
                      case A_Channel_3:SET_BIT(TCCR3A,COM3A0);
						             CLR_BIT(TCCR3A,COM3A1);
						             break;
                      case B_Channel_3:SET_BIT(TCCR3A,COM3B0);
                      				 CLR_BIT(TCCR3A,COM3B1);
                      		         break;
                      case C_Channel_3:SET_BIT(TCCR3A,COM3C0);
                      			     CLR_BIT(TCCR3A,COM3C1);
                      				 break;
                    }
						break;
case Non_inverting_3:switch(channel_t)
                        {
                         case disconnected_channel_3:break;
                          case A_Channel_3:CLR_BIT(TCCR3A,COM3A0);
						                 SET_BIT(TCCR3A,COM3A1);
						                 break;
                          case B_Channel_3:CLR_BIT(TCCR3A,COM3B0);
                          				 SET_BIT(TCCR3A,COM3B1);
                          				 break;
                          case C_Channel_3:CLR_BIT(TCCR3A,COM3C0);
                          				 SET_BIT(TCCR3A,COM3C1);
                          				 break;
                         }
						break;
case Inverting_3:switch(channel_t)
                     {
                       case disconnected_channel_3:break;
                       case A_Channel_3:SET_BIT(TCCR3A,COM3A0);
                                      SET_BIT(TCCR3A,COM3A1);
                                      break;
                       case B_Channel_3:SET_BIT(TCCR3A,COM3B0);
  				                      SET_BIT(TCCR3A,COM3B1);
  			                       	  break;
                       case C_Channel_3:SET_BIT(TCCR3A,COM3C0);
  				                      SET_BIT(TCCR3A,COM3C1);
  				                       break;
                      }

						break;
}
#elif oc_3==fastpwm_3

switch (oc3_mode)
{
case disconnected_3:CLR_BIT(TCCR3A,COM3A0);
                    CLR_BIT(TCCR3A,COM3A1);

                    CLR_BIT(TCCR3A,COM3B0);
                    CLR_BIT(TCCR3A,COM3B1);

                    CLR_BIT(TCCR3A,COM3C0);
                    CLR_BIT(TCCR3A,COM3C1);
				    break;
case toggle_3:break;
case Non_inverting_clr_oc0_oncompare_set_on_bottom_3:
	switch(channel_t)
	   {
	case disconnected_channel_3:break;
	     case A_Channel_3:CLR_BIT(TCCR3A,COM3A0);
					    SET_BIT(TCCR3A,COM3A1);
						break;
	    case B_Channel_3:CLR_BIT(TCCR3A,COM3B0);
	                   SET_BIT(TCCR3A,COM3B1);
	                   break;
	   case C_Channel_3:CLR_BIT(TCCR3A,COM3C0);
	                    SET_BIT(TCCR3A,COM3C1);
	                   break;
	   }
        break;
case Inverting_set_oc0_oncompare_clr_on_bottom_3:
	switch(channel_t)
	   {
	case disconnected_channel_3:break;
	      case A_Channel_3:SET_BIT(TCCR3A,COM3A0);
	                     SET_BIT(TCCR3A,COM3A1);
	                     break;
	      case B_Channel_3:SET_BIT(TCCR3A,COM3B0);
	  				     SET_BIT(TCCR3A,COM3B1);
	  			         break;
	      case C_Channel_3:SET_BIT(TCCR3A,COM3C0);
	  				     SET_BIT(TCCR3A,COM3C1);
	  				     break;
	   }

	break;
}

#elif oc_3==phasepwm_3

switch (oc_mode)
{
case disconnected_3:CLR_BIT(TCCR3A,COM3A0);
                    CLR_BIT(TCCR3A,COM3A1);

                    CLR_BIT(TCCR3A,COM3B0);
                    CLR_BIT(TCCR3A,COM3B1);

                    CLR_BIT(TCCR3A,COM3C0);
                    CLR_BIT(TCCR3A,COM3C1);
                    break;

case reserved_3:break;
case Non_inverting_clr_oc0_oncompare_up_set_oncompare_down_3:
								switch(channel_t)
	                        {
								case disconnected_channel_3:break;
	                          case A_Channel_3:CLR_BIT(TCCR3A,COM3A0);
							                 SET_BIT(TCCR3A,COM3A1);
							                 break;
	                          case B_Channel_3:CLR_BIT(TCCR3A,COM3B0);
	                          				 SET_BIT(TCCR3A,COM3B1);
	                          				 break;
	                          case C_Channel_3:CLR_BIT(TCCR3A,COM3C0);
	                          				 SET_BIT(TCCR3A,COM3C1);
	                          				 break;
	                         }
							break;
case Inverting_set_oc0_oncompare_up_clr_oncompare_down_3:

	switch(channel_t)
	                     {
	                        case disconnected_channel_3:break;
	                       case A_Channel_3:SET_BIT(TCCR3A,COM3A0);
	                                      SET_BIT(TCCR3A,COM3A1);
	                                      break;
	                       case B_Channel_3:SET_BIT(TCCR3A,COM3B0);
	  				                      SET_BIT(TCCR3A,COM3B1);
	  			                       	  break;
	                       case C_Channel_3:SET_BIT(TCCR3A,COM3C0);
	  				                      SET_BIT(TCCR3A,COM3C1);
	  				                       break;
	                      }

							break;

}

#endif
	TCCR3B&=0XF8;
	TCCR3B|=scaler;

}

void Timer3_InputCaptureEdge(Edge3_type edge)
{
	if(edge==Rising_3)
		SET_BIT(TCCR3B,ICES3);


	else if(edge==Falling_3)
		CLR_BIT(TCCR3B,ICES3);

}

void Timer3_ICU_InterruptEnable(void)
{
	SET_BIT(ETIMSK,TICIE3);
}
void Timer3_ICU_InterruptDisable(void)
{
	CLR_BIT(ETIMSK,TICIE3);
}
void Timer3_OV_InterruptEnable(void)
{
	SET_BIT(ETIMSK,TOIE3);
}
void Timer3_OV_InterruptDisable(void)
{
	CLR_BIT(ETIMSK,TOIE3);
}
void Timer3_OCA_InterruptEnable(void)
{
	SET_BIT(ETIMSK,OCIE3A);
}
void Timer3_OCA_InterruptDisable(void)
{
	CLR_BIT(ETIMSK,OCIE3A);
}
void Timer3_OCB_InterruptEnable(void)
{
	SET_BIT(ETIMSK,OCIE3B);
}
void Timer3_OCB_InterruptDisable(void)
{
	CLR_BIT(ETIMSK,OCIE3B);
}

void Timer3_OCC_InterruptEnable(void)
{
	SET_BIT(ETIMSK,OCIE3C);
}
void Timer3_OCC_InterruptDisable(void)
{
	CLR_BIT(ETIMSK,OCIE3C);
}


uint16  TMR3_uint16_GetICUValue(void)
{
	uint16 ret_val;
		ret_val=ICR3L|(ICR3H<<8);
		return ret_val;
}

uint16  TMR3_uint16_GetTimerValue(void)
{

	uint16 ret_val;
	ret_val=TCNT3L|(TCNT3H<<8);
	return ret_val;
}


void  TMR3_void_SetTimerValue(uint16 tmr_val)
{
TCNT3L=(uint8)tmr_val;
TCNT3H=(uint8)(tmr_val>>8);
}

void  TMR3_void_Set_OCR_TimerValue(uint16 oc_val,OC3_ch_type ch)
{


	switch(ch){
	case disconnected_channel_3:break;
	case A_Channel_3:OCR3AL=(uint8)oc_val;
	                OCR3AH=(uint8)(oc_val>>8);
	                 break;
	case B_Channel_3:OCR3BL=(uint8)oc_val;
                   OCR3BH=(uint8)(oc_val>>8);
		           break;
	case C_Channel_3:OCR3CL=(uint8)oc_val;
                     OCR3CH=(uint8)(oc_val>>8);
		             break;
	}

}
