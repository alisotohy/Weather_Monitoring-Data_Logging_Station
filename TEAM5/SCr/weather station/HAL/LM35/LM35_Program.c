#include "LM35_Interface.h"

uint16_t LM35_GetTemperature(void)
{
    uint16_t Local_ADCDigitalValue = 0;
    uint32_t Local_Voltage_mV      = 0;
    uint16_t Local_Temperature     = 0;


    // 1) Read the raw digital value from the ADC channel connected to LM35
    Local_ADCDigitalValue = ADC_Read(LM35_ADC_Channel);

    // 2) Convert the digital value into an actual voltage in millivolts
    //    Voltage(mV) = (ADC_Value * Vref(V) * 1000) / Resolution
    Local_Voltage_mV = ((uint32_t)Local_ADCDigitalValue * LM35_Vref * 1000) / LM35_ADC_Resolution;

    // 3) Convert voltage to temperature (LM35 -> 10 mV per 1 degree Celsius)
    Local_Temperature = (uint8_t)(Local_Voltage_mV / LM35_mV_Per_Degree);

    return Local_Temperature;
}
