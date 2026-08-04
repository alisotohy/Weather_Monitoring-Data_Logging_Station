#include "LDR_Interface.h"

uint16_t LDR_GetRawValue(void)
{
    return ADC_Read(LDR_ADC_Channel);
}

uint16_t LDR_GetLightPercentage(void)
{
    uint16_t Local_ADCDigitalValue = 0;
    uint16_t Local_Percentage      = 0;


    Local_ADCDigitalValue = ADC_Read(LDR_ADC_Channel);

    // Scale raw ADC value (0 -> Resolution-1) into 0 -> 100 %
    Local_Percentage = (uint8_t)(((uint32_t)Local_ADCDigitalValue * LDR_MaxPercentage ) / (LDR_ADC_Resolution ));

    #if LDR_ReadingMode == LDR_InvertedReading
        Local_Percentage = LDR_MaxPercentage - Local_Percentage;
    #endif

    return Local_Percentage;
}