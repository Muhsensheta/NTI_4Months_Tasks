/*
 * PIANO_main.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٣
 *      Author: houras
 */

#if (1)

#include <util/delay.h>
#include "BIT_MATH.h"
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


 u8 Read=0xff;

 int main()
 {


  // H_LCD_void_Init();

	 M_DIO_void_SetPinDir(PORTB, PIN3, OUT);
	 M_DIO_void_SetPinDir(PORTC, PIN6, OUT);
	 M_DIO_void_SetPinDir(PORTB, PIN7, OUT);


   H_KP_void_init();
   M_TIMER0_void_Init();
 //  M_TIMER0_void_SetFastPWM(25);
   M_TIMER0_void_StartTIME();
   M_void_GIE_Enable();
   //M_DIO_void_SetPinValue(PORTA, PIN4, HIGH);
	 //TCNT0_REG=247;


	 while (1)
	 {
		// H_SSD_void_display(Counter2);
     do {
           Read=H_KP_u8_GetPressedKey();

        }while(Read== 0xff);

	 // Read=H_KP_u8_GetPressedKey();
	  if(Read==1)
	  {
	   M_TIMER0_void_SetFastPWM(25);
	   _delay_ms(500);
	    }
	    else if(Read==2)
	    {
	   M_TIMER0_void_SetFastPWM(50);
	   _delay_ms(500);
	    }
	    else if(Read==3)
	    {
	   M_TIMER0_void_SetFastPWM(75);
	    _delay_ms(500);
	    }
	    else if(Read==4)
	   	{
	    M_TIMER0_void_SetFastPWM(100);
	    _delay_ms(500);
	    }



	 }

	return 0;
 }

#endif
