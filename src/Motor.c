/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : HAL     	                ***********/
/***********	Component : Motor                       ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 5/9/2023		            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "TIMER.h"

#include "external_peripherals.h"
#include "Motor.h"

#include <avr/io.h>

void Motor_voidInit(void){
	/*Define motor ports as output*/
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_EN1,DIO_OUTPUT);
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_IN1,DIO_OUTPUT);
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_IN2,DIO_OUTPUT);
	/*adjust direction to be clockwise at the beginning*/
	Motor_RotateClockWise();

	/*start with speed = 0*/
	TIMER0_PWM_voidSetTon(0);
	RELAY_voidInit();
}
void Motor_speedUp(void){
	openRELAY();
	TIMER0_PWM_voidIncreaseDutyCycle();
}
void Motor_speedDown(void){
	openRELAY();
	TIMER0_PWM_voidDecreaseDutyCycle();
}
void Motor_stop(void){
	TIMER0_PWM_voidSetTon(0);
	closeRELAY();
}
void Motor_RotateClockWise(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_IN2,DIO_LOW);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_IN1,DIO_HIGH);
}
void Motor_RotateAntiClockWise(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_IN1,DIO_LOW);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_IN2,DIO_HIGH);
}
