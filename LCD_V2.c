#include"LCD_V2.h"
void LCD_vidDirections(void)
{
//SET LCD_PORT AS OUTPUT FOR DATA OF LCD
DIO_void_Set_Port_Dirction(LCD_PORT,0XFF);

//SET  AS O/P FOR RS AT LCD
DIO_void_Set_Pin_Dirction(LCD_CONTROL_PORT,RS,OUTPUT);

//SET  AS O/P FOR R/W AT LCD
DIO_void_Set_Pin_Dirction(LCD_CONTROL_PORT,RW,OUTPUT);

//SET AS O/P FOR E AT LCD
DIO_void_Set_Pin_Dirction(LCD_CONTROL_PORT,E,OUTPUT);
}
//..................................................................................

void LCD_vidDirections4(void)
{
//SET PORTD 4,5,6,7 AS OUTPUT FOR DATA OF LCD
DIO_void_Set_Pin_Dirction( LCD_PORT, Fourbit_4,OUTPUT);
DIO_void_Set_Pin_Dirction( LCD_PORT, Fourbit_5,OUTPUT);
DIO_void_Set_Pin_Dirction( LCD_PORT, Fourbit_6,OUTPUT);
DIO_void_Set_Pin_Dirction( LCD_PORT, Fourbit_7,OUTPUT);
//SET PIN 0 AS O/P FOR RS AT LCD
DIO_void_Set_Pin_Dirction(LCD_CONTROL_PORT,RS,OUTPUT);
//SET PIN 1 AS O/P FOR R/W AT LCD
DIO_void_Set_Pin_Dirction(LCD_CONTROL_PORT,RW,OUTPUT);

//SET PIN 2 AS O/P FOR E AT LCD
DIO_void_Set_Pin_Dirction(LCD_CONTROL_PORT,E,OUTPUT);
}
//..............................................................
void LCD_vidInit(void)
{
	//wait for a time
   _delay_ms(50);
   //function  set
   LCD_vidSendCommand(0b00111000);
   //wait for a time
   _delay_ms(20);
   //display on off
   LCD_vidSendCommand(0b00001100);
   //wait for a time
    _delay_ms(20);
   //display clear
   LCD_vidSendCommand(0b00000001);
   //wait for a time
    _delay_ms(20);
    //entry mode set
    LCD_vidSendCommand(0b00000110);
    //wait for a time
     _delay_ms(20);
}
//.........................................................................................
void LCD_vidSendCommand(uint8 u8CommandCpy)
{
	//put RS TO LOW TO WRITE OPERATION
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,RS,LOW);
	//PUT R/W TO LOW TO WRITE OPERATION
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,RW,LOW);
	//PUT E TO HIGH TO ENABLE
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,E,HIGH);

	DIO_void_Set_Port_Value(LCD_PORT,u8CommandCpy);

	//PUT E TO LOW TO COMPLETE SEND THE COMMAND
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,E,LOW);
	//wait tc time
	_delay_ms(1);
	//put Eto high
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,E,HIGH);
	//wait to let lcd excute the command
	_delay_ms(3);
}
//....................................................................
void LCD_vidWriteCharacter(uint8 u8DataCpy)
{
	//put RS TO LOW TO WRITE OPERATION
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,RS,HIGH);
    //PUT R/W TO LOW TO WRITE OPERATION
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,RW,LOW);
	//PUT E TO HIGH TO ENABLE
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,E,HIGH);

	DIO_void_Set_Port_Value(LCD_PORT,u8DataCpy);

	//PUT E TO LOW TO COMPLETE SEND THE COMMAND
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,E,LOW);
	//wait tc time
	_delay_ms(1);
	//put E to high
	DIO_void_Set_Pin_Value(LCD_CONTROL_PORT,E,HIGH);
	//wait to let lcd excute the command
	_delay_ms(3);
}

//....................................................................

