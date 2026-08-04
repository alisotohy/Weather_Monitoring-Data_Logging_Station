#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#include  <stdint.h>
#include"../../COMMON/Defines.h"
#include "../../COMMON/BITMATH.h"
#include "../Atmega32RegMap.h"
#include "DIO_PRIVATE.h"

void DIO_InitPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirState);
void DIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);
void DIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t *PinState);
void DIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);


void DIO_InitGroup(uint8_t GroupName,uint8_t DirState);   
void DIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);
void DIO_ReadGroup(uint8_t GroupName,uint8_t *InputStates);


#endif