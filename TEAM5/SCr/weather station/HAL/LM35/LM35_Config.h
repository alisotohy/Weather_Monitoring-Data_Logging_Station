#ifndef LM35_CONFIG_H
#define LM35_CONFIG_H

// Which ADC channel the LM35 output is physically connected to (0 -> 7)
#define LM35_ADC_Channel        5

// Reference voltage in Volts - MUST match what you configure in ADC_Init
// (e.g. 5 for AVCC, 2.56 for Adc_Internal)
#define LM35_Vref               5UL

// ADC resolution steps (10-bit ADC = 1024)
#define LM35_ADC_Resolution     1024

#endif