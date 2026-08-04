#include "LCD_Interface.h"
#include <util/delay.h>

void LCD_WriteData(uint8_t Data, uint8_t ModeType)
{
    if(ModeType == Lcd_8bitMode)
    {
        DIO_WritePin(Lcd_RSGroup, Lcd_RSPin, High);
        DIO_WritePin(Lcd_RWGroup, Lcd_RWPin, Low);
        DIO_WriteGroup(Lcd_DataGroup, Data);
        DIO_WritePin(Lcd_EGroup, Lcd_EPin, High);
        _delay_ms(1);
        DIO_WritePin(Lcd_EGroup, Lcd_EPin, Low);
    }
}

void LCD_WriteInstruction(uint8_t Instruction, uint8_t ModeType)
{
    if(ModeType == Lcd_8bitMode)
    {
        DIO_WritePin(Lcd_RSGroup, Lcd_RSPin, Low);
        DIO_WritePin(Lcd_RWGroup, Lcd_RWPin, Low);
        DIO_WriteGroup(Lcd_DataGroup, Instruction);
        DIO_WritePin(Lcd_EGroup, Lcd_EPin, High);
        _delay_ms(1);
        DIO_WritePin(Lcd_EGroup, Lcd_EPin, Low);
    }
}

// =================== الدوال المعدلة (من غير معاملات) ===================

void LCD_Init(void)   // <--- من غير ModeType
{
    DIO_InitPin(Lcd_RSGroup, Lcd_RSPin, Output);
    DIO_InitPin(Lcd_RWGroup, Lcd_RWPin, Output);
    DIO_InitPin(Lcd_EGroup, Lcd_EPin, Output);
    DIO_InitGroup(Lcd_DataGroup, 0xFF);

    _delay_ms(35);
    LCD_WriteInstruction(Lcd_8bitMode2Line5x8F, Lcd_8bitMode);
    _delay_ms(1);
    LCD_WriteInstruction(Lcd_CursorOn, Lcd_8bitMode);
    _delay_ms(1);
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_8bitMode);
    _delay_ms(2);
    LCD_WriteInstruction(Lcd_EntryMode1, Lcd_8bitMode);
    _delay_ms(1);
}

void LCD_WriteString(uint8_t *String)   // <--- من غير ModeType
{
    if(String != Null)
    {
        uint8_t count = 0;
        while(String[count] != '\0')
        {
            LCD_WriteData(String[count], Lcd_8bitMode);
            count++;
        }
    }
}

void LCD_GotoXY(uint8_t X, uint8_t Y)
{
    uint8_t DigitAddress = 0;
    switch(X)
    {
        case 0: DigitAddress = 0x00 + Y; break;
        case 1: DigitAddress = 0x40 + Y; break;
        default: DigitAddress = 0x00 + Y; break;
    }
    LCD_WriteInstruction(DigitAddress | 0x80, Lcd_8bitMode);
}

void LCD_WriteNumber(uint8_t Number)
{
    uint8_t Tens = Number / 10;
    uint8_t Units = Number % 10;
    if (Tens != 0)
    {
        LCD_WriteData(Tens + '0', Lcd_8bitMode);
    }
    LCD_WriteData(Units + '0', Lcd_8bitMode);
}