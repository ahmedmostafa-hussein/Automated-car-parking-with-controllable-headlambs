/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_



#include "std_types.h"

typedef enum
{
	PORTA_ID = 0,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID,
	PORTE_ID,
	PORTF_ID,
	PORTG_ID//NAAKHOD BALNA EN PORTG FROM  0 TO 4
}port_no_type;

typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}bit_no_type;

typedef enum
{
	INPUT = 0,
	OUTPUT
}direction_type;

typedef enum
{
	LOW = 0,
	HIGH
}value_type;

typedef enum
{
	NIPPLEL = 0,
	NIPPLEH
}NIPPLE_H_OR_L_type;

void DIO_void_Set_Pin_Dirction(port_no_type port_no, bit_no_type bit_no, direction_type direction);
void DIO_void_Set_Pin_Value(port_no_type port_no, bit_no_type bit_no, value_type value);
value_type DIO_value_type_Get_Pin_Value(port_no_type port_no, bit_no_type bit_no);

void DIO_void_Set_Port_Dirction(port_no_type port_no, uint8 direction);
void DIO_void_Set_Port_Value(port_no_type port_no, uint8 value);
void DIO_void_Set_Port_ValueNIPPLE_H_OR_L(port_no_type port_no, uint8 value,NIPPLE_H_OR_L_type nipple);
uint8 DIO_uint8_Get_Port_Value(port_no_type port_no);


#endif /* MCAL_DIO_DIO_H_ */
