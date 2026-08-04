#include "Monitoring_Interface.h"


/* Store latest sensor readings */
static Monitoring_Data_t CurrentData;

/*Initialize monitoring module */
void Monitoring_Init(void)
{
    CurrentData.Temperature = 0;
    
    CurrentData.Light = 0;
}

/*Read all sensors and update stored values*/
void Monitoring_Update(void)
{
    /* Read current temperature from LM35 */
    CurrentData.Temperature = LM35_GetTemperature();


    _delay_ms(100);
    
    /* Read current light percentage */
    CurrentData.Light = LDR_GetLightPercentage();
}

/*Return latest sensor readings*/
Monitoring_Data_t Monitoring_GetData(void)
{
    return CurrentData;
}