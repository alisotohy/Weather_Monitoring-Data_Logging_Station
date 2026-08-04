

#include "UART_Handler_Interface.h"
#include <string.h>

/* UART configuration */
static Uart_Config_t UART_Config;

static uint8_t Command[UART_COMMAND_LENGTH];
static uint8_t CommandIndex = 0;


void UARTManager_Init(void)
{
    /* Configure UART */
    UART_Config.ModeSelect          = Uart_AsynchronousMode;
    UART_Config.StopBitSelect       = Uart_1StopBit;
    UART_Config.ParitySelect        = Uart_ParityDisabled;
    UART_Config.SizeCharacterSelect = Uart_8BitSize;
    UART_Config.SpeedMode           = Uart_NormalSpeed;
    UART_Config.BaudRate            = 9600;
    UART_Config.InterruptSelect     = Uart_InterruptDisabled;
    UART_Config.EnbaleSelect        = Uart_EnableRxAndTx;

    UART_Init(UART_Config);
}

/* ======================================================
   Send Current Weather Data
   ====================================================== */
void UARTManager_SendCurrentData(uint8_t Temp, uint8_t Light, uint8_t Alarm)
{
    UART_SendStringPolling((uint8_t*)"Current Data\r\n");

    UART_SendStringPolling((uint8_t*)"Temp = ");
    UART_SendBytePolling((Temp / 10) + '0');
    UART_SendBytePolling((Temp % 10) + '0');
    UART_SendStringPolling((uint8_t*)" C\r\n");

    UART_SendStringPolling((uint8_t*)"Light = ");
    UART_SendBytePolling((Light / 10) + '0');
    UART_SendBytePolling((Light % 10) + '0');
    UART_SendStringPolling((uint8_t*)" %\r\n");

    if(Alarm)
    {
        UART_SendStringPolling((uint8_t*)"Alarm = ON\r\n");
    }
    else
    {
        UART_SendStringPolling((uint8_t*)"Alarm = OFF\r\n");
    }
}


void UARTManager_Task(void)
{
    uint8_t ReceivedByte = 0;

    if (ReadBit(UCSRA_Reg, Uart_RXC) == 1)  
    {
        ReceivedByte = UDR_Reg; 

        // لو المستخدم ضغط Enter أو وصلنا لآخر حاجة مسموح بها
        if ((ReceivedByte == '\r') || (ReceivedByte == '\n') || (CommandIndex >= (UART_COMMAND_LENGTH - 1)))
        {
            Command[CommandIndex] = '\0'; // ختم الأمر

            // لو الأمر مش فاضي، اشتغل عليه
            if (CommandIndex > 0)
            {
                // ========== مقارنة الأوامر ==========
                if (strcmp((char*)Command, CMD_HELP) == 0)
                {
                    UART_SendStringPolling((uint8_t*)"HELP\r\nSTATUS\r\nCURRENT\r\nREAD LOG\r\nCLEAR LOG\r\n");
                }
                else if (strcmp((char*)Command, CMD_CLEAR_LOG) == 0)
                {
                    DataLogger_Clear();
                    UART_SendStringPolling((uint8_t*)"LOG CLEARED\r\n");
                }
                // ======================================
                // باقي الأوامر (STATUS, CURRENT, READ LOG) 
                // هتضيفها هنا لما تكملها
                // ======================================
            }

            // امسح البايفر عشان الأمر الجاي
            CommandIndex = 0;
        }
        else
        {
            // خزن الحرف في البايفر
            Command[CommandIndex] = ReceivedByte;
            CommandIndex++;
        }
    }
    // لو مفيش بايت، الدالة بتخلص في أجزاء من الميكروثانية (مش بتقف)
}