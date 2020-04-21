/*
 * MAGNET_DOOR.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef HAL_MAGNET_DOOR_MAGNET_DOOR_H_
#define HAL_MAGNET_DOOR_MAGNET_DOOR_H_
#include"DIO.h"
#define Magnet_Door_Pin  7
#define Magnet_Door_Port  PORTA_ID

uint8 Check_Door_Is_Closed(void);

#endif /* HAL_MAGNET_DOOR_MAGNET_DOOR_H_ */
