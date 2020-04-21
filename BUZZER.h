/*
 * BUZZER.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_
#include"DIO.h"
#define BUZZER_PIN  PIN7
#define BUZZER_PORT PORTE_ID
void Buzzer_On(void);
void Buzzer_Off(void);

#endif /* HAL_BUZZER_BUZZER_H_ */
