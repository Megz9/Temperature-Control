/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : USART		                ***********/
/***********	Version   : 2.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE.h"
#include "DIO.h"
#include "USART.h"
#include "avr/io.h"

void USART_Init(void){
	SET_BIT(DDRD,TXD_PIN); //tx pin as output
	CLR_BIT(DDRD,RXD_PIN); //rx pin as input

	//enable usart
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*configure UCSRC*/
	SET_BIT(UCSRC,UCSRC_URSEL);
	CLR_BIT(UCSRC,UCSRC_UMSEL); //asynchronous operation

	//disable parity bit
	CLR_BIT(UCSRC,UCSRC_UPM1);
	CLR_BIT(UCSRC,UCSRC_UPM0);

	CLR_BIT(UCSRC,UCSRC_USBS); //one stop bit

	//character size = 8 bit
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(UCSRC,UCSRC_UCSZ0);
	SET_BIT(UCSRC,UCSRC_UCSZ1);

	/*baud rate*/
	UBRRL = 51; //baud rate = 9600
	UBRRH = 0;

}

void UART_Close(void) {
    // Disable TX and RX
    CLR_BIT(UCSRB, TXEN);
    CLR_BIT(UCSRB, RXEN);
}

//void USART_SendData(u8 dataCopy){
//	SET_BIT(DDRD,TXD_PIN); //tx pin as output
//	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0); //busy waiting
//	UDR = dataCopy;
//}
//
//u8   USART_ReceiveData(void){
////	CLR_BIT(DDRD,RXD_PIN); //rx pin as input
//	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
//	CLR_BIT(UCSRA,UCSRA_RXC);
//	return UDR;
//}
//
//void USART_SendString(u8* dataCopy){
//	while(*dataCopy != 0){
//		USART_SendData(*(dataCopy++));
//	}
//}
//
//void   USART_ReceiveString(u8* dataCopy){
//	u8 localData = USART_ReceiveData();
//	/*end receiving when sender press enter*/
//	while(localData != '\r'){
//		*dataCopy = localData;
//		dataCopy++;
//		localData = USART_ReceiveData();
//	}
//	*dataCopy = 0;//null terminator to indicate end of string
//}

void USART_SendData(u8 u8data_Copy)
{
	// step 1 : wait flag UDRFE to finish
	// Wait until transmission Register Empty
	while(GET_BIT(UCSRA , UDRE) == 0);

	// step 2 : send Data
	UDR = u8data_Copy; //UDR is buffer register
}


u8   USART_ReceiveData(void)
{
	// step 1 : wait flag RXC to finish
	while(GET_BIT(UCSRA,RXC)==0) ;
	// step 2 : Receive Data
	return UDR ;
}


void USART_SendString(u8* Copy_pu8Data) {
    while (*Copy_pu8Data != '\0') {
        USART_SendData(*Copy_pu8Data);
        Copy_pu8Data++;
    }
}

void USART_ReceiveString(u8* Copy_pu8Data) {
    u8 x = 0;
    while (1) {
        u8 receivedChar = USART_ReceiveData();
        if (receivedChar == '\r' || receivedChar == '\n') {
            // If a carriage return or newline character is received, terminate the string
            Copy_pu8Data[x] = '\0';
            break;
        }
        Copy_pu8Data[x] = receivedChar;
        x++;
    }
}

