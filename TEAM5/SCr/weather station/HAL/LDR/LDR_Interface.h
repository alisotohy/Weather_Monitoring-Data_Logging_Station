#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

#include <stdint.h>
#include "../../Common/Bitmath.h"
#include "../../Common/Defines.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LDR_Private.h"
#include "LDR_Config.h"

/*
 * Description : Reads the LDR sensor through the ADC (blocking/polling)
 *               and returns the light intensity as a percentage (0-100).
 *               0   = darkest reading
 *               100 = brightest reading
 * Note        : ADC_Init() must already be called (once, in main) before
 *               using this function. Uses ADC_Read internally.
 */
uint16_t LDR_GetLightPercentage(void);

/*
 * Description : Reads the LDR sensor and returns the raw ADC digital
 *               value (0 -> LDR_ADC_Resolution-1) with no conversion.
 *               Useful for calibrating your own thresholds.
 */
uint16_t LDR_GetRawValue(void);

#endif