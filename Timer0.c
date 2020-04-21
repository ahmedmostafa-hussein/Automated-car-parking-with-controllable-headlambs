#include"Timer0.h"
void Timer0_Init(timer0_mode_type mode,prescaler0_type scaler,OC0_mode_type oc_mode)
{
	switch (mode)
				{
					case Normal_mode:
						CLR_BIT(TCCR0,WGM00);
						CLR_BIT(TCCR0,WGM01);

					break;
					case Phasecorrect_mode:
						SET_BIT(TCCR0,WGM00);
						CLR_BIT(TCCR0,WGM01);
					break;
					case CTC_mode:
						CLR_BIT(TCCR0,WGM00);
						SET_BIT(TCCR0,WGM01);

					break;
					case FastPWM_mode:
						SET_BIT(TCCR0,WGM00);
						SET_BIT(TCCR0,WGM01);
					break;
				}
#if  oc==normal
	switch (oc_mode)
				{
					case disconnected:
						CLR_BIT(TCCR0,COM00);
						CLR_BIT(TCCR0,COM01);
						break;
					case Toggle:
						SET_BIT(TCCR0,COM00);
						CLR_BIT(TCCR0,COM01);
						break;
					case Nin_inverting:
						CLR_BIT(TCCR0,COM00);
						SET_BIT(TCCR0,COM01);
						break;
					case Inverting:
						SET_BIT(TCCR0,COM00);
						SET_BIT(TCCR0,COM01);
						break;
					}
#elif oc==fastpwm

	switch (oc_mode)
					{
						case disconnected:
							CLR_BIT(TCCR0,COM00);
							CLR_BIT(TCCR0,COM01);
							break;
						case reserved:

							break;
						case Non_inverting_clr_oc0_oncompare_set_on_bottom:
							CLR_BIT(TCCR0,COM00);
							SET_BIT(TCCR0,COM01);
							break;
						case Inverting_set_oc0_oncompare_clr_on_bottom:
							SET_BIT(TCCR0,COM00);
							SET_BIT(TCCR0,COM01);
							break;
						}

#elif oc==phasepwm

	switch (oc_mode)
						{
							case disconnected:
								CLR_BIT(TCCR0,COM00);
								CLR_BIT(TCCR0,COM01);
								break;
							case reserved:

								break;
							case Non_inverting_clr_oc0_oncompare_up_set_oncompare_down:
								CLR_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							case Inverting_set_oc0_oncompare_up_clr_oncompare_down:
								SET_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							}

#endif
	//MASK FOR SCALLER THE FIRST 3 BITS
	TCCR0&=0XF8;
	//PUT THE SCALLER
	TCCR0|=scaler;

}

void Timer0_OVInterrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void Timer0_OVInterrupt_Disable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}
void Timer0_OCInterrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void Timer0_OCInterrupt_Disable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}

void Timer0_OCI_Set_Value(uint8 oc_value)
{
	OCR0= oc_value;
}
void Timer0_TCNT_Set_Value(uint8 TCNT_value)
{
	TCNT0= TCNT_value;
}
uint8 Timer0_Get_Value(void)
{
	return TCNT0;
}
