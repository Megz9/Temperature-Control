/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : GIE		                    ***********/
/***********	Version   : 2.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#include "BIT_MATH.h"
#include "avr/io.h"
#include "GIE.h"


void GIE_Enable(void){
	//Set bit 7 in SREG
	SET_BIT(SREG,SREG_I);
}
void GIE_Disable(void){
	//CLR bit 7 in SREG
	CLR_BIT(SREG,SREG_I);

}