void LCD_vidSendCommand4(uint8 u8CommandCpy)
{

	LCD_vidSendCommand( ( GET_NippleH(u8CommandCpy))<<4 );
	LCD_vidSendCommand(  (GET_NippleL(u8CommandCpy))<<4 );
}
//........................................................................................
\
void LCD_vidInit4(void)
{
	 //wait for a time
	  _delay_ms(50);

	  //function  set
	  LCD_vidSendCommand(0b00100000);
	  LCD_vidSendCommand(0b00100000);
	  LCD_vidSendCommand(0b11000000);

	  //wait for a time
	  _delay_ms(50);

	  //display on off
	  LCD_vidSendCommand(0b00000000);
	  LCD_vidSendCommand(0b11100000);

	  //wait for a time
	  _delay_ms(30);

	  //display clear
	  LCD_vidSendCommand(0b00000000);
	  LCD_vidSendCommand(0b00010000);

	  //wait for a time
	  _delay_ms(30);

	  //entry mode set
	 LCD_vidSendCommand(0b00000000);
	  LCD_vidSendCommand(0b01100000);

	  //wait for a time
	  _delay_ms(30);
}

//....................................................................

void LCD_vidWriteCharacter4(uint8 u8DataCpy)
{
	LCD_vidWriteCharacter((GET_NippleH(u8DataCpy))<<4);
	LCD_vidWriteCharacter((GET_NippleL(u8DataCpy))<<4);
}


void LCD_vidWriteString(uint8 *pu8StringCpy)
{
	uint8 u8_index=0;

	while(pu8StringCpy[u8_index]!='\0')

	{
		LCD_vidWriteCharacter(pu8StringCpy[u8_index]);
		u8_index++;
		_delay_ms(2);
	}
}
//...................................................................................
void LCD_vidWriteString4(uint8 *pu8StringCpy)
{
	uint8 u8_index=0;

		while(pu8StringCpy[u8_index]!='\0')

		{
			LCD_vidWriteCharacter4(pu8StringCpy[u8_index]);
			u8_index++;
			_delay_ms(1);
		}
}
//..........................................................................................
void LCD_vidWriteUnSignedInteger(uint64 number)
{
	uint8 arr[20]={};
    uint8 i=0;

    if(number==0)
    {
    	LCD_vidWriteCharacter(number+48);
    }
    else{
   while((i<20)&&(number!=0))
   {   arr[i++]=number%10;

	       number/=10;

   }

       while(i!=0){
    	LCD_vidWriteCharacter(arr[--i]+48);

       }
    }
}
//............................................................................................
void LCD_vidWriteUnSignedInteger4(uint64 number)
{
	uint8 arr[20]={};
    uint8 i=0;

    if(number==0)
    {
    	LCD_vidWriteCharacter4(number+48);
    }
    else{
   while((i<20)&&(number!=0))
   {   arr[i++]=number%10;

	       number/=10;

   }

       while(i!=0){
    	LCD_vidWriteCharacter4(arr[--i]+48);

       }
    }
}
//......................................................................................
void LCD_vidWriteSignedInteger(sint64 s64SignedNumCpy)
{
	uint64 u64UnsignedNumCpy=0;
	if(s64SignedNumCpy<(sint64)0)
	{
		u64UnsignedNumCpy=s64SignedNumCpy*(-1);
        LCD_vidWriteCharacter('-');
	}
	else
	{
		u64UnsignedNumCpy=s64SignedNumCpy;
	}

	LCD_vidWriteUnSignedInteger(u64UnsignedNumCpy);


}
//......................................................................................
void LCD_vidWriteSignedInteger4(sint64 s64SignedNumCpy)
{
	uint64 u64UnsignedNumCpy=0;
		if(s64SignedNumCpy<(sint64)0)
		{
			u64UnsignedNumCpy=s64SignedNumCpy*(-1);
	        LCD_vidWriteCharacter4('-');
		}
		else
		{
			u64UnsignedNumCpy=s64SignedNumCpy;
		}

		LCD_vidWriteUnSignedInteger4(u64UnsignedNumCpy);

}




