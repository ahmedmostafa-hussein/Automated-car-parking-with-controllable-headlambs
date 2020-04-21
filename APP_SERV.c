#include"APP_SERV.h"
//#include"Timer3_config.h"
volatile uint16 count_right_front=0,count_back=0,count_front=0,count_right_back=0,count_right_back2=0;
volatile uint32 ultra_right_front=0,ultra_back=0,ultra_back2=0,ultra_front=0, ultra_right_back=0;
volatile uint8 flag_check=0;
volatile uint64 length_rf,length_rb;
volatile uint64 time_rf,time_rb;
volatile uint64 t_rf,t_rb,c_rf,c_rb;
void project_init(void)
{
	 DIO_void_Set_Pin_Dirction(PORTE_ID,PIN0,INPUT);
	 DIO_void_Set_Pin_Dirction(PORTE_ID,PIN1,OUTPUT);

	//AUTOPARK
   DIO_void_Set_Pin_Dirction(auto_park_port,auto_park_pin,INPUT);
   DIO_void_Set_Pin_Value(auto_park_port,auto_park_pin,HIGH);
   //antipark
   DIO_void_Set_Pin_Dirction(auto_park_port,no_park_pin,INPUT);
   DIO_void_Set_Pin_Value(auto_park_port,no_park_pin,HIGH);
   //LCD INIT
   LCD_vidDirections();
   LCD_vidInit();
   LCD_LIGHT();
   //...........................
   Ultrasonic_init();
   //...........................
   //CAR CONTROL
   DIO_void_Set_Pin_Dirction(car_control,forward,OUTPUT);
   DIO_void_Set_Pin_Dirction(car_control,backword,OUTPUT);
   DIO_void_Set_Pin_Dirction(car_control,left_wheel,OUTPUT);
   DIO_void_Set_Pin_Dirction(car_control,right_wheel,OUTPUT);
   DIO_void_Set_Pin_Dirction(car_control,stop,OUTPUT);

   DIO_void_Set_Pin_Value(car_control,forward,HIGH);
   DIO_void_Set_Pin_Value(car_control,backword,HIGH);
   DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
   DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
   DIO_void_Set_Pin_Value(car_control,stop,HIGH);
   //
   sei();
   Buzzer_Init();
   //
   Mag_Door_Init();
   Timer0_OVInterrupt_Enable();
  }



