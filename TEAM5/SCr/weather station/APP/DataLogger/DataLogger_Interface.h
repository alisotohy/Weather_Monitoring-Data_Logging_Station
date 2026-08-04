#ifndef DATALOGGER_INTERFACE_H
#define DATALOGGER_INTERFACE_H

#include <stdint.h>

#include "../../HAL/EEPROM/EEPROM_Interface.h"
#include "DataLogger_Config.h"
#include "DataLogger_Private.h"

/* Structure of one weather record */
typedef struct
{
    uint8_t Temperature;
    uint8_t Light;
    uint8_t Alarm;
    uint8_t Reserved;
}Logger_Record_t;

/* Initialize Logger */
void DataLogger_Init(void);

/* Save new record */
void DataLogger_Save(uint8_t Temp,uint8_t Light,uint8_t Alarm);

/* Read record */
void DataLogger_Read(uint16_t Index,Logger_Record_t *Record);

/* Clear all records */
void DataLogger_Clear(void);

/* Return number of saved records */
uint16_t DataLogger_GetRecordsCount(void);


#endif