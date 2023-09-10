/*
 * TIMER.c
 *
 *  Created on: Aug 20, 2023
 *      Author: abdel
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "GIE.h"
#include <avr/io.h>
#include "TIMER.h"


void (*TIMER2_pvCallBackFunc)(void) = NULL;

void TIMER2_Init(void){
	//clear flag
	SET_BIT(TIFR, TIFR_OCF2);

	//CTC mode
	CLR_BIT(TCCR2, TCCR2_WGM20);
	SET_BIT(TCCR2, TCCR2_WGM21);

	//enable compare match
	SET_BIT(TIMSK, TIMSK_OCIE2);

	//Set compare match value
	OCR2 =125;

	SET_BIT(TIFR, TIFR_OCF2);
	//set prescalar mode //prescalar = 64
	SET_BIT(TCCR2, TCCR2_CS22);
	CLR_BIT(TCCR2, TCCR2_CS21);
	CLR_BIT(TCCR2, TCCR2_CS20);

}

void TIMER2_Disable(void){
	CLR_BIT(TIMSK, TIMSK_OCIE2);
}
u8 TIMER2_u8SetCallBack(void (*pvCallBackFunc_Copy)(void)){
	u8 u8ErrorStateLocal = OK;
	if(pvCallBackFunc_Copy !=NULL){
		TIMER2_pvCallBackFunc = pvCallBackFunc_Copy;
	}else{
		u8ErrorStateLocal = NULL_POINTER;
	}
	return u8ErrorStateLocal;
}

//Actual ISR timer2
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
	if(TIMER2_pvCallBackFunc != NULL){
		TIMER2_pvCallBackFunc();
	}
}