void CAR_Width_Check(void)
{
	//MOVE FORWARD
    forward_move();
    LCD_vidSendCommand(1);

    	do{
    	   LCD_vidGotoxy(0,0);
    	   LCD_vidWriteString("CAR CHECK WIDTH");
    	   ultra_right_front=Ultrasonic_right_front_Get_Distance();
    	   LCD_vidGotoxy(0,1);
    	   LCD_vidWriteString("DISTANCE:");
    	   LCD_vidGotoxy(10,1);
    	   LCD_vidWriteUnSignedInteger(ultra_right_front);

    	}while(Ultrasonic_right_front_Get_Distance()<100);

}
uint64 distance_rf(void)
{
  t_rf=TCNT0;
  c_rf=count_right_front;
  time_rf=(uint64)t_rf+((uint64)c_rf*256);
  length_rf=((((uint64)time_rf*13))/1000000);
  return length_rf;
}
uint64 distance_rb(void)
{
t_rb=TCNT0;
c_rb=count_right_back;
time_rb=(uint64)t_rb+((uint64)c_rb*256);
length_rb=((((uint64)time_rb*13))/1000000);
 return length_rb;
}
uint64 distance_rb2(void)
{
t_rb=TCNT0;
c_rb=count_right_back2;
time_rb=(uint64)t_rb+((uint64)c_rb*256);
length_rb=((((uint64)time_rb*13))/1000000);
 return length_rb;
}
uint8 CAR_Length_Check(void)
{
	 uint8 ret_val=1;
	Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	CLR_BIT(TCCR3A,COM3A0);
	CLR_BIT(TCCR3A,COM3A1);
	LCD_vidSendCommand(1);
	forward_move();
	Timer0_Init(Normal_mode,timer0_scale_8,disconnected);
	TCNT0=0;
	count_right_front=0;
    do
    {
    LCD_vidGotoxy(0,0);
    LCD_vidWriteString("DISTANCE:");
    ultra_right_front=Ultrasonic_right_front_Get_Distance();
    LCD_vidGotoxy(10,0);
    LCD_vidWriteUnSignedInteger(ultra_right_front);
     //heya mashya forward
     length_rf=distance_rf();
     LCD_vidGotoxy(0,1);
     LCD_vidWriteString("LENGTH:");
     LCD_vidGotoxy(8,1);
     LCD_vidWriteUnSignedInteger((uint64)length_rf);
    if(length_rf>=165)
    {
     //STOP CAR
     DIO_void_Set_Pin_Value(car_control,forward,HIGH);
     Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
     CLR_BIT(TCCR3A,COM3A0);
     CLR_BIT(TCCR3A,COM3A1);
     Buzzer_On();
     LCD_vidGotoxy(0,1);
     LCD_vidWriteString((uint8*)"Spot found");
     _delay_ms(1000);
     Buzzer_Off();
    flag_check=1;
   }

  }while((Ultrasonic_right_front_Get_Distance()>=100)&&(length_rf<165));
 if(flag_check!=1)
   ret_val=0;
   return ret_val;
}
void CAR_Length_Check2(void)
{
LCD_vidGotoxy(0,1);
LCD_vidWriteString("distance found");

forward_move();
LCD_vidSendCommand(1);

do{

  LCD_vidGotoxy(0,1);
  LCD_vidWriteString("distance:");
  ultra_right_back=Ultrasonic_right_back_Get_Distance();
  LCD_vidGotoxy(10,1);
  LCD_vidWriteUnSignedInteger(ultra_right_back);

}while(Ultrasonic_right_back_Get_Distance()>=100);
//STOP CAR
DIO_void_Set_Pin_Value(car_control,forward,HIGH);
Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
CLR_BIT(TCCR3A,COM3A0);
CLR_BIT(TCCR3A,COM3A1);
}
void CAR_Length_Check3(void)
{
	flag_check=2;
    Timer0_Init(Normal_mode,timer0_scale_8,disconnected);
	forward_move();
	TCNT0=0;
	c_rb=0;
	t_rb=0;
	length_rb=0;
	count_right_back=0;
		 do{
		    //heya mashya forward
		  length_rb=distance_rb();
		  LCD_vidGotoxy(0,0);
		  LCD_vidWriteString("length:");
		  LCD_vidGotoxy(10,0);
		  LCD_vidWriteUnSignedInteger(length_rb);
		  if(length_rb>=50)
		   {
		     //STOP CAR
		   DIO_void_Set_Pin_Value(car_control,forward,HIGH);
		   Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
		   CLR_BIT(TCCR3A,COM3A0);
		   CLR_BIT(TCCR3A,COM3A1);
		    Buzzer_On();
		   LCD_vidGotoxy(0,1);
		   LCD_vidWriteString((uint8*)"yala start park");
		   _delay_ms(1000);
		   Buzzer_Off();
		   }
           }while(length_rb<50);
}

void CAR_Length_Check4(void)
{
	flag_check=3;
    Timer0_Init(Normal_mode,timer0_scale_8,disconnected);
	forward_move();
	TCNT0=0;
	count_right_back2=0;
		 do{
		    //heya mashya forward
		  length_rb=distance_rb2();
		  LCD_vidGotoxy(0,0);
		  LCD_vidWriteString("length:");
		  LCD_vidGotoxy(10,0);
		  LCD_vidWriteUnSignedInteger(length_rb);
		  if(length_rb>=60)
		   {
		     //STOP CAR
		   DIO_void_Set_Pin_Value(car_control,forward,HIGH);
		   Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
		   CLR_BIT(TCCR3A,COM3A0);
		   CLR_BIT(TCCR3A,COM3A1);
		    Buzzer_On();
		   _delay_ms(1000);
		   Buzzer_Off();
		   }
           }while(length_rb<60);
}


void forward_move(void)
{
	//TO DISCONNECT CHANNEL C
   Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
   DIO_void_Set_Pin_Value(car_control, backword,HIGH);
   CLR_BIT(TCCR3A,COM3C0);
   CLR_BIT(TCCR3A,COM3C1);

   Timer3_Init(timer3_Fast_PWM_10_bit,timer3_scale_1024,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,A_Channel_3);
   DIO_void_Set_Pin_Dirction(car_control, forward,OUTPUT);
   TMR3_void_Set_OCR_TimerValue(100,A_Channel_3);
}

