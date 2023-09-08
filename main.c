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
	}
}