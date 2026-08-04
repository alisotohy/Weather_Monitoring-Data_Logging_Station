#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LED_CONFIG.h"
#include "LED_PRIVATE.h"

void LED_Init(uint8_t LED_NAME);
void LED_On(uint8_t LED_NAME);
void LED_Off(uint8_t LED_NAME);
void LED_Toggle(uint8_t LED_NAME);


#endif