void backward_move(void)
{
	    Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    CLR_BIT(TCCR3A,COM3A0);
	    CLR_BIT(TCCR3A,COM3A1);
		Timer3_Init( timer3_Fast_PWM_10_bit,timer3_scale_1024,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,C_Channel_3);
        DIO_void_Set_Pin_Dirction(car_control,backword,OUTPUT);
		TMR3_void_Set_OCR_TimerValue(100,C_Channel_3);

}


void right_move(void)
{
	DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
	DIO_void_Set_Pin_Value(car_control,right_wheel,LOW);
	_delay_ms(1200);
	DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
}
void right_half_move(void)
{
	DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
	DIO_void_Set_Pin_Value(car_control,right_wheel,LOW);
	_delay_ms(500);
	DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
}
void right_QUARTER_move(void)
{
	DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
	DIO_void_Set_Pin_Value(car_control,right_wheel,LOW);
	_delay_ms(250);
	DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
}

void left_move(void)
{
	DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
	DIO_void_Set_Pin_Value(car_control,left_wheel,LOW);
    _delay_ms(1200);
	DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
}
void left_half_move(void)
{
	DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
	DIO_void_Set_Pin_Value(car_control,left_wheel,LOW);
    _delay_ms(500);
	DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
}
void left_QUARTER_move(void)
{
	DIO_void_Set_Pin_Value(car_control,right_wheel,HIGH);
	DIO_void_Set_Pin_Value(car_control,left_wheel,LOW);
    _delay_ms(250);
	DIO_void_Set_Pin_Value(car_control,left_wheel,HIGH);
}


