/*
 * ADC_Init.h
 *
 *  Created on: ١٧‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef ADC_ADC_INIT_H_
#define ADC_ADC_INIT_H_

typedef enum {
	channel0,channel1,channel2,channel3,channel4,channel5,channel6,channel7
}Channel_t;

typedef enum {
	prescaler2=1,prescaler4,prescaler8,prescaler16,prescaler32,prescaler64,prescaler128
}Prescaller_t;

typedef enum {
	AREF,AVCC,VIN=3
}Vref_t;

void M_void_ADC_Init(Prescaller_t prescaler);
u16  M_u16_ADC_Read  (Channel_t Channel);
void  M_void_ADC_EnableInt();
void  M_void_ADC_DisableInt();
void SetCallback( void(*Ptr_fun)() );


#endif /* ADC_ADC_INIT_H_ */
