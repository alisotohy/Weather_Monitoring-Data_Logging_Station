
#include "Timer0_Interface.h"

static uint8_t StaticPWMOutputMode = 0;
static void (*Timer0_OVFCallBack)(void)=Null;
static void (*Timer0_CTCCallBack)(void)=Null;
void TIMER0_Init(Timer0_Config_t Config)
{
    TCCR0_Reg = ClearRegister; 
    if(Config.TimerMode==Timer0_NormalMode)
    {
        ClearBit(TCCR0_Reg,Timer0_WGM00);
        ClearBit(TCCR0_Reg,Timer0_WGM01);
        TCNT0_Reg=Config.PreloadValue;
        SetBit(TIMSK_Reg,Timer0_TOIE0);
        
    }
    else if (Config.TimerMode==Timer0_CTCMode)
    {
        ClearBit(TCCR0_Reg,Timer0_WGM00);
        SetBit(TCCR0_Reg,Timer0_WGM01);
        OCR0_Reg=Config.CompareMatchValue;
        SetBit(TIMSK_Reg,Timer0_OCIE0);
    }
    else if (Config.TimerMode==Timer0_FastPWM)
    {
        SetBit(TCCR0_Reg,Timer0_WGM00);
        SetBit(TCCR0_Reg,Timer0_WGM01);
        if(Config.PWMOutputMode==Timer0_OC0NinInverting)
        {
            ClearBit(TCCR0_Reg,Timer0_COM00);
            SetBit(TCCR0_Reg,Timer0_COM01);
            StaticPWMOutputMode = Timer0_OC0NinInverting ;
        }
        else if (Config.PWMOutputMode==Timer0_OC0Inverting)
        {
            SetBit(TCCR0_Reg,Timer0_COM00);
            SetBit(TCCR0_Reg,Timer0_COM01);
            StaticPWMOutputMode = Timer0_OC0Inverting ;
        }
        OCR0_Reg = ClearRegister ; 
    }
    else if (Config.TimerMode==Timer0_PhaseCorrectPWM)
    {
        SetBit(TCCR0_Reg,Timer0_WGM00);
        ClearBit(TCCR0_Reg,Timer0_WGM01);
        if(Config.PWMOutputMode==Timer0_OC0NinInverting)
        {
            ClearBit(TCCR0_Reg,Timer0_COM00);
            SetBit(TCCR0_Reg,Timer0_COM01);
            StaticPWMOutputMode = Timer0_OC0NinInverting ;
        }
        else if(Config.PWMOutputMode==Timer0_OC0Inverting)
        {
            SetBit(TCCR0_Reg,Timer0_COM00);
            SetBit(TCCR0_Reg,Timer0_COM01);
            StaticPWMOutputMode = Timer0_OC0Inverting ;
        }
        OCR0_Reg = ClearRegister;
    }
}

void TIMER0_Start(uint8_t ClockSelectValue)
{
    if (ClockSelectValue!=Timer0_Disable)
    {
      TCCR0_Reg = (TCCR0_Reg &~ClockSelectMask)|ClockSelectValue;
    }
}

void TIMER0_Stop(void)
{   
    TCCR0_Reg = (TCCR0_Reg &~ClockSelectMask)|Timer0_Disable;
}

void TIMER0_SetPreload(uint8_t PreloadValue)
{
    TCNT0_Reg=PreloadValue;
}
void TIMER0_SetCompare(uint8_t CompareValue)
{
    OCR0_Reg=CompareValue;
}
void TIMER0_SetCallBack(uint8_t TimerInterruptType, void (*PF)(void))
{
    if(TimerInterruptType==Timer0_OverFlowInterrupt)
    {
      if(PF!=Null)
      {
        Timer0_OVFCallBack=PF;
      }  
    }
    else if (TimerInterruptType==Timer0_CompareMatchInterrupt)
    {
        if(PF!=Null)
        {
            Timer0_CTCCallBack=PF;
        }
    }
}
void TIMER0_SetPWM_DutyCycle(uint8_t DutyCyclePercentage )
{
    if(DutyCyclePercentage<=Timer0_MaxDutyCycle)
    {
        uint8_t LocalCompareValue = 0;
        if(StaticPWMOutputMode==Timer0_OC0NinInverting)
        {
            LocalCompareValue = (uint8_t)(((uint32_t)DutyCyclePercentage*Timer0_MaxPWM)/Timer0_MaxDutyCycle) ;
        }
        else if (StaticPWMOutputMode==Timer0_OC0Inverting)
        {
            LocalCompareValue = Timer0_MaxPWM - (uint8_t)((Timer0_MaxPWM*(uint32_t)DutyCyclePercentage)/Timer0_MaxDutyCycle) ; 
        }
        OCR0_Reg = LocalCompareValue ; 
    }
}

void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
    if(Timer0_CTCCallBack !=Null)
    {
    Timer0_CTCCallBack();
    }
}    
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
    if(Timer0_OVFCallBack !=Null)
    {
    Timer0_OVFCallBack();
    }
}