/*
 * Uartc.c
 *
 * Created: 3/14/2020 8:52:44 PM
 *  Author: DELL_PC
 */ 
#include "Uart.h"



uint8 USART_Receive( void )
{
	uint8 res;
	
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC)) );
	
	res=UDR0;
	//clear RXC flag
	SET_BIT(UCSR0A,RXC);
	
	/* Get and return received data from buffer */
	return res;
}



void USART_Transmit( uint8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}


void USART_Init( void)
{

	//Baudrate 9600
	UBRR0L=51;
	UBRR0H=0;
	
	//Select Asynchronous mode 
	CLR_BIT(UCSR0C,UMSEL0);
	
	//Enable, no parity
	CLR_BIT(UCSR0C,UPM01);
	CLR_BIT(UCSR0C,UPM00);
	
	//1- stop bit
	CLR_BIT(UCSR0C,USBS0);
	
	//8 bit data
	SET_BIT(UCSR0C,UCSZ00);
	SET_BIT(UCSR0C,UCSZ01);
	CLR_BIT(UCSR0B,UCSZ02);
	
	//Enable Rx & Tx
	SET_BIT(UCSR0B,RXEN0);
	SET_BIT(UCSR0B,TXEN0);
}






void USART_SendString(uint8 *str)
{
	uint8 i=0;
	
	while(str[i]!=0)
	{
		USART_Transmit(str[i]);
		i++;
	}
}
