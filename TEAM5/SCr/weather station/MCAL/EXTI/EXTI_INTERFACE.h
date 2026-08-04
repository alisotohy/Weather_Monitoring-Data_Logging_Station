#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include <stdint.h>
#include "../../COMMON/BITMATH.h"
#include "../../COMMON/Defines.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"

#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"


void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);
void EXTI_SetSenseControl(uint8_t InterruptName , uint8_t SenseMode);
void EXTI_SetCallBack(uint8_t InterruptName , void (*Copy_pf)(void));

#endif