/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : PWM		                    ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 5/9/2023		            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "GIE.h"
#include "TIMER.h"

#include "avr/io.h"

//call back function
void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_Init(void){
	// wave generation : Fast PWM mode
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	//non-inverted
	SET_BIT(TCCR0, TCCR0_COM01);
	CLR_BIT(TCCR0, TCCR0_COM00);

	//Set compare match value
	OCR0=0;

	// prescaler = 1024
	SET_BIT(TCCR0 , TCCR0_CS00);
	CLR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);
}

void TIMER0_PWM_voidSetTon(u8 ton){
	OCR0 = ton;
}

void TIMER0_PWM_voidIncreaseDutyCycle(void){
	if(OCR0 < 255)
		OCR0++;
}

void TIMER0_PWM_voidDecreaseDutyCycle(void){
	if(OCR0 > 0)
		OCR0--;
}

u8 TIMER0_u8SetCallBack(void (*pvCallBackFunc_Copy)(void)){
	u8 u8ErrorState_Local = OK;
	if(pvCallBackFunc_Copy != NULL){
		TIMER0_pvCallBackFunc = pvCallBackFunc_Copy ;
	}
	else{
		u8ErrorState_Local = NULL_POINTER;
	}
return u8ErrorState_Local ;

}
/*Actual ISR */
void __vector_10 (void)__attribute__((signal));
void __vector_10 (void){
	if (TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
