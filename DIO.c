
#include "DIO.h"
#include "utils.h"
#include"memmap128.h"

void DIO_void_Set_Pin_Dirction(port_no_type port_no, bit_no_type bit_no, direction_type direction)
{
	if(direction == INPUT)
	{
		switch(port_no)
		{
		case PORTA_ID:CLR_BIT(DDRA,bit_no);break;
		case PORTB_ID:CLR_BIT(DDRB,bit_no);break;
		case PORTC_ID:CLR_BIT(DDRC,bit_no);break;
		case PORTD_ID:CLR_BIT(DDRD,bit_no);break;
		case PORTE_ID:CLR_BIT(DDRE,bit_no);break;
		case PORTF_ID:CLR_BIT(DDRF,bit_no);break;
	    case PORTG_ID:CLR_BIT(DDRG,bit_no);break;

		}
	}
	else if(direction == OUTPUT)
	{
		switch(port_no)
		{
		case PORTA_ID:SET_BIT(DDRA,bit_no);break;
		case PORTB_ID:SET_BIT(DDRB,bit_no);break;
		case PORTC_ID:SET_BIT(DDRC,bit_no);break;
		case PORTD_ID:SET_BIT(DDRD,bit_no);break;
		case PORTE_ID:SET_BIT(DDRE,bit_no);break;
		case PORTF_ID:SET_BIT(DDRF,bit_no);break;
		case PORTG_ID:SET_BIT(DDRG,bit_no);break;
		}
	}
}

void DIO_void_Set_Pin_Value(port_no_type port_no, bit_no_type bit_no, value_type value)
{
	if(value == LOW)
	{
		switch(port_no)
		{
		case PORTA_ID:CLR_BIT(PORTA,bit_no);break;
		case PORTB_ID:CLR_BIT(PORTB,bit_no);break;
		case PORTC_ID:CLR_BIT(PORTC,bit_no);break;
		case PORTD_ID:CLR_BIT(PORTD,bit_no);break;
		case PORTE_ID:CLR_BIT(PORTE,bit_no);break;
		case PORTF_ID:CLR_BIT(PORTF,bit_no);break;
		case PORTG_ID:CLR_BIT(PORTG,bit_no);break;
		}
	}
	else if(value == HIGH)
	{
		switch(port_no)
		{
		case PORTA_ID:SET_BIT(PORTA,bit_no);break;
		case PORTB_ID:SET_BIT(PORTB,bit_no);break;
		case PORTC_ID:SET_BIT(PORTC,bit_no);break;
		case PORTD_ID:SET_BIT(PORTD,bit_no);break;
		case PORTE_ID:SET_BIT(PORTE,bit_no);break;
		case PORTF_ID:SET_BIT(PORTF,bit_no);break;
		case PORTG_ID:SET_BIT(PORTG,bit_no);break;
		}
	}
}

value_type DIO_value_type_Get_Pin_Value(port_no_type port_no, bit_no_type bit_no)
{
	value_type return_value;
	switch(port_no)
	{
	case PORTA_ID:return_value = GET_BIT(PINA,bit_no);break;
	case PORTB_ID:return_value = GET_BIT(PINB,bit_no);break;
	case PORTC_ID:return_value = GET_BIT(PINC,bit_no);break;
	case PORTD_ID:return_value = GET_BIT(PIND,bit_no);break;
	case PORTE_ID:return_value = GET_BIT(PINE,bit_no);break;
	case PORTF_ID:return_value = GET_BIT(PINF,bit_no);break;
	case PORTG_ID:return_value = GET_BIT(PING,bit_no);break;
	}

	return return_value;
}

void DIO_void_Set_Port_Dirction(port_no_type port_no, uint8 direction)
{
	switch(port_no)
	{
	case PORTA_ID: DDRA = direction; break;
	case PORTB_ID: DDRB = direction; break;
	case PORTC_ID: DDRC = direction; break;
	case PORTD_ID: DDRD = direction; break;
	case PORTE_ID: DDRE = direction; break;
	case PORTF_ID: DDRF = direction; break;
	case PORTG_ID: DDRG = direction; break;
	}
}

void DIO_void_Set_Port_Value(port_no_type port_no, uint8 value)
{
	switch(port_no)
	{
	case PORTA_ID: PORTA = value; break;
	case PORTB_ID: PORTB = value; break;
	case PORTC_ID: PORTC = value; break;
	case PORTD_ID: PORTD = value; break;
	case PORTE_ID: PORTE = value; break;
	case PORTF_ID: PORTF = value; break;
	case PORTG_ID: PORTG = value; break;
	}
}

void DIO_void_Set_Port_ValueNIPPLE_H_OR_L(port_no_type port_no, uint8 value,NIPPLE_H_OR_L_type nipple)
{
	if(nipple==NIPPLEL)
	{
		switch(port_no)
			{
			case PORTA_ID: ASSIGN_NippleL(PORTA,value); break;
			case PORTB_ID: ASSIGN_NippleL(PORTB,value);break;
			case PORTC_ID: ASSIGN_NippleL(PORTC,value); break;
			case PORTD_ID: ASSIGN_NippleL(PORTD,value); break;
			case PORTE_ID: ASSIGN_NippleL(PORTE,value); break;
			case PORTF_ID: ASSIGN_NippleL(PORTF,value); break;
			case PORTG_ID: ASSIGN_NippleL(PORTG,value); break;
			}
	}
	else if(nipple==NIPPLEH)
	{
		switch(port_no)
					{
					case PORTA_ID: ASSIGN_NippleH(PORTA,value); break;
					case PORTB_ID: ASSIGN_NippleH(PORTB,value);break;
					case PORTC_ID: ASSIGN_NippleH(PORTC,value); break;
					case PORTD_ID: ASSIGN_NippleH(PORTD,value); break;
					case PORTE_ID: ASSIGN_NippleH(PORTE,value); break;
					case PORTF_ID: ASSIGN_NippleH(PORTF,value); break;
					case PORTG_ID:break;
					}
	}
}
uint8 DIO_uint8_Get_Port_Value(port_no_type port_no)
{
	uint8 return_value=0;
	switch(port_no)
	{
	case PORTA_ID:return_value =PINA;break;
	case PORTB_ID:return_value =PINB;break;
	case PORTC_ID:return_value =PINC;break;
	case PORTD_ID:return_value =PIND;break;
	case PORTE_ID:return_value =PINE;break;
	case PORTF_ID:return_value =PINF;break;
	case PORTG_ID:return_value =PING;break;
	}

	return return_value;
}
