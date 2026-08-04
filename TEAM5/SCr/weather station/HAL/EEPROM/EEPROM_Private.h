#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H

/*-------------------------------------------------
 *              EECR Register Bits
 *-------------------------------------------------*/
#define Eeprom_EERIE    3   // EEPROM Ready Interrupt Enable
#define Eeprom_EEMWE    2   // EEPROM Master Write Enable
#define Eeprom_EEWE     1   // EEPROM Write Enable
#define Eeprom_EERE     0   // EEPROM Read Enable

/*-------------------------------------------------
 *   I-Bit in SREG - needed to protect the write
 *   sequence's 4-cycle timing window from being
 *   interrupted (kept local to this driver on
 *   purpose, instead of reaching into GIE_Private.h)
 *-------------------------------------------------*/
#define Eeprom_GlobalIntBit   7

/*-------------------------------------------------
 *   ATmega32 internal EEPROM size = 1024 bytes
 *   (10-bit address, EEAR9:0)
 *-------------------------------------------------*/
#define Eeprom_AddressMask    0x03FF

#endif
