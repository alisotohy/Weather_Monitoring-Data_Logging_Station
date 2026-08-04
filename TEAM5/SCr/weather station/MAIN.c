/*
========================================================
                Weather Monitoring Station
========================================================
*/

#include "APP/Weather_Controller/Weather_Controller_Interface.h"

int main(void)
{
    /* Initialize Complete System */
    WeatherController_Init();

    /* Super Loop */
    while (1)
    {
        /* Execute Weather Station Tasks */
        WeatherController_Run();
    }

    /* Never reaches here */
    return 0;
}
