#include"ULTRASONIC.h"
volatile uint8 f=0,c=0;
volatile uint16 t1=0,t2=0;

void Ultrasonic_init(void)
{
	DIO_void_Set_Pin_Dirction(trig_port,trig0,OUTPUT);
	DIO_void_Set_Pin_Dirction(trig_port,trig1,OUTPUT);
	DIO_void_Set_Pin_Dirction(trig_port,trig2,OUTPUT);
	DIO_void_Set_Pin_Dirction(trig_port,trig3,OUTPUT);
	DIO_void_Set_Pin_Dirction(trig_port,trig4,OUTPUT);
	//TRY TO PUT ICU PIN INPUT
	Timer1_Init(timer1_Normal_mode,timer_scale_8,disconnected_1,disconnected_channel);
	Timer1_OV_InterruptEnable();
}
uint32 Ultrasonic_front_Get_Distance(void)
{
	uint32 time=0,distance=0;
		c = 0;
		TCNT1 = 0;
		f = 0;

		DIO_void_Set_Pin_Value(PORTA_ID,trig0,HIGH);
		_delay_us(10);
		DIO_void_Set_Pin_Value(PORTA_ID,trig0,LOW);

		 Timer1_InputCaptureEdge(Rising);
         Timer1_ICU_InterruptEnable();
		 while(f<2);
		 time = (t2-t1);
		 distance = time /58;
		 Timer1_ICU_InterruptDisable();


		 return distance;
}

uint32 Ultrasonic_right_front_Get_Distance(void)
{
	uint32 time=0,distance=0;
			c = 0;
			TCNT1 = 0;
			f = 0;

			DIO_void_Set_Pin_Value(PORTA_ID,trig1,HIGH);
			_delay_us(10);
			DIO_void_Set_Pin_Value(PORTA_ID,trig1,LOW);

			 Timer1_InputCaptureEdge(Rising);
	         Timer1_ICU_InterruptEnable();
			 while(f<2);
			 time = (t2-t1);
			 distance = time /58;
			 Timer1_ICU_InterruptDisable();


			 return distance;
}
uint32 Ultrasonic_right_back_Get_Distance(void)
{
	uint32 time=0,distance=0;
			c = 0;
			TCNT1 = 0;
			f = 0;

			DIO_void_Set_Pin_Value(PORTA_ID,trig2,HIGH);
			_delay_us(10);
			DIO_void_Set_Pin_Value(PORTA_ID,trig2,LOW);

			 Timer1_InputCaptureEdge(Rising);
	         Timer1_ICU_InterruptEnable();
			 while(f<2);
			 time = (t2-t1);
			 distance = time /58;
			 Timer1_ICU_InterruptDisable();


			 return distance;
}
uint32 Ultrasonic_back_Get_Distance(void)
{
	uint32 time=0,distance=0;
			c = 0;
			TCNT1 = 0;
			f = 0;

			DIO_void_Set_Pin_Value(PORTA_ID,trig3,HIGH);
			_delay_us(10);
			DIO_void_Set_Pin_Value(PORTA_ID,trig3,LOW);

			 Timer1_InputCaptureEdge(Rising);
	         Timer1_ICU_InterruptEnable();
			 while(f<2);
			 time = (t2-t1);
			 distance = time /58;
			 Timer1_ICU_InterruptDisable();


			 return distance;
}
uint32 Ultrasonic_back2_Get_Distance(void)
{
	uint32 time=0,distance=0;
				c = 0;
				TCNT1 = 0;
				f = 0;

				DIO_void_Set_Pin_Value(PORTA_ID,trig4,HIGH);
				_delay_us(10);
				DIO_void_Set_Pin_Value(PORTA_ID,trig4,LOW);

				 Timer1_InputCaptureEdge(Rising);
		         Timer1_ICU_InterruptEnable();
				 while(f<2);
				 time = (t2-t1);
				 distance = time /58;
				 Timer1_ICU_InterruptDisable();


				 return distance;
}
ISR(TIMER1_CAPT_vect)
{
if(f==0)
{
	t1=ICR1;
	f=1;

Timer1_InputCaptureEdge(Falling);
}

else if(f==1)
{
	t2=ICR1;
	f=2;

}
}


ISR(TIMER1_OVF_vect)
{
		c++;
}

