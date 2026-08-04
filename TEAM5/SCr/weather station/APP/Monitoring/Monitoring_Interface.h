#ifndef MONITORING_INTERFACE_H
#define MONITORING_INTERFACE_H

#include <stdint.h>
#include <util/delay.h>

#include "../../MCAL/ADC/ADC_INTERFACE.h"
#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/LDR/LDR_Interface.h"
#include "Monitoring_Config.h"
#include "Monitoring_Private.h"


/* Structure that stores current sensor readings */
typedef struct
{
    uint8_t Temperature;
    uint8_t Light;
}Monitoring_Data_t;

/* Initialize monitoring module */
void Monitoring_Init(void);

/* Update all sensor readings */
void Monitoring_Update(void);

/* Return latest sensor values */
Monitoring_Data_t Monitoring_GetData(void);


#endif