//...............................................................................................
void LCD_vidGotoxy(uint8 u8Numx,uint8 u8Numy)
{
	switch(u8Numy)
	{
	case 0 : if((u8Numx<16)&&(u8Numx>=0))
		    LCD_vidSendCommand(0x80+u8Numx);
	        break;

	case 1:if((u8Numx<16)&&(u8Numx>=0))
	          LCD_vidSendCommand(0xc0+u8Numx);
                break;
	}
}
//...........................................................................................
void LCD_vidGotoxy4(uint8 u8Numx,uint8 u8Numy)
{
	switch(u8Numy)
		{
		case 0 : if((u8Numx<16)&&(u8Numx>=0))
			LCD_vidSendCommand4(0x80+u8Numx);
		        break;

		case 1:if((u8Numx<16)&&(u8Numx>=0))
			LCD_vidSendCommand4(0xc0+u8Numx);
	                break;
		}
}
//.........................................................................................
void LCD_vidShiftDisplayCursor(uint8 u8Direction,uint8 u8ShiftNumber,uint8 u8DisplayOrcursor)

{   uint8 u8CommandValue=0x10;
	switch(u8Direction)
	{
	case Right:SET_BIT(u8CommandValue,2);
	            break;

	case Left:CLR_BIT(u8CommandValue,2);
	          break;

	}

	switch(u8DisplayOrcursor)
	{
	case Display:SET_BIT(u8CommandValue,3);
	               break;
	case Cursor:CLR_BIT(u8CommandValue,3);
                 break;
	}

	while(u8ShiftNumber!=0)
	{
		 LCD_vidSendCommand(u8CommandValue);
		 u8ShiftNumber--;
		 _delay_ms(10);
	}

}

//.....................................................................................
void LCD_vidShiftDisplayCursor4(uint8 u8Direction,uint8 u8ShiftNumber,uint8 u8DisplayOrcursor)
{
	 uint8 u8CommandValue=0x10;
		switch( u8Direction)
		{
		case Right:SET_BIT(u8CommandValue,2);
		            break;

		case Left:CLR_BIT(u8CommandValue,2);
		          break;

		}

		switch( u8DisplayOrcursor)
		{
		case Display:SET_BIT(u8CommandValue,3);
		               break;
		case Cursor:CLR_BIT(u8CommandValue,3);
	                 break;
		}
		while(u8ShiftNumber!=0)
		{
			 LCD_vidSendCommand4(u8CommandValue);
			 u8ShiftNumber--;
		}

}

//.......................................................................................
void LCD_vidPrint(uint8 str[])
{
	uint8 i=0;
	while(str[i]!=0)
	{
		LCD_vidWriteCharacter(str[i++]);
	}
}
//.........................................................................................
void LCD_vidPrintInTwoLines(uint8 str[])
{

	uint8 i=0;
		while(str[i]!=0)
		{
			if(i<=15){

			LCD_vidGotoxy(i,0);
			LCD_vidWriteCharacter(str[i++]);
		}
			else if(i<=31)
			{

				LCD_vidGotoxy(i-16,1);
				LCD_vidWriteCharacter(str[i++]);

			}
			else if(i>31)
				{
					LCD_vidGotoxy(i-32,0);
					LCD_vidWriteCharacter(str[i++]);
				}
			else
			{

				LCD_vidGotoxy(i-64,1);
				LCD_vidWriteCharacter(str[i++]);

				}

}

}
//.........................................................................................
void LCD_vidPrint4(uint8 str[])
{
	uint8 i=0;
	while(str[i]!=0)
	{
		LCD_vidWriteCharacter4(str[i++]);
	}
}

//......................................................................................
void LCD_vidPrintInTwoLines4(uint8 str[])
{

	uint8 i=0;
		while(str[i]!=0)
		{
			if(i<=15)
			{

			LCD_vidGotoxy4(i,0);
			LCD_vidWriteCharacter4(str[i++]);
		}
			else
			{
				LCD_vidGotoxy4(i-16,1);
				LCD_vidWriteCharacter4(str[i++]);


			}

		}

}

