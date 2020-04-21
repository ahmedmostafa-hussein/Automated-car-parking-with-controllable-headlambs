/*
 * LCD_V2.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef HAL_LCD_V2_LCD_V2_H_
#define HAL_LCD_V2_LCD_V2_H_

#include "../../LIB/Std_types.h"
#include"../../LIB/utils.h"
#include "../../MCAL/DIO/DIO.h"

#include <util/delay.h>



#define M_4BIT 0
#define M_8BIT 1

#define RS PIN5
#define RW PIN6
#define E  PIN7
#define LCD_PORT          PORTC_ID
#define LCD_CONTROL_PORT  PORTB_ID
#define LCD_MODE          M_4BIT
#define Fourbit_4         PIN4
#define Fourbit_5         PIN5
#define Fourbit_6 PIN6
#define Fourbit_7 PIN7

//#define M_4BIT_MASK

typedef enum
{
	Cursor,
	Display
}u8DisplayOrCursor;
typedef enum
{
	Left=0,
	Right
}u8Direction;
void LCD_vidDirections(void);
void LCD_vidDirections4(void);
void LCD_vidInit(void);
void LCD_vidInit4(void);
void LCD_vidWriteCharacter(uint8 u8DataCpy);
void LCD_vidWriteCharacter4(uint8 u8DataCpy);
void LCD_vidSendCommand(uint8 u8CommandCpy);
void LCD_vidSendCommand4(uint8 u8CommandCpy);
void LCD_vidWriteString(uint8 *pu8StringCpy);
void LCD_vidWriteString4(uint8 *pu8StringCpy);
void LCD_vidWriteSignedInteger(sint64 s64SignedNumCpy);
void LCD_vidWriteSignedInteger4(sint64 s64SignedNumCpy);
void LCD_vidWriteUnSignedInteger(uint64 u64UnSignedNumCpy);
void LCD_vidWriteUnSignedInteger4(uint64 number);
void LCD_vidGotoxy(uint8 u8Numx,uint8 u8Numy);
void LCD_vidGotoxy4(uint8 u8Numx,uint8 u8Numy);
void LCD_vidShiftDisplayCursor(uint8 u8Direction,uint8 u8ShiftNumber,uint8 u8DisplayOrcursor);
void LCD_vidShiftDisplayCursor4(uint8 u8Direction,uint8 u8ShiftNumber,uint8 u8DisplayOrcursor);
void LCD_vidPrint(uint8 str[]);
void LCD_vidPrint4(uint8 str[]);
void LCD_vidPrintInTwoLines(uint8 str[]);
void LCD_vidPrintInTwoLines4(uint8 str[]);

#endif /* HAL_LCD_V2_LCD_V2_H_ */
