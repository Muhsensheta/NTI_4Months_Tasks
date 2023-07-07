/*
 * VOLTMETER_main.c
 *
 *  Created on: ٠٥‏/٠٧‏/٢٠٢٣
 *      Author: houras
 */
#if (0)

#include <util/delay.h>

#include "STD_TYPES.h"
#include "DIO_init.h"
#include "SSD_init.h"
#include"PB_init.h"
#include "LCD_int.h"
#include "KEYPAD_init.h"
#include "EXT1_Init.h"
#include "EXT1_config.h"
#include "EXT0_int.h"
#include "GIE_int.h"
#include "ADC_Init.h"
#include "TIMER_int.h"
#include "TIMER_priv.h"
#include "TIMER1_priv.h"
#include "TIMER1_int.h"



 void ADC_INT();
 u16 Read=0;
 u8  LM_Read=0;
 int main()
 {


   H_LCD_void_Init();
   M_void_ADC_Init(prescaler128);
    SetCallback(ADC_INT);
    M_void_ADC_EnableInt();
   M_void_EXT0_INIT();
    M_void_EXT0_Enable(RAISING_EDGE_CHANGE);
   M_void_GIE_Enable();
M_DIO_void_SetPinDir(PORTD, PIN2, IN);


	 while (1)
	 {

		 /*Read=M_u16_ADC_Read(channel0);
			 Read *=(5000/1024);
			  H_LCD_void_gotXY(0 ,5);
			       H_LCD_void_sendIntNum(Read);
			       _delay_ms(500);*/


	 }

	return 0;
 }
 void ADC_INT()
 {
	 Read=M_u16_ADC_Read(channel0);
	 Read *=(5000/1024);
	 //LM_Read=Read/10;

	       H_LCD_void_sendIntNum(Read); //for LDR
          // H_LCD_void_sendIntNum(LM_Read); //for LM35
	       H_LCD_void_sendString(" mv");
	       _delay_ms(500);
	       H_LCD_void_clear();

 }


#endif

