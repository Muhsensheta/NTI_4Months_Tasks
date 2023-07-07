/*
 * ADC_priv.h
 *
 *  Created on: ١٧‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef ADC_ADC_PRIV_H_
#define ADC_ADC_PRIV_H_

#define ADMUX_REG      *((volatile u8*)0x27)
#define MUX0_BIT    0
#define MUX1_BIT    1
#define MUX2_BIT    2
#define MUX3_BIT    3
#define MUX4_BIT    4
#define ADLAR_BIT   5
#define REF0_BIT    6
#define REF1_BIT    7

/******************* ADCSRA REG**********************/
#define ADCSRA_REG     *((volatile u8*)0x26)
#define ADPS0_BIT    0
#define ADPS1_BIT    1
#define ADPS2_BIT    2
#define ADIE_BIT    3
#define ADIF_BIT    4
#define ADATE_BIT   5
#define ADSC_BIT    6
#define ADEN_BIT    7
/*****************SFIOR REG***********************/
#define SFIOR_REG     *((volatile u8*)0x50)


#define ADCL_REG      *((volatile u16*)0x24)
#define ADCH_REG       *((volatile u8*)0x25)

#define  PRESCALER_MASK  0b11111000
#define  VREF_MASK  0b00111111
#define  CHANNEL_MASK  0b11100000
#define SFIOR_MASK     0b00011111





#endif /* ADC_ADC_PRIV_H_ */
