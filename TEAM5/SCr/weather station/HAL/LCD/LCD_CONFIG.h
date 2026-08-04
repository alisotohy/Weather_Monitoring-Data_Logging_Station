#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#define Lcd_RSPin      DIO_Pin0
#define Lcd_RSGroup    Dio_GroupA

#define Lcd_RWPin      DIO_Pin1
#define Lcd_RWGroup    Dio_GroupA

#define Lcd_EPin       DIO_Pin2
#define Lcd_EGroup     Dio_GroupA


#define Lcd_D4Pin      DIO_Pin0
#define Lcd_D5Pin      DIO_Pin1
#define Lcd_D6Pin      DIO_Pin2
#define Lcd_D7Pin      DIO_Pin3

#define Lcd_DataGroup  Dio_GroupC

/*
#define LCD_ENABLE_PULSE_US    1
#define LCD_COMMAND_DELAY_US   100
*/

#endif