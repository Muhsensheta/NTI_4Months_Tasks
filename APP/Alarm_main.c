/*
 * Alarm_main.c
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

u8 Alarm = 0;
void EXTI0_ISR(void);
void EXTI1_ISR(void);

u8 Welcome[]="Adjust Alarm";

u8 SystemState=0 ;
u8 Reading = 0xFF;


void alarm_init(void)
{
		/*LCD control*/
		M_DIO_void_SetPinDir(PORTA ,PIN5 ,OUT);
		M_DIO_void_SetPinValue(PORTA , PIN5 ,LOW);

		/*Buzzer*/
		M_DIO_void_SetPinDir(PORTC ,PIN6 , OUT);
		M_DIO_void_SetPinValue(PORTC , PIN6 ,LOW);

		M_DIO_void_SetPinDir(PORTD ,PIN2 , IN);
		M_DIO_void_SetPinValue(PORTD , PIN2 ,HIGH);

		H_LCD_void_Init();
		H_KP_void_init();

		M_void_EXT0_SetCallback(&EXTI0_ISR);
		M_void_EXT0_Enable(RAISING_EDGE);


		M_void_EXT1_SetCallback(&EXTI1_ISR);
		M_void_EXT1_Enable(RAISING_EDGE);

		M_void_GIE_Enable();
}


void alarm_run(void)
{


	  while(1)
	  {
		  while(Reading != 'f')
		  {
			  do
			  {
				  Reading = H_KP_u8_GetPressedKey();
			  }while (Reading == 0xFF);
			  H_LCD_void_sendIntNum(Reading);
			  if (Reading != 'f')
				Alarm = (Alarm*10) + Reading ;
		  }
		  H_LCD_void_sendCommand(0x01);
		  while(Alarm !=0 && SystemState == 1)
		  {
			  Alarm-- ;
			  _delay_ms(1000);
			  H_LCD_void_sendCommand(0x01);
			  H_LCD_void_sendIntNum(Alarm);
		  }
		  while (Alarm == 0 && SystemState == 1 )
		  {
			  M_DIO_void_SetPinValue(PORTC ,PIN6 ,HIGH);
		  }


	  }
}
int main(void)
{

	alarm_init();
	alarm_run();

}

void EXTI0_ISR(void)
{
	u8 static flag = 1 ;
	if (flag == 1)
	{
		M_DIO_void_SetPinValue(PORTA , PIN5 ,HIGH);
		flag = 0;
		H_LCD_void_sendCommand(0x01);
		H_LCD_void_gotXY(0,0);
		H_LCD_void_sendString("WELCOM");
		H_LCD_void_gotXY(1,0);
		SystemState = 1;
		Alarm = 0;
	}
	else if(flag == 0)
	{
		H_LCD_void_sendCommand(0x01);
		M_DIO_void_SetPinValue(PORTA , PIN5 , LOW);
		flag = 1;
		M_DIO_void_SetPinValue(PORTC , PIN6 ,LOW);
		SystemState = 0;
		Reading = 0xFF;
	}
}

void EXTI1_ISR(void)
{
	TOG_BIT(SystemState , 0);
}
#endif

