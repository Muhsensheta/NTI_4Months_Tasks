/*
 * EXT0_prog.c
 *
 *  Created on: ١٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_init.h"
#include "EXT0_priv.h"
#include"EXT0_config.h"
#include "EXT0_int.h"


void (*ptr_fn0)()=NULL;

void M_void_EXT0_INIT()
{
	CLR_BIT(GICR_REG,INT0_BIT);
	SET_BIT(GIFR_REG,INTF0_BIT);
}
void M_void_EXT0_Enable(u8 Sense)
{
 SET_BIT(GICR_REG,INT0_BIT);
 switch (Sense)
 {
 case LOW_LEVEL_CHANGE:
	 CLR_BIT(MCUCR_REG,ISC00_BIT);
	 CLR_BIT(MCUCR_REG,ISC01_BIT);
   break;
 case ANY_LEVEL_CHANGE:
 	 SET_BIT(MCUCR_REG,ISC00_BIT);
 	 CLR_BIT(MCUCR_REG,ISC01_BIT);
    break;
 case RAISING_EDGE_CHANGE:
 	 SET_BIT(MCUCR_REG,ISC00_BIT);
 	 SET_BIT(MCUCR_REG,ISC01_BIT);
    break;
 case FALING_EDGE_CHANGE:
 	 CLR_BIT(MCUCR_REG,ISC00_BIT);
 	 SET_BIT(MCUCR_REG,ISC01_BIT);
    break;
 }
}
void M_void_EXT0_disable()
{
  CLR_BIT(GICR_REG,INT0_BIT);
}
void M_void_EXT0_SetCallback(void (*ptr)())
{

	   ptr_fn0=ptr;

}

void __vector_1 (void)__attribute__((signal));
void __vector_1 (void)
{
	 if (ptr_fn0 !=NULL)
	   {
		   ptr_fn0();
	   }
}

