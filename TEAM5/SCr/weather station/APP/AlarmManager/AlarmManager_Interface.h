#ifndef ALARMMANAGER_INTERFACE_H
#define ALARMMANAGER_INTERFACE_H

#include <stdint.h>

#include "../Monitoring/Monitoring_Interface.h"
#include "../../HAL/LED/LED_INTERFACE.h"
#include "../../HAL/BUZZER/BUZZER_INTERFACE.h"
#include "AlarmManager_Config.h"
#include "AlarmManager_Private.h"



/* Initialize alarm hardware */
void AlarmManager_Init(void);

/* Check sensors and update alarm state */
void AlarmManager_Update(uint8_t Temperature,uint8_t Light);

/* Return current alarm state */
uint8_t AlarmManager_GetStatus(void);



#endif