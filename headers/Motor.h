/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : HAL     	                ***********/
/***********	Component : Motor                       ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 5/9/2023		            ***********/
/******************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#define MOTOR_PORT         DIO_PORTB

#define MOTOR_IN1          DIO_PIN1
#define MOTOR_IN2          DIO_PIN2
#define MOTOR_EN1          DIO_PIN3

void Motor_voidInit(void);
void Motor_speedUp(void);
void Motor_speedDown(void);
void Motor_stop(void);
void Motor_RotateClockWise(void);
void Motor_RotateAntiClockWise(void);

#endif /* MOTOR_H_ */
