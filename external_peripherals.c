/*
 * leds.c
 *
 *  Created on: Sep 7, 2023
 *      Author: Eng.Abdelrhman
 */
#include "STD_TYPES.h"
#include "DIO.h"

#include "external_peripherals.h"

#include "util/delay.h"

void RELAY_voidInit(void){
	//configure relay pin as output
	DIO_SetPinDirection(RELAY_PORT, RELAY_PIN, DIO_OUTPUT);

	//normally opened
	DIO_SetPinValue(RELAY_PORT, RELAY_PIN, DIO_LOW);

}
void LEDS_voidInit(void){
	/*initialize led pins as output*/
	DIO_SetPinDirection(RED_LED_PORT, RED_LED_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, DIO_OUTPUT);

	/*start lighting up green led to indicate system starting well*/
	GreenLedON();
}

void BUZZER_voidInit(void){
	/*set buzzer pin as output*/
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);
}


void openRELAY(void){
	DIO_SetPinValue(RELAY_PORT, RELAY_PIN, DIO_HIGH);
}
void closeRELAY(void){
	DIO_SetPinValue(RELAY_PORT, RELAY_PIN, DIO_LOW);
}
void closeBuzzer(void){
	DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_LOW);
}

void openBuzzer(void){
	DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_HIGH);
}

void useBuzzer(u8 toggleNumber){
	for(int i=0;i<toggleNumber;i++){
		DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_HIGH);
		_delay_ms(500);
		DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_LOW);
		_delay_ms(500);
	}
}
void GreenLedOFF(void){
	DIO_SetPinValue(DIO_PORTD, DIO_PIN4, DIO_LOW);
}
void GreenLedON(void){
	DIO_SetPinValue(DIO_PORTD, DIO_PIN4, DIO_HIGH);
}

void RedLedOFF(void){
	DIO_SetPinValue(DIO_PORTD, DIO_PIN5, DIO_LOW);
}

void RedLedON(void){
	DIO_SetPinValue(DIO_PORTD, DIO_PIN5, DIO_HIGH);
}
void RedLedBlink(void){
	DIO_TogglePin(DIO_PORTD,DIO_PIN5);
}
