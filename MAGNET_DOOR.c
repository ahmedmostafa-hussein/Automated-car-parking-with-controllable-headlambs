
#include"MAGNET_DOOR.h"

void Mag_Door_Init(void)
{
DIO_void_Set_Pin_Dirction(Magnet_Door_Port,Magnet_Door_Pin,INPUT);
DIO_void_Set_Pin_Value(Magnet_Door_Port,Magnet_Door_Pin,HIGH);
}

uint8 Check_Door_Is_Closed(void)
{
uint8 ret=0;
ret=DIO_value_type_Get_Pin_Value(Magnet_Door_Port,Magnet_Door_Pin);
return ret;
}
