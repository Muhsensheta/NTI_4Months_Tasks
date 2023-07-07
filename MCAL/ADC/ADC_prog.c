/*
 * ADC_prog.c
 *
 *  Created on: ١٧‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_Init.h"

void (*ADC_ptr)()={NULL};
void M_void_ADC_Init(Prescaller_t prescaler)
{
	//set vref
	//ADMUX_REG &= VREF_MASK;
	SET_BIT(ADMUX_REG,REF0_BIT);
	CLR_BIT(ADMUX_REG,REF1_BIT);
    // for  prescaller 128
	ADCSRA_REG &= PRESCALER_MASK;
	ADCSRA_REG |= prescaler;
	//Enable ADC
	SET_BIT(ADCSRA_REG,ADEN_BIT);
	SET_BIT(ADCSRA_REG,ADSC_BIT);//if you don't use auto trigger enable this bit
	//ENABLE AUTO TRIGGER
//	SET_BIT(ADCSRA_REG,ADATE_BIT);
	//select source for auto trigger(external interrupt)
	//SFIOR_REG &= SFIOR_MASK;
	//SFIOR_REG |=0b01011111;


}
u16  M_u16_ADC_Read  (Channel_t Channel)
{
	u16 Read;
	//for channel
	ADMUX_REG &=CHANNEL_MASK;
	ADMUX_REG |= Channel;

	//start conversion
	SET_BIT(ADCSRA_REG,ADSC_BIT);  //if you don't use auto trigger enable this bit
	//while(GET_BIT(ADCSRA_REG,ADSC_BIT)==1); //if you want to adjust adc by polling

	Read=ADCL_REG;
	return Read;
}
void  M_void_ADC_EnableInt()
{
 SET_BIT(ADCSRA_REG,ADIE_BIT);
}
void  M_void_ADC_DisableInt()
{
	CLR_BIT(ADCSRA_REG,ADIE_BIT);
}
void SetCallback( void(*Ptr_func)() )
{
	ADC_ptr = Ptr_func;
}
void __vector_16 (void)__attribute__((signal));
void __vector_16 (void)
{
	 if (ADC_ptr !=NULL)
	   {
		 ADC_ptr();
	   }
}

