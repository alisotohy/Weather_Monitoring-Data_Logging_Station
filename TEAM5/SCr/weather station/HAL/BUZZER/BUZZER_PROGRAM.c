#include "BUZZER_INTERFACE.h"

void BUZZER_Init(void)
{
    DIO_InitPin(BUZZER_GROUP , BUZZER_PIN , Output);
    BUZZER_Off();
}

void BUZZER_On(void)
{
    if(BUZZER_STATE == BUZZER_ACTIVE_HIGH)
    {
        DIO_WritePin(BUZZER_GROUP , BUZZER_PIN , High);
    }
    else if(BUZZER_STATE == BUZZER_ACTIVE_LOW)
    {
        DIO_WritePin(BUZZER_GROUP , BUZZER_PIN , Low);
    }
}

void BUZZER_Off(void)
{
    if(BUZZER_STATE == BUZZER_ACTIVE_HIGH)
    {
        DIO_WritePin(BUZZER_GROUP , BUZZER_PIN , Low);    
    }
    else if(BUZZER_STATE == BUZZER_ACTIVE_LOW)
    {
        DIO_WritePin(BUZZER_GROUP , BUZZER_PIN , High);
    }
}