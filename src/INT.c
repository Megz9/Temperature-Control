/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : EXTI	                    ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 4/9/2023		            ***********/
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "EXTI.h"

#include "avr/io.h"
#include <string.h> // Include the string.h library for strcmp function

void ( *EXTI0_pvCallBackFunc)(void) = NULL;

// Function to initialize the external interrupt
void initExternalInterrupt(void) {
    // Configure the button pin as an input
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);

    // Enable the internal pull-up resistor for the button pin
    DIO_SetPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH);

    // Configure the external interrupt to trigger on falling edge
    SET_BIT(MCUCR, MCUCR_ISC01);
    CLR_BIT(MCUCR, MCUCR_ISC00);

    // Enable external interrupt 0
    SET_BIT(GICR, GICR_INT0);

}

u8   EXTI0_u8SetCallBack(void ( *Copy_userISR)(void)){

	u8 u8ErrorStstus_Local = OK;

	if(Copy_userISR != NULL){
		EXTI0_pvCallBackFunc = Copy_userISR;
	}
	else{
		u8ErrorStstus_Local = NULL_POINTER;
	}
	return u8ErrorStstus_Local;
}


/* Actual ISR */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if(EXTI0_pvCallBackFunc != NULL){
		EXTI0_pvCallBackFunc();
	}
}
//
//ISR(INT0_vect) {
//    DIO_SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
//
//    // Initialize the data array with null characters
//    memset(data, '\0', sizeof(data));
//
//    // Initialize UART (assuming this is done elsewhere in your code)
//    UART_Init();
//
//    // Receive the string
//    USART_voidReceiveNumber(data);
//
//    u8 i = 0;
//    while(data[i] != 0){
//    	if(data[i] <'0' || data[i] > '9'){
//    		USART_voidSendString("invalid input\r");
//    		USART_voidSendString("Usart closed");
//    		UART_Close();
//    		break;
//    	}
//    	i++;
//    }
//    if(data[i] == 0){
//    	u8 num = atoi(data);
//    	if(num > 15 && num < 150)
//    		isrData = num;
//    }
//
//    // Copy the contents of the data array to isrData
//    //strncpy(isrData, data, sizeof(isrData) - 1);
//   // isrData[sizeof(isrData) - 1] = '\0';
//
//
//    UART_Close();
//}
