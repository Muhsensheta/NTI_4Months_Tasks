/*
 * TIMER1_prog.c
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_priv.h"
#include "TIMER1_config.h"
#include "TIMER1_int.h"

void (*Pf_Timer1)()={NULL};
void M_TIMER1_void_Init()
{
  //select normal mode
	TCCR1A &=0b11111100 ;
	TCCR1B &=0b11100111	;
}
void M_TIMER1_void_StartTime()
{
	SET_BIT(TCCR1B,1);

}
void M_TIMER1_void_DisableTime()
{
	TCCR1B&=0b11111000;
}
void M_TIMER1_void_SetTime()
{

}
void M_TIMER1_void_ICU_SetEdge(u8 Edge)
{
	switch (Edge)
	{
	case FALLING_EDGE :
		CLR_BIT(TCCR1B,ICES1_bit);
		break;
	case RAISING_EDGE :
		SET_BIT(TCCR1B,ICES1_bit);
		break;

	}
}
void M_TIMER1_void_ICU_EnableINT()
{
	SET_BIT(TIMSK,TICIE1_BIT);
}
void M_TIMER1_void_ICU_DisableINT()
{
	CLR_BIT(TIMSK,TICIE1_BIT);
}
void M_TIMER1_SetCallBack(void(*Pf)())
 {
	Pf_Timer1= Pf;
 }

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
 {
	 if (*Pf_Timer1 != NULL)
	   {
		 Pf_Timer1();
	   }
 }


