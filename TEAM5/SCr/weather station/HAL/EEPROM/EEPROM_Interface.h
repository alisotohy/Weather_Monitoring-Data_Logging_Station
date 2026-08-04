#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

#include <stdint.h>
#include "../../COMMON/BITMATH.h"
#include "../../COMMON/Defines.h"
#include "../../MCAL/Atmega32RegMap.h"
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"

/*
 * Description : Writes a single byte to internal EEPROM at the given
 *               address. Blocking - waits for any previous write to
 *               finish first, and waits for this write to complete
 *               before returning (~3.4ms on real hardware).
 */
void EEPROM_WriteByte(uint16_t Address, uint8_t Data);

/*
 * Description : Reads a single byte from internal EEPROM at the given
 *               address into *Data. Blocking - waits for any pending
 *               write to finish first (reads are otherwise fast).
 */
void EEPROM_ReadByte(uint16_t Address, uint8_t *Data);

/*
 * Description : Writes Length consecutive bytes starting at Address.
 *               Blocking - each byte waits for the previous one to finish.
 */
void EEPROM_WriteBlock(uint16_t Address, uint8_t *Data, uint16_t Length);

/*
 * Description : Reads Length consecutive bytes starting at Address into
 *               the Data buffer (caller must ensure it's big enough).
 */
void EEPROM_ReadBlock(uint16_t Address, uint8_t *Data, uint16_t Length);

#endif
