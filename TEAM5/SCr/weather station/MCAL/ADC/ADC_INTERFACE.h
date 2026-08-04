#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include <stdint.h>
#include "../../Common/Bitmath.h"
#include "../../Common/Defines.h"
#include "../Atmega32RegMap.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "../DIO/DIO_Interface.h"

#include "util/delay.h"


/*
 * Description : Configure the ADC (reference voltage, result adjustment,
 *               clock prescaler) and enable it. Single-conversion /
 *               polling mode only - no interrupt, no auto-trigger.
 */
void ADC_Init(uint8_t Reference, uint8_t Adjust, uint8_t Division_Factor);

/*
 * Description : Select a channel, start a conversion, block (poll) until
 *               it finishes, then return the 10-bit digital result.
 */
uint16_t ADC_Read(uint8_t SingleEnded_Channel);



#endif