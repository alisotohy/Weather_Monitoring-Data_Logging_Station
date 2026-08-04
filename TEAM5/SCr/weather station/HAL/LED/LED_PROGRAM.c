#include "LED_INTERFACE.h"

void LED_Init(uint8_t LED_NAME)
{
    switch(LED_NAME)
    {
        case LED_0:DIO_InitPin(LED_0_GROUP , LED_0_PIN , Output);break;
        case LED_1:DIO_InitPin(LED_1_GROUP , LED_1_PIN , Output);break;
    }
}

void LED_On(uint8_t LED_NAME)
{
    switch(LED_NAME) 
    {
        case LED_0:
            if(LED_0_STATE == LED_ACTIVE_HIGH) 
            {
                DIO_WritePin(LED_0_GROUP , LED_0_PIN , High);
            } 
            else if(LED_0_STATE == LED_ACTIVE_LOW) 
            {
                DIO_WritePin(LED_0_GROUP , LED_0_PIN , Low);
            }
            break;

        case LED_1:
            if(LED_1_STATE == LED_ACTIVE_HIGH) 
            {
                DIO_WritePin(LED_1_GROUP , LED_1_PIN , High);
            } 
            else if(LED_1_STATE == LED_ACTIVE_LOW) 
            {
                DIO_WritePin(LED_1_GROUP , LED_1_PIN , Low);
            }
            break;
    }
}

void LED_Off(uint8_t LED_NAME)
{
    switch(LED_NAME) 
    {
        case LED_0:
            if(LED_0_STATE == LED_ACTIVE_HIGH) 
            {
                DIO_WritePin(LED_0_GROUP , LED_0_PIN , Low);
            } 
            else if(LED_0_STATE == LED_ACTIVE_LOW) 
            {
                DIO_WritePin(LED_0_GROUP , LED_0_PIN , High);
            }
            break;

        case LED_1:
            if(LED_1_STATE == LED_ACTIVE_HIGH) 
            {
                DIO_WritePin(LED_1_GROUP , LED_1_PIN , Low);
            } 
            else if(LED_1_STATE == LED_ACTIVE_LOW) 
            {
                DIO_WritePin(LED_1_GROUP , LED_1_PIN , High);
            }
            break;
    }
}

void LED_Toggle(uint8_t LED_NAME)
{
    switch(LED_NAME)
    {
        case LED_0: DIO_TogglePin(LED_0_GROUP , LED_0_PIN);break;
        case LED_1: DIO_TogglePin(LED_1_GROUP , LED_1_PIN);break;
    }
}