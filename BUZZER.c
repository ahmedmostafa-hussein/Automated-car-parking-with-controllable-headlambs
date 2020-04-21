#include"BUZZER.h"

void Buzzer_Init(void)
{
	DIO_void_Set_Pin_Dirction(BUZZER_PORT,BUZZER_PIN,OUTPUT);
}
void Buzzer_On(void)
{
DIO_void_Set_Pin_Value(BUZZER_PORT,BUZZER_PIN,HIGH);
}

void Buzzer_Off(void)
{
	DIO_void_Set_Pin_Value(BUZZER_PORT,BUZZER_PIN,LOW);
}
