#ifndef UART_HANDLER_INTERFACE_H
#define UART_HANDLER_INTERFACE_H

#include <stdint.h>

#include "../../MCAL/UART/UART_INTERFACE.h"

#include "../Monitoring/Monitoring_Interface.h"
#include "../AlarmManager/AlarmManager_Interface.h"
#include "../DataLogger/DataLogger_Interface.h"

#include "UART_Handler_Private.h"
#include "UART_Handler_Config.h"

/* Initialize UART Module */
void UARTManager_Init(void);

/* Receive and process UART commands */
void UARTManager_Task(void);

/* Send current measurements */
void UARTManager_SendCurrentData(uint8_t Temp, uint8_t Light, uint8_t Alarm);


#endif