#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H
//FOR REG ADMUX
#define ADC_REFS1          7
#define ADC_REFS0          6
#define ADC_ADLAR          5
#define ADC_MUX4           4
#define ADC_MUX3           3
#define ADC_MUX2           2
#define ADC_MUX1           1
#define ADC_MUX0           0
 
#define ADC_RightAdjust    0
#define ADC_LeftAdjust     1
 
 
//FOR REG ADCSRA
#define ADC_ADEN           7
#define ADC_ADSC           6
#define ADC_ADATE          5
#define ADC_ADIF           4
#define ADC_ADIE           3
#define ADC_ADPS2          2
#define ADC_ADPS1          1
#define ADC_ADPS0          0
 
#define ADC_DivisionFactor2         2
#define ADC_DivisionFactor4         4
#define ADC_DivisionFactor8         8
#define ADC_DivisionFactor16        16
#define ADC_DivisionFactor32        32
#define ADC_DivisionFactor64        64
#define ADC_DivisionFactor128       128
 
 
#define ADC_AREF           0
#define ADC_AVCC           1
#define ADC_Internal       2
 
//FOR CHANNEL
#define ADC_SingleEndedChannel0       0
#define ADC_SingleEndedChannel1       1
#define ADC_SingleEndedChannel2       2
#define ADC_SingleEndedChannel3       3
#define ADC_SingleEndedChannel4       4
#define ADC_SingleEndedChannel5       5
#define ADC_SingleEndedChannel6       6
#define ADC_SingleEndedChannel7       7
 
 
#define ADC_ChannelMask     0x1F
 




#endif