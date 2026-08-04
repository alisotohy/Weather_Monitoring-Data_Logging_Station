#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H
#include  <stdint.h>
#include "../../COMMON/BITMATH.h"
#include "../../COMMON/Defines.h"
#include "../Atmega32RegMap.h"
#include "Timer0_Private.h"

void TIMER0_Init(Timer0_Config_t Config);
void TIMER0_Start(uint8_t ClockSelectValue);
void TIMER0_Stop();
void TIMER0_SetPreload(uint8_t PreloadValue);
void TIMER0_SetCompare(uint8_t CompareValue);
void TIMER0_SetCallBack(uint8_t TimerInterruptType, void (*PF)(void));
void TIMER0_SetPWM_DutyCycle(uint8_t DutyCyclePercentage);


#endif