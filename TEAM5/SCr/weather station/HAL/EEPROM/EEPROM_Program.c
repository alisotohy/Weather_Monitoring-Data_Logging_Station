#include "EEPROM_Interface.h"

void EEPROM_WriteByte(uint16_t Address, uint8_t Data)
{
    uint8_t Local_SREG_Backup = 0;

    Address &= Eeprom_AddressMask;

    // 1) Wait for any previous write to finish
    while (ReadBit(EECR_Reg, Eeprom_EEWE) == 1);

    // 2) Set up address and data registers
    EEARH_Reg = (uint8_t)(Address >> 8);
    EEARL_Reg = (uint8_t)(Address);
    EEDR_Reg  = Data;

    // 3) The next two writes (EEMWE then EEWE) must happen within 4 clock
    //    cycles of each other, or the write is silently aborted by hardware.
    //    An interrupt firing in between would blow that window, so save
    //    the current global-interrupt state and disable it for this
    //    critical section, then restore exactly what it was before.
    Local_SREG_Backup = SREG_Reg;
    ClearBit(SREG_Reg, Eeprom_GlobalIntBit);

    SetBit(EECR_Reg, Eeprom_EEMWE);
    SetBit(EECR_Reg, Eeprom_EEWE);

    SREG_Reg = Local_SREG_Backup;
}


void EEPROM_ReadByte(uint16_t Address, uint8_t *Data)
{
    if (Data != Null)
    {
        Address &= Eeprom_AddressMask;

        // Wait for any pending write to finish first
        while (ReadBit(EECR_Reg, Eeprom_EEWE) == 1);

        EEARH_Reg = (uint8_t)(Address >> 8);
        EEARL_Reg = (uint8_t)(Address);

        SetBit(EECR_Reg, Eeprom_EERE);

        *Data = EEDR_Reg;
    }
}


void EEPROM_WriteBlock(uint16_t Address, uint8_t *Data, uint16_t Length)
{
    uint16_t Local_Counter = 0;

    if (Data != Null)
    {
        for (Local_Counter = 0; Local_Counter < Length; Local_Counter++)
        {
            EEPROM_WriteByte(Address + Local_Counter, Data[Local_Counter]);
        }
    }
}


void EEPROM_ReadBlock(uint16_t Address, uint8_t *Data, uint16_t Length)
{
    uint16_t Local_Counter = 0;

    if (Data != Null)
    {
        for (Local_Counter = 0; Local_Counter < Length; Local_Counter++)
        {
            EEPROM_ReadByte(Address + Local_Counter, &Data[Local_Counter]);
        }
    }
}
