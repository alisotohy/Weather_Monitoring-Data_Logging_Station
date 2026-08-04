#include "DataLogger_Interface.h"



/* Variable that stores number of saved records */
static uint16_t Global_RecordCounter = 0;

/*
  Function: DataLogger_Init
  -------------------------
  Reads number of saved records from EEPROM.
  If EEPROM is empty, start from zero.
*/
void DataLogger_Init(void)
{
    uint8_t Counter = 0;

    /* Read record counter from EEPROM */
    EEPROM_ReadByte(LOGGER_COUNTER_ADDRESS, &Counter);

    /* Store value in RAM */
    Global_RecordCounter = Counter;

    /* Protection against corrupted EEPROM value */
    if(Global_RecordCounter > LOGGER_MAX_RECORDS)
    {
        Global_RecordCounter = 0;
    }
}

/*
  Function: DataLogger_Save
  -------------------------
  Save one weather record into EEPROM.
*/
void DataLogger_Save(uint8_t Temp, uint8_t Light, uint8_t Alarm)
{
    Logger_Record_t Record;
    uint16_t Address;

    if(Global_RecordCounter >= LOGGER_MAX_RECORDS) return;

    // 1)  EEPROM  ( Record)
    //  (Global_RecordCounter + 1)  EEPROM
    EEPROM_WriteByte(LOGGER_COUNTER_ADDRESS, (uint8_t)(Global_RecordCounter + 1));

    // 2)+1 counter in RAM
    Global_RecordCounter++;

    // 3) write new record
    Record.Temperature = Temp;
    Record.Light = Light;
    Record.Alarm = Alarm;
    Record.Reserved = 0;
    Address = LOGGER_START_ADDRESS + ((Global_RecordCounter - 1) * LOGGER_RECORD_SIZE);
    EEPROM_WriteBlock(Address, (uint8_t*)&Record, LOGGER_RECORD_SIZE);
}

/*
  Function: DataLogger_Read
  -------------------------
  Read one record from EEPROM.
*/
void DataLogger_Read(uint16_t Index, Logger_Record_t *Record)
{
    uint16_t Address;

    /* Check valid pointer */
    if(Record == Null)
    {
        return;
    }

    /* Check record number */
    if(Index >= Global_RecordCounter)
    {
        return;
    }

    /* Calculate EEPROM address */
    Address = LOGGER_START_ADDRESS + (Index * LOGGER_RECORD_SIZE);

    /* Read structure */
    EEPROM_ReadBlock(Address,(uint8_t*)Record,LOGGER_RECORD_SIZE);
}

/*
  Function: DataLogger_Clear
  --------------------------
  Remove all stored records.
*/
void DataLogger_Clear(void)
{
    /* Reset record counter */
    Global_RecordCounter = 0;

    /* Save zero inside EEPROM */
    EEPROM_WriteByte(LOGGER_COUNTER_ADDRESS,0);
}

/*
  Function: DataLogger_GetRecordsCount
  ------------------------------------
  Return total saved records.
*/
uint16_t DataLogger_GetRecordsCount(void)
{
    return Global_RecordCounter;
}
