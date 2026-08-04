#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "BUZZER_CONFIG.h"
#include "BUZZER_PRIVATE.h"

void BUZZER_Init(void);

void BUZZER_On(void);

void BUZZER_Off(void);

#endif