#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

#include <stdint.h>
#include "../../Common/Bitmath.h"
#include "../../Common/Defines.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LM35_Private.h"
#include "LM35_Config.h"

/*
 * Description : Reads the LM35 sensor through the ADC (blocking/polling)
 *               and returns the temperature in whole degrees Celsius.
 * Note        : ADC_Init() must already be called (once, in main) before
 *               using this function. Uses ADC_Read internally.
 */
uint16_t LM35_GetTemperature(void);

#endif