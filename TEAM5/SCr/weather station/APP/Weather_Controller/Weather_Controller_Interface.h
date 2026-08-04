#ifndef WEATHER_CONTROLLER_INTERFACE_H
#define WEATHER_CONTROLLER_INTERFACE_H

#include "Weather_Controller_Config.h"
#include "Weather_Controller_Private.h"

#include "../../HAL/LM35/LM35_Interface.h"
#include "../../HAL/LDR/LDR_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/LED/LED_INTERFACE.h"
#include "../../HAL/BUZZER/BUZZER_INTERFACE.h"

/* Initialize complete weather station */
void WeatherController_Init(void);

/* Run Weather Station */
void WeatherController_Run(void);



#endif