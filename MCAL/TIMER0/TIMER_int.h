/*
 * TIMER_int.h
 *
 *  Created on: ١٨‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER_TIMER_INT_H_
#define TIMER_TIMER_INT_H_

void M_TIMER0_void_Init();
void M_TIMER0_void_StartTIME();
void M_TIMER0_void_StopTIME();
void M_TIMER0_void_SetTIME_MS(u32 Desired_timeMS);
void M_TIMER0_void_SetFastPWM(u8  Duty);

void M_TIMER0_void_EnableINT();
void M_TIMER0_void_DisableINT();
void M_TIMER0_SetCallBack(void(*Pf_timer)());





#endif /* TIMER0_TIMER_INT_H_ */
