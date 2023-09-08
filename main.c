#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "ACD.h"
#include "GIE.h"
#include "TIMER.h"
#include "EXTI.h"
#include "USART.h"

#include "Motor.h"
#include "CLCD.h"
#include "voltageTempMapping.h"
#include "external_peripherals.h"

#include "avr/io.h"
#include "stdlib.h"
#include "util/delay.h"
#include "math.h"

/*range from 15 to 75 excluded*/
#define UPPER_LIMIT     75
#define LOWER_LIMIT     15


void EXTI_ISR(void);
void TIMER2_ISR(void);
void systemFailure(void);
void printCurrentTemp(void);
void main_Function(void);


u16 desiredTemp = 25; /*represent desired temp on the system*/
u16 ADC_currentTemp; /*variable to take sensor readings*/
u8 buf[3];          /*helpful string buffer*/


void main(){
	LEDS_voidInit();
	BUZZER_voidInit();

	GIE_Enable();
	TIMER0_Init();

	TIMER2_u8SetCallBack(&TIMER2_ISR);

	ADC_Init();
	Motor_voidInit();

	initExternalInterrupt();
	EXTI0_u8SetCallBack(&EXTI_ISR);


	CLCD_voidInit();

	/*delay 1s until first conversion fully done*/
	_delay_ms(1000);
	/*get sensor readings*/
	printCurrentTemp();

	/*if system temperature exceeds upper limit, the system goes into failure state*/
	if(ADC_currentTemp > UPPER_LIMIT){
		systemFailure();
	}else{
		/*print desired temp at the beginning*/
		CLCD_voidMoveCursor(2, 1);
		CLCD_voidSendString("Desired: ");
		itoa(desiredTemp, buf,10);
		CLCD_voidSendString(buf);
	}

	while(1){
		main_Function();
	}
}

void main_Function(void){
	u8 ADC_prevTemp = ADC_currentTemp; //record last temperature
	/*take new readings*/
	ADC_currentTemp=ADC_Read(0);
	ADC_currentTemp = getTemp(ADC_currentTemp);

	if(desiredTemp > ADC_currentTemp ){
		Motor_speedUp(); //take an action by increasing motor speed
		while(1){
			if(desiredTemp <= ADC_currentTemp){
				printCurrentTemp();
				Motor_stop(); //stop motor as the desired temp had been reached
				break;
			}
			/*if the temp changed but not reached desired temp yet*/
			if(ADC_currentTemp != ADC_prevTemp){
				printCurrentTemp();

				if(ADC_currentTemp > UPPER_LIMIT){
					systemFailure(); //system goes into failure
					break;
				}
				Motor_speedUp(); //since desired temp had not been reached yet, then take an action
			}
			//take the sensor new readings
			ADC_prevTemp = ADC_currentTemp;
			ADC_currentTemp=ADC_Read(0);
			ADC_currentTemp = getTemp(ADC_currentTemp);
		}
	}else if(desiredTemp < ADC_currentTemp){
		u8 flag = 0;     //to indicate that the motor is rotating anti clock-wise
		Motor_speedDown(); //decrease motor speed
		//check if there is a need to reverse motor direction to reach desired temperature
		if(OCR0 == 0){
			flag = 1;
			Motor_RotateAntiClockWise();
			Motor_speedUp(); //increase the speed at the reverse direction
		}

		while(1){

			if(desiredTemp >= ADC_currentTemp){
				printCurrentTemp();
				Motor_stop();
				Motor_RotateClockWise(); //re-adjust rotation direction
				break;
			}
			if(ADC_currentTemp != ADC_prevTemp){
				printCurrentTemp();
				if(ADC_currentTemp > UPPER_LIMIT){
					systemFailure();
					break;
				}
				if(flag){
					//speed up in the anti-clockwise direction
					Motor_speedUp();
				}else{
					Motor_speedDown();
					if(OCR0 == 0){
						flag = 1;
						Motor_RotateAntiClockWise();
					}
				}
			}
			//take sensor readings
			ADC_prevTemp = ADC_currentTemp;
			ADC_currentTemp=ADC_Read(0);
			ADC_currentTemp = getTemp(ADC_currentTemp);
		}
	}else{
		Motor_stop(); //no action if temperatures are equal
	}
}


void EXTI_ISR(void){
	// Initialize UART to enable it only by the push button
	USART_Init();

	// Receive the string
	u8 *data = "";
	USART_ReceiveString(data);

	//check validity of data
	u8 i = 0; //iterator
	while(data[i]){
		if(data[i] <'0' || data[i] > '9'){
			USART_SendString("invalid input.\r"); //data[1:end]
			USART_SendString("invalid input.\rUsart closed, please try again later\r");
			UART_Close();
			break;
		}
		i++;
	}
	if(!data[i]){
		u8 num = atoi(data);
		if(num > LOWER_LIMIT && num < UPPER_LIMIT){
			desiredTemp = num;
			CLCD_voidMoveCursor(2, 10);
			CLCD_voidSendString(data);
		}
		else{
			USART_SendString("Temperature out of range.\r");
			USART_SendString("Usart closed, please try again later\r");
		}
		UART_Close();
	}
}
