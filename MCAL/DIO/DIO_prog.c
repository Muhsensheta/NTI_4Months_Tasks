/*
 * DIO_prog.c
 *
 *  Created on: ١٠‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_init.h"


void M_DIO_void_SetPinDir  (u8 port,PIN_T pin ,u8 dir)
{
	switch(port)
	{
	case PORTA :
		switch(dir)
		{
		case IN:
			CLR_BIT(DDRA,pin);
			break;
		case OUT:
			SET_BIT(DDRA,pin);
			break;
		}
		break;
	case PORTB :
		switch(dir)
		{
		case IN:
			CLR_BIT(DDRB,pin);
			break;
		case OUT:
			SET_BIT(DDRB,pin);
			break;
		}
		break;
	case PORTC :
		switch(dir)
		{
		case IN:
			CLR_BIT(DDRC,pin);
			break;
		case OUT:
			SET_BIT(DDRC,pin);
			break;
		}
		break;
	case PORTD :
		switch(dir)
		{
		case IN:
			CLR_BIT(DDRD,pin);
			break;
		case OUT:
			SET_BIT(DDRD,pin);
			break;
		}
		break;
	}

}
void M_DIO_void_SetPinValue(u8 port,PIN_T pin ,u8 val)
{
	switch(port)
		{
		case PORTA :
			switch(val)
			{
			case LOW:
				CLR_BIT(PORTA_REG,pin);
				break;
			case HIGH:
				SET_BIT(PORTA_REG,pin);
				break;
			}
			break;
		case PORTB :
			switch(val)
			{
			case LOW:
				CLR_BIT(PORTB_REG,pin);
				break;
			case HIGH:
				SET_BIT(PORTB_REG,pin);
				break;
			}
			break;
		case PORTC :
			switch(val)
			{
			case LOW:
				CLR_BIT(PORTC_REG,pin);
				break;
			case HIGH:
				SET_BIT(PORTC_REG,pin);
				break;
			}
			break;
		case PORTD :
			switch(val)
			{
			case LOW:
				CLR_BIT(PORTD_REG,pin);
				break;
			case HIGH:
				SET_BIT(PORTD_REG,pin);
				break;
			}
			break;
		}


}
void M_DIO_void_TogPinValue(u8 port,PIN_T pin )
{
	switch (port){
			case PORTA:
				TOG_BIT(PORTA_REG,pin);
				break;
			case PORTB:
				TOG_BIT(PORTB_REG,pin);
				break;
			case PORTC:
				TOG_BIT(PORTC_REG,pin);
				break;
			case PORTD:
				TOG_BIT(PORTD_REG,pin);
				break;
			}


}
u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorStatus = 0 ;

	/*if the port is selected as output*/
	if (Copy_u8Direction == 0xFF)
	{
		switch(Copy_u8Port)
		{
			case PORTA : DDRA = 0xFF ;				break;		/*set port A*/
			case PORTB : DDRB = 0xFF ;				break;		/*set port B*/
			case PORTC : DDRC = 0xFF ;				break;      /*set port C*/
			case PORTD : DDRD = 0xFF ;				break;      /*set port D*/
			default 	   : Local_u8ErrorStatus = 1 ;	break;      /*the port parameter is invalid*/
		}
	}
	/*if the port is selected as input*/
	else if (Copy_u8Direction == 0x00)
	{
		switch(Copy_u8Port)
		{                                                               /*Clear port A*/
			case PORTA : DDRA = 0x00 ;					break;      /*Clear port B*/
			case PORTB : DDRB = 0x00 ;					break;		/*Clear port C*/
			case PORTC : DDRC = 0x00 ;					break;      /*Clear port D*/
			case PORTD : DDRD = 0x00 ;					break;      /*the port parameter is invalid*/
			default 	   : Local_u8ErrorStatus = 1 ; 		break;
		}
	}
	/*if the parameter invalid*/
	else
	{
			Local_u8ErrorStatus = 1 ;
	}
	return Local_u8ErrorStatus ;
}




u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8ErrorStatus = 0 ;

	switch(Copy_u8Port)
		{
			case PORTA : DDRA = Copy_u8Value ;		break;		/*set the value to the port A*/
			case PORTB : DDRB = Copy_u8Value ;		break;		/*set the value to the port B*/
			case PORTC : DDRC = Copy_u8Value ;		break;      /*set the value to the port C*/
			case PORTD : DDRD = Copy_u8Value ;		break;      /*set the value to the port D*/
			default 	   : Local_u8ErrorStatus = 1 ;	break;      /*the port parameter is invalid*/
		}
	return Local_u8ErrorStatus ;
}


void M_DIO_void_GetPinValue(u8 port,PIN_T pin ,u8 *pval)
{
	switch (port)
	{
	case PORTA:
	  *pval=GET_BIT(PINA_REG,pin);
	   break;
	case PORTB:
	  *pval=GET_BIT(PINB_REG,pin);
	   break;
	case PORTC:
		  *pval=GET_BIT(PINC_REG,pin);
		   break;
	case PORTD:
		  *pval=GET_BIT(PIND_REG,pin);
		   break;
	}
}

