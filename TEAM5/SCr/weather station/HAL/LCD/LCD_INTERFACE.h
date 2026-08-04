#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LCD_PRIVATE.h"
#include "LCD_CONFIG.h"

void LCD_Init(void);
void LCD_WriteInstruction(uint8_t Instruction,uint8_t ModeType);
void LCD_WriteData(uint8_t Data,uint8_t ModeType);
void LCD_WriteString(uint8_t *String);
void LCD_WriteNumber(uint8_t Number);
void LCD_GotoXY(uint8_t X,uint8_t Y);


#endif