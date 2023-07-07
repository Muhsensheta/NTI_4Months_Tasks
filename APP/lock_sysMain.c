/*
 * lock_sysMain.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٣
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

//u8 Read;
u8  key;

void GetEntry();
u8 Chek_pass();

u8 UsserPASS[5] ;
u8 PassArr[5]={1,2,3,4,5};
int main()
{
	//H_SSD_void_Init();
	H_void_PB1_init();
	H_LCD_void_Init();
	H_KP_void_init();
	//M_DIO_void_SetPinDir(PORTA, PIN4, OUT);

   u8 check;

  // GetEntry();
   check=Chek_pass();
   while(!check)
   {
	   if (check ==0)
	   {
		   H_LCD_void_sendString("SYSTEM HOLD");
		   _delay_ms(5000);
		   H_LCD_void_clear();

		   H_LCD_void_sendString("Rentre pass");
		   _delay_ms(500);


	   }
	   check=Chek_pass();

   }
	//key=H_KP_u8_GetPressedKey();
	while (1)
	{
		//H_LCD_void_sendString("KEY IS");
		//_delay_ms(500);

		//H_LCD_void_clear();

		//_delay_ms(500);
	//	key=H_KP_u8_GetPressedKey();
       /*if (key!=0xff)
       {
    	   H_LCD_void_sendIntNum(key);
		_delay_ms(500);
       }*/
       H_LCD_void_gotXY(1, 5);
		H_LCD_void_sendString("WELCOM");
		 H_LCD_void_gotXY(0, 5);
		 H_LCD_void_sendData('2');


	}

return 0;
}

void GetEntry()
{
	u8 i,VAL;

	for(i=0;i<5;i++)
	{
		VAL=H_KP_u8_GetPressedKey();
		while(VAL==0xff){
			VAL=H_KP_u8_GetPressedKey();
		}

		if (  VAL != 0xff )
		{
			UsserPASS[i]=VAL;
			H_LCD_void_sendString("*");


		}

	}
H_LCD_void_clear();

}
 u8 Chek_pass()
{
	u8 i,try_num=0;
	u8 flag=1;
	do{
		GetEntry();
		flag=1;
		for(i=0;i<5;i++){
			if(UsserPASS[i] !=PassArr[i])
			{
				H_LCD_void_sendString("WRONG PASS");
				_delay_ms(200);
				H_LCD_void_clear();
				H_LCD_void_sendString("PLEASE RE ENTER PASS");
				_delay_ms(200);
				H_LCD_void_clear();
				try_num++;
				flag=0;
				break;
			}

		}
	}while((flag==0)&&(try_num<3));

	return flag;
}
#endif




