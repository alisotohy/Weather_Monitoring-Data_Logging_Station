#ifndef LDR_CONFIG_H
#define LDR_CONFIG_H

// Which ADC channel the LDR voltage-divider output is connected to (0 -> 7)
#define LDR_ADC_Channel        6

// ADC resolution steps (10-bit ADC = 1024)
#define LDR_ADC_Resolution     1024

/*
 * Wiring orientation of the voltage divider:
 * - LDR_NormalReading   : ADC value INCREASES as light INCREASES
 *                         (LDR connected to GND, fixed resistor to VCC,
 *                          ADC reads the node between them)
 * - LDR_InvertedReading : ADC value DECREASES as light INCREASES
 *                         (LDR connected to VCC, fixed resistor to GND)
 * Set this to match your actual circuit.
 */
#define LDR_NormalReading      0
#define LDR_InvertedReading    1

#define LDR_ReadingMode        LDR_NormalReading

#endif