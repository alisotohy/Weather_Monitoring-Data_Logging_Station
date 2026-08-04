/*
========================================================
                Weather Controller (Final Version)
========================================================
*/

#include "Weather_Controller_Interface.h"

/* APP Modules */
#include "../Monitoring/Monitoring_Interface.h"
#include "../AlarmManager/AlarmManager_Interface.h"
#include "../DataLogger/DataLogger_Interface.h"
#include "../UART_Handler/UART_Handler_Interface.h"

/* HAL Drivers */
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/LED/LED_INTERFACE.h"
#include "../../HAL/BUZZER/BUZZER_INTERFACE.h"

/* MCAL Drivers */
#include "../../MCAL/GIE/GIE_INTERFACE.h"
#include "../../MCAL/Timer0/Timer0_Interface.h"

#include <util/delay.h>


static uint32_t SystemTicks = 0;          
static uint32_t LastSensorRead = 0;
static uint32_t LastLCDUpdate = 0;
static uint32_t LastLogSave = 0;

void Timer_Init(void)
{
    TCCR0_Reg = 0;
    SetBit(TCCR0_Reg, Timer0_WGM01);   // CTC Mode
    OCR0_Reg = 124;                     // (8MHz/64) = 125kHz -> 125 tick = 1ms
    SetBit(TIMSK_Reg, Timer0_OCIE0);    //  Compare Match
    SetBit(TCCR0_Reg, Timer0_CS00);     
    SetBit(TCCR0_Reg, Timer0_CS01);     // Prescaler = 64
}

static void Timer_Callback(void)
{
    SystemTicks++; 
}

void WeatherController_Init(void)
{
   
    ADC_Init(ADC_AVCC, ADC_RightAdjust, ADC_DivisionFactor128);

    // 2) LCD  
    LCD_Init();

    // 3) LED
    LED_Init(LED_0);

    // 4) Buzzer
    BUZZER_Init();

    // 5) UART 
    UARTManager_Init();

    // 6) Data Logger
    DataLogger_Init();

    // 7) Monitoring
    Monitoring_Init();

    // 8) Alarm Manager
    AlarmManager_Init();

    // 9) Timer Scheduler
    Timer_Init();

    // 10)  ا Callback  ( SystemTicks كل 1ms)
    TIMER0_SetCallBack(Timer0_CompareMatchInterrupt, Timer_Callback);

    // 11) int
    GIE_Enable();

    //     LCD_Clear)
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_8bitMode);
    LCD_WriteString((uint8_t*)"Weather Station");
    _delay_ms(500); // تأخير بسيط
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_8bitMode);
}

void WeatherController_Run(void)
{
    Monitoring_Data_t SensorData;
    uint8_t AlarmState;

    /* -------------------------------------------
       ------------------------------------------- */
    if ((SystemTicks - LastSensorRead) >= 500)
    {
        LastSensorRead = SystemTicks;

        Monitoring_Update();
        SensorData = Monitoring_GetData();

        AlarmManager_Update(SensorData.Temperature, SensorData.Light);
        AlarmState = AlarmManager_GetStatus();

        Global_Temperature = SensorData.Temperature;
        Global_Light = SensorData.Light;
        Global_AlarmState = AlarmState;
    }

    /* -------------------------------------------
       ------------------------------------------- */
    if ((SystemTicks - LastLCDUpdate) >= 1000)
    {
        LastLCDUpdate = SystemTicks;

        LCD_GotoXY(0, 0);
        LCD_WriteString("Temp: ");
        LCD_WriteNumber(Global_Temperature);
        LCD_WriteString(" C  ");

        LCD_GotoXY(1, 0);
        LCD_WriteString("Light: ");
        LCD_WriteNumber(Global_Light);
        LCD_WriteString("%  ");

        LCD_GotoXY(1, 10);
        if (Global_AlarmState == 1)
            LCD_WriteString("ALARM");
        else
            LCD_WriteString("OK   ");
    }

    /* -------------------------------------------
       ------------------------------------------- */
    if ((SystemTicks - LastLogSave) >= 5000)
    {
        LastLogSave = SystemTicks;

        DataLogger_Save(Global_Temperature, Global_Light, Global_AlarmState);
    }

    /* -------------------------------------------
       ------------------------------------------- */
    UARTManager_Task();
}