void start_parking(void)
{

LCD_vidPrintInTwoLines("RIGHT WHEEL CAR MOVE BACKWORD");
right_move();
backward_move();
LCD_vidSendCommand(1);

do {
	 LCD_vidGotoxy(0,0);
	 LCD_vidWriteString("back DISTANCE");
	 ultra_back=Ultrasonic_back2_Get_Distance();
	 LCD_vidGotoxy(0,1);
	 LCD_vidWriteString("       ");
	LCD_vidGotoxy(0,1);
	 LCD_vidWriteUnSignedInteger(ultra_back);


if(ultra_back>200)
	   	{
	      	ultra_back=200;
	      }
else if(ultra_back<6)
	    {
	        	ultra_back=5;
	   }
 } while(Ultrasonic_back2_Get_Distance()>80);
	//....................................
	Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	DIO_void_Set_Pin_Value(car_control, backword,HIGH);
    //TO DISCONNECT CHANNEL C
    CLR_BIT(TCCR3A,COM3C0);
    CLR_BIT(TCCR3A,COM3C1);

 //...................................................
    left_move();
    backward_move();

    	do {
    		LCD_vidGotoxy(0,0);
    		LCD_vidWriteString("back DISTANCE");
    		LCD_vidGotoxy(0,1);
    		LCD_vidWriteString("       ");
    	    LCD_vidGotoxy(0,1);
    		ultra_back=Ultrasonic_back_Get_Distance();
    		LCD_vidWriteUnSignedInteger(ultra_back);
    	    if(ultra_back>200)
    		   	{
    		      	ultra_back=200;
    		      }
    	    else if(ultra_back<6)
    		    {
    		        	ultra_back=5;
    		   }
    	 } while(Ultrasonic_back_Get_Distance()>12);

  //stop car
 Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
 DIO_void_Set_Pin_Value(car_control, backword,HIGH);
  //TO DISCONNECT CHANNEL C
  CLR_BIT(TCCR3A,COM3C0);
  CLR_BIT(TCCR3A,COM3C1);

   //........................................
   right_move();
   forward_move();

  do{
      LCD_vidGotoxy(0,0);
       LCD_vidWriteString("front DISTANCE");
      ultra_front=Ultrasonic_front_Get_Distance();
      LCD_vidGotoxy(0,1);
      LCD_vidWriteString("       ");
      LCD_vidGotoxy(0,1);
       LCD_vidWriteUnSignedInteger(ultra_front);
       if(ultra_front>200)
      	{
           ultra_front=200;
         }
       else if(ultra_front)
         {
             	ultra_front=5;
         }
        	}while(Ultrasonic_front_Get_Distance()>10);
        //stop
	    Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    CLR_BIT(TCCR3A,COM3A0);
	    CLR_BIT(TCCR3A,COM3A1);
//..................................................................................
left_move();
backward_move();
do {
	 LCD_vidGotoxy(0,0);
	 LCD_vidWriteString("back DISTANCE");
	 ultra_back=Ultrasonic_back_Get_Distance();
	 LCD_vidGotoxy(0,1);
	 LCD_vidWriteString("       ");
	   LCD_vidGotoxy(0,1);
	  LCD_vidWriteUnSignedInteger(ultra_back);


if(ultra_back>200)
	   	{
	      	ultra_back=200;
	      }
else if(ultra_back<6)
	    {
	        	ultra_back=5;
	   }
 } while(Ultrasonic_back_Get_Distance()>10);


	    //stop back
	    Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	        	DIO_void_Set_Pin_Value(car_control, backword,HIGH);
	            //TO DISCONNECT CHANNEL C
	            CLR_BIT(TCCR3A,COM3C0);
	            CLR_BIT(TCCR3A,COM3C1);
//.........................................................
right_half_move();
forward_move();
do{
	LCD_vidGotoxy(0,0);
	LCD_vidWriteString("front DISTANCE");
	ultra_front=Ultrasonic_front_Get_Distance();
	 LCD_vidGotoxy(0,1);
     LCD_vidWriteString("       ");
	LCD_vidGotoxy(0,1);
	LCD_vidWriteUnSignedInteger(ultra_front);
	if(ultra_front>200)
	 {
	  ultra_front=200;
	}
	else if(ultra_front)
	{
	  ultra_front=5;
   }
} while(Ultrasonic_front_Get_Distance()>15);
	      Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    	    DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    	    CLR_BIT(TCCR3A,COM3A0);
	    	    CLR_BIT(TCCR3A,COM3A1);
//..................................................................................................
backward_move();
left_half_move();
do {
	LCD_vidGotoxy(0,0);
	LCD_vidWriteString("back DISTANCE");
	ultra_back=Ultrasonic_back_Get_Distance();
	LCD_vidGotoxy(0,1);
	LCD_vidWriteString("       ");
	LCD_vidGotoxy(0,1);
	LCD_vidWriteUnSignedInteger(ultra_back);


if(ultra_back>200)
	   	{
	      	ultra_back=200;
	      }
else if(ultra_back<6)
	    {
	        	ultra_back=5;
	   }

 } while(Ultrasonic_back_Get_Distance()>25);

Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	  DIO_void_Set_Pin_Value(car_control, backword,HIGH);
	   //TO DISCONNECT CHANNEL C
	    CLR_BIT(TCCR3A,COM3C0);
	     CLR_BIT(TCCR3A,COM3C1);
	     right_half_move();

//.................................zawdthaaaaa
/*
	     left_half_move();
	     forward_move();
	     do{
	     	ultra_front=Ultrasonic_front_Get_Distance();
	     	LCD_vidGotoxy(0,0);
	     	LCD_vidWriteString("front DISTANCE");
	     	LCD_vidGotoxy(0,1);
	     	LCD_vidWriteUnSignedInteger(ultra_front);
	     	if(ultra_front>200)
	     	 {
	     	  ultra_front=200;
	     	}
	     	else if(ultra_front)
	     	{
	     	  ultra_front=5;
	        }
	     } while(Ultrasonic_front_Get_Distance()>17);
	     	      Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	     	    	    DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	     	    	    CLR_BIT(TCCR3A,COM3A0);
	     	    	    CLR_BIT(TCCR3A,COM3A1);
*/
}
void unparking(void)
{
	right_move();
	backward_move();
LCD_vidSendCommand(1);
	do {


	      LCD_vidGotoxy(0,0);
	     LCD_vidWriteString("back DISTANCE");
	     ultra_back=Ultrasonic_back_Get_Distance();
	     LCD_vidGotoxy(0,1);
	     LCD_vidWriteString("   ");
	     LCD_vidGotoxy(0,1);
	     LCD_vidWriteUnSignedInteger(ultra_back);

	if(ultra_back>200)
		   	{
		      	ultra_back=200;
		      }
	else if(ultra_back<6)
		    {
		        	ultra_back=5;
		   }


	 } while(Ultrasonic_back_Get_Distance()>7);
		//....................................
		Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
		DIO_void_Set_Pin_Value(car_control, backword,HIGH);
	    //TO DISCONNECT CHANNEL C
	    CLR_BIT(TCCR3A,COM3C0);
	    CLR_BIT(TCCR3A,COM3C1);
//...............................................................
left_move();
forward_move();
LCD_vidSendCommand(1);

do{

		     LCD_vidGotoxy(0,0);
		     LCD_vidWriteString("front DISTANCE");
		     ultra_front=Ultrasonic_front_Get_Distance();
		     LCD_vidGotoxy(0,1);
		     LCD_vidWriteString("   ");
		     LCD_vidGotoxy(0,1);
		     LCD_vidWriteUnSignedInteger(ultra_front);
		if(ultra_front>200)
			   	{
			      	ultra_front=200;
			      }
		else if(ultra_front<6)
			    {
			        	ultra_front=5;
			   }




} while(Ultrasonic_front_Get_Distance()>7);
	      Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    	    DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    	    CLR_BIT(TCCR3A,COM3A0);
	    	    CLR_BIT(TCCR3A,COM3A1);
//..........................................................................................
	    	    right_move();
	    	    	backward_move();

	    	    	do {
	    	    		 LCD_vidGotoxy(0,0);
	    	    	     LCD_vidWriteString("back DISTANCE");
	    	    		 ultra_back=Ultrasonic_back_Get_Distance();
	    	    		 LCD_vidGotoxy(0,1);
	    	    		 LCD_vidWriteString("   ");
	    	    		 LCD_vidGotoxy(0,1);
	    	    		 LCD_vidWriteUnSignedInteger(ultra_back);


	    	    	if(ultra_back>200)
	    	    		   	{
	    	    		      	ultra_back=200;
	    	    		      }
	    	    	else if(ultra_back<6)
	    	    		    {
	    	    		        	ultra_back=5;
	    	    		   }

	    	    	 } while(Ultrasonic_back_Get_Distance()>7);
	    	    		//....................................
	    	    		Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    	    		DIO_void_Set_Pin_Value(car_control, backword,HIGH);
	    	    	    //TO DISCONNECT CHANNEL C
	    	    	    CLR_BIT(TCCR3A,COM3C0);
	    	    	    CLR_BIT(TCCR3A,COM3C1);
//...........................................................
	    	    	    left_move();
	    	    	    forward_move();

	    	    	    do{

	    	    	    	LCD_vidGotoxy(0,0);
	    	    	    	LCD_vidWriteString("back2 DISTANCE");

	    	    	    	ultra_back2=Ultrasonic_back2_Get_Distance();
	    	    	    	LCD_vidGotoxy(0,1);
	    	    	    	LCD_vidWriteUnSignedInteger(ultra_back2);
	    	    	    	if(ultra_back2>200)
	    	    	    	 {
	    	    	    	  ultra_back2=200;
	    	    	    	}
	    	    	    	else if(ultra_back2)
	    	    	    	{
	    	    	    	  ultra_back2=5;
	    	    	       }
	    	    	    } while(Ultrasonic_back2_Get_Distance()<80);
	    	    	    	      Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    	    	    	    	    DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    	    	    	    	    CLR_BIT(TCCR3A,COM3A0);
	    	    	    	    	    CLR_BIT(TCCR3A,COM3A1);

//..........................................................
right_QUARTER_move();
	    	    	     forward_move();
	    	    	     LCD_vidSendCommand(1);
	    	    	     CAR_Length_Check4();
	    	     Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    	   DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    	  CLR_BIT(TCCR3A,COM3A0);
	    	  CLR_BIT(TCCR3A,COM3A1);
//...............................................

	    	  left_QUARTER_move();
	    	  	    	    	     forward_move();
	    	  	    	    	     LCD_vidSendCommand(1);
	    	  	    	    	     CAR_Length_Check4();
	    	  	    	     Timer3_Init(timer3_Fast_PWM_10_bit,timer3_stop,Non_inverting_clr_oc0_oncompare_set_on_bottom_3,disconnected_channel_3);
	    	  	    	   DIO_void_Set_Pin_Value(car_control,forward,HIGH);
	    	  	    	  CLR_BIT(TCCR3A,COM3A0);
	    	  	    	  CLR_BIT(TCCR3A,COM3A1);
	    	  //...............................................
    LCD_vidSendCommand(1);
	    	  	    	  LCD_vidGotoxy(0,1);
	    	  	          LCD_vidWriteString((uint8*)"unpark is done");
}
ISR(TIMER0_OVF_vect)
{

if(flag_check==0)
{
    	count_right_front++;
}

  if(flag_check==2)
 {
     	count_right_back++;
 }
 if(flag_check==3)
 {
 	count_right_back2++;
 }


}


void LCD_LIGHT(void)
{
	DIO_void_Set_Pin_Dirction(PORTE_ID,PIN4,OUTPUT);
	DIO_void_Set_Pin_Value(PORTE_ID,PIN4,OUTPUT);
}
