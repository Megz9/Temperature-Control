/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : DIO		                    ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 25/8/2023		            ***********/
/******************************************************************/
#ifndef DIO_H_
#define DIO_H_

/*Port Defines*/
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

/*Pins Defines*/
#define DIO_PIN0 	0
#define DIO_PIN1	1
#define DIO_PIN2 	2
#define DIO_PIN3 	3
#define DIO_PIN4 	4
#define DIO_PIN5 	5
#define DIO_PIN6 	6
#define DIO_PIN7 	7

/*Pin Directions */
#define DIO_INPUT 	0
#define DIO_OUTPUT	1

/*PIN Value Options*/
#define DIO_HIGH 	1
#define DIO_LOW		0

/*prototypes of Function IO pins*/
/* IO Pins*/
void 	DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValCopy);

void 	DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

u8 		DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void 	DIO_TogglePin(u8 u8PortIdCopy, u8 u8PinIdCopy);

/* IO Ports*/
void 	DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValCopy);

void 	DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy);


#endif /* DIO _H_ */
