#include "GIE_INTERFACE.h"

#include <stdint.h>

void GIE_Enable()
{
    SetBit(SREG_Reg,I_Bit);
}
void GIE_Disable()
{
    ClearBit(SREG_Reg,I_Bit);
}