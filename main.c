#include"APP_SERV.h"
#include"../HAL/MAGNET_DOOR/MAGNET_DOOR.h"
#include"../MCAL/UARTT/Uart.h"
volatile uint8 park_flag=0,un_park_flag=1,check=0,chec=1;
volatile uint8 read_park_button=1,read_un_park_button=1;
void func_blue(void);
int main(void)
{
project_init();

while(1)
{

	LCD_vidGotoxy(0,0);
	LCD_vidPrintInTwoLines((uint8*)"Enter a TO PARK or b TO !PARK");
	_delay_ms(1000);
	LCD_vidSendCommand(1);
	func_blue();
	while(read_park_button&&read_un_park_button)
	{
		read_park_button=DIO_value_type_Get_Pin_Value(auto_park_port ,auto_park_pin);
		read_un_park_button=DIO_value_type_Get_Pin_Value(auto_park_port ,no_park_pin);
	}

	if((read_park_button==0)&&(un_park_flag==1)&&(park_flag==0)&&(read_un_park_button==1))
	{
	LCD_vidSendCommand(1);
	LCD_vidGotoxy(0,0);
	LCD_vidWriteString((uint8*)"AUTOPARKING");
	_delay_ms(1000);
	LCD_vidGotoxy(0,0);
	LCD_vidWriteString((uint8*)"CHECK DOOR");
if(Check_Door_Is_Closed())
{
	LCD_vidGotoxy(0,0);
	    LCD_vidWriteString((uint8*)"DOOR IS OPEND");
	    _delay_ms(1000);
	    LCD_vidSendCommand(1);

				while(Check_Door_Is_Closed());

}
	LCD_vidGotoxy(0,0);
			LCD_vidWriteString((uint8*)"DOOR IS CLOSED");
			park_flag=1;
		    un_park_flag=0;
		    LCD_vidSendCommand(1);
			CAR_Width_Check();
			while(check==0)
			{
			check=CAR_Length_Check();
		     }
			CAR_Length_Check2();
			CAR_Length_Check3();
		    start_parking();
		    LCD_vidPrintInTwoLines((uint8*)"CONGRATULAAAAATION PARK DOONE");


}
else  if((read_un_park_button==0)&&(park_flag==1)&&(un_park_flag==0))
		{
		if(Check_Door_Is_Closed())
		{
			LCD_vidGotoxy(0,0);
			    LCD_vidWriteString((uint8*)"DOOR IS OPEND");
			    _delay_ms(1000);
			    LCD_vidSendCommand(1);

						while(Check_Door_Is_Closed());
		}
	    	LCD_vidGotoxy(0,0);
	        LCD_vidWriteString((uint8*)"UNPARKING");
	        _delay_ms(1000);
			LCD_vidGotoxy(0,0);
			LCD_vidWriteString((uint8*)"CHECK DOOR");
				un_park_flag=1;
				park_flag=0;
				LCD_vidGotoxy(0,0);
				LCD_vidWriteString((uint8*)"DOOR IS CLOSED");
				unparking();


}

else if((read_park_button==0)&&(un_park_flag==0)&&(park_flag==1))
	{
		LCD_vidSendCommand(1);
		LCD_vidPrintInTwoLines((uint8*)"YOU ARE ALREADY PARKING ");
		  _delay_ms(1000);
		        LCD_vidSendCommand(1);
	}


    else  if((read_un_park_button==0)&&(park_flag==0)&&(un_park_flag==1))
    {
    	LCD_vidSendCommand(1);
        LCD_vidPrintInTwoLines((uint8*)"YOU ARE ALREADY UN PARKING ");
        _delay_ms(1000);
        LCD_vidSendCommand(1);
    }
    else
    {

    }

	LCD_vidSendCommand(1);

}



}

void func_blue(void)
{
	uint8 res=0;
	USART_Init();


		res=USART_Receive();
		LCD_vidWriteCharacter(res);
		_delay_ms(2000);
		if(res=='a')
		{
			read_park_button=0;

		}
		else if(res=='b')
		{
		read_un_park_button=0;

		}


}
