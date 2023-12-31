/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : USART	                    ***********/
/***********	Version   : 2.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#ifndef USART_H_
#define USART_H_

#define FRAME_SIZE              8

#define RXD_PORT                PORTD
#define TXD_PORT                PORTD

#define RXD_PIN                 0
#define TXD_PIN                 1

/*define registers pins*/
#define UCSRA_RXC               7
#define UCSRA_TXC               6
#define UCSRA_UDRE              5
#define UCSRA_FE                4
#define UCSRA_DOR               3
#define UCSRA_PE                2
#define UCSRA_U2X               1
#define UCSRA_MPCM              0

#define UCSRB_RXCIE             7
#define UCSRB_TXCIE             6
#define UCSRB_UDRIE             5
#define UCSRB_RXEN              4
#define UCSRB_TXEN              3
#define UCSRB_UCSZ2             2
#define UCSRB_RXB8              1
#define UCSRB_TXB8              0

#define UCSRC_URSEL             7
#define UCSRC_UMSEL             6
#define UCSRC_UPM1              5
#define UCSRC_UPM0              4
#define UCSRC_USBS              3
#define UCSRC_UCSZ1             2
#define UCSRC_UCSZ0             1
#define UCSRC_UCPOL             0

#define UBRRH_URSEL             7


void USART_Init(void);
void USART_SendData(u8 dataCopy);
u8   USART_ReceiveData(void);

void USART_SendString(u8* dataCopy);
void   USART_ReceiveString(u8* dataCopy);
void UART_Close(void);
//u8   USART_ReceiveString(u8* dataCopy, u8 nOfCharacters);
#endif /* USART_H_ */
