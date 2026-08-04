#include "ADC_Interface.h"

void ADC_Init(uint8_t Reference, uint8_t Adjust, uint8_t Division_Factor)
{
    // Reference Selection (ADMUX - REFS1:0)
    if (Reference == ADC_AREF)
    {
        ClearBit(ADMUX_Reg, ADC_REFS1);
        ClearBit(ADMUX_Reg, ADC_REFS0);
    }
    else if (Reference == ADC_AVCC)
    {
        ClearBit(ADMUX_Reg, ADC_REFS1);
        SetBit(ADMUX_Reg, ADC_REFS0);
    }
    else if (Reference == ADC_Internal)
    {
        SetBit(ADMUX_Reg, ADC_REFS1);
        SetBit(ADMUX_Reg, ADC_REFS0);
    }

    // Result Adjustment (ADMUX - ADLAR)
    if (Adjust == ADC_RightAdjust)
    {
        ClearBit(ADMUX_Reg, ADC_ADLAR);
    }
    else if (Adjust == ADC_LeftAdjust)
    {
        SetBit(ADMUX_Reg, ADC_ADLAR);
    }

    // Clock Prescaler (ADCSRA - ADPS2:0)
    if (Division_Factor == ADC_DivisionFactor2)
    {
        ClearBit(ADCSRA_Reg, ADC_ADPS2);
        ClearBit(ADCSRA_Reg, ADC_ADPS1);
        ClearBit(ADCSRA_Reg, ADC_ADPS0);
    }
    else if (Division_Factor == ADC_DivisionFactor4)
    {
        ClearBit(ADCSRA_Reg, ADC_ADPS2);
        SetBit(ADCSRA_Reg, ADC_ADPS1);
        ClearBit(ADCSRA_Reg, ADC_ADPS0);
    }
    else if (Division_Factor == ADC_DivisionFactor8)
    {
        ClearBit(ADCSRA_Reg, ADC_ADPS2);
        SetBit(ADCSRA_Reg, ADC_ADPS1);
        SetBit(ADCSRA_Reg, ADC_ADPS0);
    }
    else if (Division_Factor == ADC_DivisionFactor16)
    {
        SetBit(ADCSRA_Reg, ADC_ADPS2);
        ClearBit(ADCSRA_Reg, ADC_ADPS1);
        ClearBit(ADCSRA_Reg, ADC_ADPS0);
    }
    else if (Division_Factor == ADC_DivisionFactor32)
    {
        SetBit(ADCSRA_Reg, ADC_ADPS2);
        ClearBit(ADCSRA_Reg, ADC_ADPS1);
        SetBit(ADCSRA_Reg, ADC_ADPS0);
    }
    else if (Division_Factor == ADC_DivisionFactor64)
    {
        SetBit(ADCSRA_Reg, ADC_ADPS2);
        SetBit(ADCSRA_Reg, ADC_ADPS1);
        ClearBit(ADCSRA_Reg, ADC_ADPS0);
    }
    else if (Division_Factor == ADC_DivisionFactor128)
    {
        SetBit(ADCSRA_Reg, ADC_ADPS2);
        SetBit(ADCSRA_Reg, ADC_ADPS1);
        SetBit(ADCSRA_Reg, ADC_ADPS0);
    }

    // Enable the ADC
    SetBit(ADCSRA_Reg, ADC_ADEN);
}

uint16_t ADC_Read(uint8_t SingleEnded_Channel)
{
    uint16_t Result = 0;

    SingleEnded_Channel &= 0x07; 
    ADMUX_Reg &= 0xE0;
    _delay_ms(1); 
    ADMUX_Reg |= SingleEnded_Channel;
    DIO_InitPin(Dio_GroupA, SingleEnded_Channel, Input);

    SetBit(ADCSRA_Reg, ADC_ADSC);

    while (ReadBit(ADCSRA_Reg, ADC_ADIF) == 0)
    {
           // busy  wait
    }

    Result = ADC_Data_Reg;

    ADCSRA_Reg |= (1 << ADC_ADIF);

    return Result;
}