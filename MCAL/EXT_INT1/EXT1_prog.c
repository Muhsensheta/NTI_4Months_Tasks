/*
 * EXT1_prog.c
 *
 *  Created on: ١٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_init.h"
#include "EXT1_priv.h"
#include"EXT1_config.h"
#include "EXT1_Init.h"


void (*ptr_fn)()=NULL;

void M_void_EXT1_INIT()
{
	CLR_BIT(GICR_REG,INT1_BIT);
	SET_BIT(GIFR_REG,INTF1_BIT);
}
void M_void_EXT1_Enable(u8 Sense)
{
 SET_BIT(GICR_REG,INT1_BIT);
 switch (Sense)
 {
 case LOW_LEVEL_CHANGE:
	 CLR_BIT(MCUCR_REG,ISC10_BIT);
	 CLR_BIT(MCUCR_REG,ISC11_BIT);
   break;
 case ANY_LEVEL_CHANGE:
 	 SET_BIT(MCUCR_REG,ISC10_BIT);
 	 CLR_BIT(MCUCR_REG,ISC11_BIT);
    break;
 case RAISING_EDGE_CHANGE:
 	 SET_BIT(MCUCR_REG,ISC10_BIT);
 	 SET_BIT(MCUCR_REG,ISC11_BIT);
    break;
 case FALING_EDGE_CHANGE:
 	 CLR_BIT(MCUCR_REG,ISC10_BIT);
 	 SET_BIT(MCUCR_REG,ISC11_BIT);
    break;
 }
}
void M_void_EXT1_disable()
{
  CLR_BIT(GICR_REG,INT1_BIT);
}
void M_void_EXT1_SetCallback(void (*ptr)())
{

	   ptr_fn=ptr;

}

void __vector_2 (void)__attribute__((signal));
void __vector_2 (void)
{
	 if (ptr_fn !=NULL)
	   {
		   ptr_fn();
	   }
}


