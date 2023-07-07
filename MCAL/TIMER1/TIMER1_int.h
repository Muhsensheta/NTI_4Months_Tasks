/*
 * TIMER1_int.h
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_


#define    FALLING_EDGE         0
#define    RAISING_EDGE         1


void M_TIMER1_void_Init();
void M_TIMER1_void_StartTime();
void M_TIMER1_void_DisableTime();
void M_TIMER1_void_SetTime();
void M_TIMER1_void_ICU_SetEdge(u8 Edge);
void M_TIMER1_void_ICU_EnableINT();
void M_TIMER1_void_ICU_DisableINT();
void M_TIMER1_SetCallBack(void(*Pf)());





#endif /* TIMER1_TIMER1_INT_H_ */
