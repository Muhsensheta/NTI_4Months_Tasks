/*
 * WaterLevel.c
 *
 *  Created on: ٠٥‏/٠٧‏/٢٠٢٣
 *      Author: houras
 */
#if (0)

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

 void ADC_INT();
 u16 Read=0;

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
M_DIO_void_SetPinDir(PORTC,PIN6, OUT);


	 while (1)
	 {
		 if (Read <= 3000 )
		 		{
		 			H_LCD_void_gotXY(0,0);
		 			H_LCD_void_sendString("NO WATER");
		 			DIO_u8SetPortDirection(PORTC < PIN6 ,LOW);
		 		}
		 		else if (Read <= 4750 )
		 		{
		 			H_LCD_void_gotXY(0,0);
		 			H_LCD_void_sendString("WATER LEVEL");
		 			H_LCD_void_sendIntNum(1);
		 			DIO_u8SetPortDirection(PORTC < PIN6 ,LOW);
		 		}
		 		else if (Read <= 4800)
		 		{
		 			H_LCD_void_gotXY(0,0);
		 			H_LCD_void_sendString("WaterLevel");
		 			H_LCD_void_sendIntNum(2);
		 			DIO_u8SetPortDirection(PORTC <PIN6 ,LOW);
		 		}
		 		else if (Read <= 4900)
		 		{
		 			H_LCD_void_gotXY(0,0);
		 			H_LCD_void_sendString("WaterLevel");
		 			H_LCD_void_sendIntNum(4);
		 			DIO_u8SetPortDirection(PORTC <PIN6 ,LOW);
		 		}
		 		else if (Read <= 4950)
		 		{
		 			H_LCD_void_gotXY(0,0);
		 			H_LCD_void_sendString("WaterLevel");
		 			H_LCD_void_sendIntNum(5);
		 			DIO_u8SetPortDirection(PORTC <PIN6 ,LOW);
		 		}
	 }

	return 0;
 }
 void ADC_INT()
 {
	 Read=M_u16_ADC_Read(channel1);
	 Read *=(5000/1024);
	       _delay_ms(500);


 }

#endif


