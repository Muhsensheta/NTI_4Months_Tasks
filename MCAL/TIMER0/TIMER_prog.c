/*
 * TIMER_prog.c
 *
 *  Created on: ١٨‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"TIMER_priv.h"
#include "TIMER_config.h"
#include "TIMER_int.h"

static u32 OVF_Countnums=0;
static u32 OVF_CountRemainders=0;

void (*PF_Timer)(void)=NULL;

void M_TIMER0_void_Init()
{
#if (TIMER0_MODE == TIMER0_NORMAL_MODE)

	CLR_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);


#elif (TIMER0_MODE == TIMER0_CTC_MODE)
#elif (TIMER0_MODE == TIMER0_FAST_PWM_MODE)

	SET_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);


	//select Non inverting mode
	SET_BIT(TCCR0_REG,COM01_BIT);
	CLR_BIT(TCCR0_REG,COM00_BIT);
#elif (TIMER0_MODE == TIMER0_PHASECORRECT_MODE)

#endif

}
void M_TIMER0_void_StartTIME()
{
 TCCR0_REG &= TIMER0_PRESCALER_MASK;
 TCCR0_REG |= 0b00000010;
}
void M_TIMER0_void_StopTIME()
{
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
}
void M_TIMER0_void_SetTIME_MS(u32 Desired_timeMS)
{
 f32 tick_t =0;
 f32 OVF_t =0;
 tick_t=(f32)(TIMER0_PRESCALLER/16);
 OVF_t=(tick_t*256);
 u32  NoOfDesiredTicks=(Desired_timeMS*1000)/tick_t;
  OVF_Countnums= NoOfDesiredTicks/256;
  OVF_CountRemainders =NoOfDesiredTicks%256;
  if (OVF_CountRemainders != 0)
   {
	  TCNT0_REG  = 256-OVF_CountRemainders;
	  OVF_Countnums ++;
   }


}
void M_TIMER0_void_SetFastPWM(u8  Duty)
{
	u8 Compare_val=((float)Duty/100)*256;
	OCR0_REG=Compare_val;
}

void M_TIMER0_void_EnableINT()
{
   SET_BIT(TIMSK_REG,TOIE0_BIT);
}
void M_TIMER0_void_DisableINT()
{
	 CLR_BIT(TIMSK_REG,TOIE0_BIT);
}
void M_TIMER0_SetCallBack(void(*Pf)())
 {
	PF_Timer=Pf;
 }

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
 {
	 if (PF_Timer !=NULL)
	   {
		 PF_Timer();
	   }
 }

