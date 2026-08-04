🌦️ Weather Monitoring & Data Logging Station

Embedded Systems Project — ATmega32

A real-time environmental monitoring station built using the ATmega32 AVR microcontroller. The system continuously acquires environmental data, displays live measurements on an LCD, logs historical records to internal EEPROM, generates threshold-based alarms, and communicates with a PC over UART for data retrieval and diagnostics.

This project demonstrates real-time data acquisition, embedded data logging, threshold monitoring, serial communication, and a strict layered embedded software architecture.

📌 Project Overview

Environmental monitoring systems are widely used in agriculture, weather stations, greenhouses, laboratories, warehouses, and smart buildings.

This project implements a compact weather monitoring station capable of continuously collecting sensor measurements, displaying live information on an LCD, storing historical data in EEPROM, generating alarms when environmental limits are exceeded, and allowing users to retrieve logged data and system status through a serial (UART) interface.

🎯 Project Objectives
Continuously monitor environmental conditions
Display real-time sensor values on LCD
Store historical measurements in internal EEPROM
Generate edge-triggered, threshold-based alarms
Support serial communication with a PC over UART
Implement periodic sampling using a Timer0-based cooperative scheduler
Build reusable, layered embedded drivers
Apply strict layered software architecture (LIB/Common → MCAL → HAL → APP)
📋 Functional Requirements
Real-Time Sensor Reading

The controller continuously samples environmental sensors including:

Temperature Sensor (LM35) — ADC Channel 5 (PA5)
Light Sensor (LDR) — ADC Channel 6 (PA6)

Sensor acquisition is performed periodically (every 500 ms) using the ADC driver.

Local Status Display

The LCD continuously displays:

Current Temperature
Light Intensity
System / Alarm Status

Example:

Temp : 28C
Light: 72%
Data Logging

The DataLogger module periodically stores measurements inside EEPROM.

Each record contains:

Record ID (sequence number)
Temperature
Light Level

Measurements are saved at a fixed interval (every 5 seconds), with a capacity of up to 60 records.

Data Retrieval

Stored records and system information can be retrieved through UART. Available commands:

READ LOG
CLEAR LOG
CURRENT DATA
SYSTEM STATUS
HELP

Example output:

Record 15
Temperature : 29C
Light       : 68%
Threshold Alarm

The AlarmManager module compares sensor values against predefined thresholds and fires an edge-triggered alarm (sent once per crossing, not repeated while the condition persists):

Temperature Alarm

High Temperature
Low Temperature

Light Alarm

Very Low Light
Very High Light

When a limit is exceeded, a UART notification is sent and the LCD/status output is updated accordingly.

System Monitoring

The Monitoring module continuously tracks:

Temperature & Light readings
EEPROM / Data Logger status
UART communication activity
🛠 Hardware Requirements
ATmega32
LM35 Temperature Sensor
LDR Sensor
16x2 LCD
Internal EEPROM
UART Interface (e.g. CH340 USB-to-Serial)
💻 Software Requirements
Microchip Studio / Atmel Studio
Proteus (simulation)
AVR-GCC
Git / GitHub
📚 Drivers Used
MCAL
ADC
GIE (Global Interrupt Enable)
EXTI
TIMER0 (Normal / CTC / PWM)
UART
LCD
HAL
LM35
LDR
EEPROM
LIB / Common
STD_TYPES.h
BIT_MATH.h
Common register-map / macros
📂 Project Structure
Weather_Station/
│
├── APP
│      main.c
│      Weather_Controller/
│      DataLogger/
│      AlarmManager/
│      Monitoring/
│      UART_Handler/
│
├── HAL
│      LCD/
│      LM35/
│      LDR/
│      EEPROM/
│
├── MCAL
│      ADC/
│      GIE/
│      EXTI/
│      TIMER0/
│      UART/
│
├── LIB
│      STD_TYPES.h
│      BIT_MATH.h
│
└── README.md

Each APP/HAL/MCAL module follows a consistent 4-file layout:

ModuleName/
   ModuleName_Config.h      -> configuration & tunable parameters
   ModuleName_Interface.h   -> public API exposed to other layers
   ModuleName_Private.h     -> internal macros / prototypes
   ModuleName_Program.c     -> implementation
🏗 Layered Architecture
   APP        -> Weather_Controller, DataLogger, AlarmManager, Monitoring, UART_Handler
    ↑
   HAL        -> LCD, LM35, LDR, EEPROM
    ↑
   MCAL       -> ADC, GIE, EXTI, TIMER0, UART
    ↑
   LIB/Common -> STD_TYPES, BIT_MATH

Each layer only calls the layer directly beneath it, keeping drivers reusable and hardware details isolated from application logic.

📈 Sampling Schedule

Implemented as a flag-based cooperative scheduler driven by Timer0 (1 ms tick):

Task	Period
Read Temperature	500 ms
Read Light Sensor	500 ms
Update LCD	1000 ms
Save Data (EEPROM)	5000 ms
Check Alarm	500 ms
UART Communication	Event Driven
💾 EEPROM Memory Layout
Address	Stored Data
0x0000	Record Counter
0x0002	Record 1 (3 bytes)
0x0005	Record 2 (3 bytes)
0x0008	Record 3 (3 bytes)
...	...

Each record occupies 3 bytes (Record ID + Temperature + Light), with a maximum of 60 records.

🚨 Alarm Conditions
Alarm	Condition
High Temperature	Temp > High Threshold
Low Temperature	Temp < Low Threshold
High Light	Light > High Threshold
Low Light	Light < Low Threshold
EEPROM Full	Record count = 60
🚀 Future Improvements
Humidity Sensor (DHT11/DHT22)
RTC Time Stamping for logged records
SD Card data logging
Wi-Fi / IoT cloud dashboard
Weather trend analysis
📖 Course Information

Embedded Systems Diploma

Topics Covered

Embedded C
AVR Architecture
ADC, LCD, EEPROM, UART
Timers & Interrupts
Driver Development
Layered Software Architecture
👥 Team
Name
Ali Mohamed Ramadan Elsotohy
Seif Alaa Abd El Fattah
Ahmed Sobhy Mohammed
Ahmed Ayman Fekry
👨‍💼 Team Leader

Eng. Hesham Ahmed

📜 License

This project was developed during the NTI Embedded Systems Training Program.

Licensed under the MIT License.

Project Organization: Gestell

🙏 Acknowledgment

Special thanks to:

National Telecommunications Institute (NTI)
Eng. Hesham Ahmed
Gestell Team

for their guidance and continuous support throughout this project.

⭐ Final Note

The Weather Monitoring & Data Logging Station demonstrates the core principles of embedded environmental monitoring by integrating real-time sensing, historical data storage, threshold-based alarm generation, and serial communication into a modular, layered embedded system.
