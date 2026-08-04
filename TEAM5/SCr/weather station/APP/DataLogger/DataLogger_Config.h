#ifndef DATALOGGER_CONFIG_H
#define DATALOGGER_CONFIG_H

/* EEPROM Start Address */
#define LOGGER_START_ADDRESS      0x0010

/* Address that stores number of records */
#define LOGGER_COUNTER_ADDRESS    0x0000

/* Log every 5 seconds */
#define LOGGER_LOG_PERIOD_SEC     5

/* Maximum records */
#define LOGGER_MAX_RECORDS        100

#endif