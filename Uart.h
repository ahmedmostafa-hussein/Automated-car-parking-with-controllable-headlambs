/*
 * Uart.h
 *
 * Created: 3/14/2020 8:53:23 PM
 *  Author: DELL_PC
 */ 


#ifndef UART_H_
#define UART_H_

#include "../LIB/std_types.h"
#include "../LIB/utils.h"
#include "../LIB/memmap128.h"



uint8 USART_Receive( void );
void USART_Transmit( uint8 data );
void USART_Init( void);
void USART_SendString(uint8 *str);



#endif /* UART_H_ */
