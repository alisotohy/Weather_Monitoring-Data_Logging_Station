#include "AlarmManager_Interface.h"

/* Store current alarm state */
static uint8_t AlarmStatus = ALARM_OFF;

/*Initialize Alarm Hardware*/
void AlarmManager_Init(void)
{
    /* Initialize alarm LED */
    LED_Init(LED_0);

    /* Initialize buzzer */
    BUZZER_Init();
}

/*Check Temperature and Light*/
void AlarmManager_Update(uint8_t Temperature,uint8_t Light)
{
    /* Assume system is normal */
    AlarmStatus = ALARM_OFF;

    /* High temperature alarm */
    if(Temperature >= HIGH_TEMP_THRESHOLD)
    {
        AlarmStatus = ALARM_ON;
    }

    /* Low temperature alarm */
    if(Temperature <= LOW_TEMP_THRESHOLD)
    {
        AlarmStatus = ALARM_ON;
    }

    /* Low light alarm */
    if(Light <= LOW_LIGHT_THRESHOLD)
    {
        AlarmStatus = ALARM_ON;
    }

    /* High light alarm */
    if(Light >= HIGH_LIGHT_THRESHOLD)
    {
        AlarmStatus = ALARM_ON;
    }
    

    /* Activate outputs */
    if(AlarmStatus == ALARM_ON)
    {
        LED_On(LED_0);
        BUZZER_On();
    }
    else
    {
        LED_Off(LED_0);
        BUZZER_Off();
    }
}

/*Return current alarm state*/
uint8_t AlarmManager_GetStatus(void)
{
    return AlarmStatus;
}