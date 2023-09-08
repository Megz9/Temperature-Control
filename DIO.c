/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : DIO 	                    ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 25/8/2023		            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include <util/delay.h>

void 	DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValCopy){
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
		if(u8PinValCopy  == DIO_HIGH){
			switch(u8PortIdCopy){
				case DIO_PORTA:	SET_BIT(PORTA,u8PinIdCopy);	break;
				case DIO_PORTB: SET_BIT(PORTB,u8PinIdCopy); break;
				case DIO_PORTC: SET_BIT(PORTC,u8PinIdCopy); break;
				case DIO_PORTD: SET_BIT(PORTD,u8PinIdCopy); break;
			}
		}
		else if(u8PinValCopy == DIO_LOW){
			switch(u8PortIdCopy){
				case DIO_PORTA:	CLR_BIT(PORTA,u8PinIdCopy);	break;
				case DIO_PORTB: CLR_BIT(PORTB,u8PinIdCopy); break;
				case DIO_PORTC: CLR_BIT(PORTC,u8PinIdCopy); break;
				case DIO_PORTD: CLR_BIT(PORTD,u8PinIdCopy); break;

			}
		}else{
			//didn't enter high or low
		}

	}else{
		//out or range
	}
}

void 	DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy){
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
		if(u8PinDirCopy == DIO_OUTPUT){
			switch(u8PortIdCopy){
					case DIO_PORTA:	SET_BIT(DDRA,u8PinIdCopy); break;
					case DIO_PORTB: SET_BIT(DDRB,u8PinIdCopy); break;
					case DIO_PORTC: SET_BIT(DDRC,u8PinIdCopy); break;
					case DIO_PORTD: SET_BIT(DDRD,u8PinIdCopy); break;
				}
			}
			else if(u8PinDirCopy == DIO_INPUT){
				switch(u8PortIdCopy){
					case DIO_PORTA:	CLR_BIT(DDRA,u8PinIdCopy); break;
					case DIO_PORTB: CLR_BIT(DDRB,u8PinIdCopy); break;
					case DIO_PORTC: CLR_BIT(DDRC,u8PinIdCopy); break;
					case DIO_PORTD: CLR_BIT(DDRD,u8PinIdCopy); break;
				}
			}else{
				//didn't enter high or low
			}


	}else{
		//out of range
	}
}

u8 		DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy){
	u8 u8ResultLocal;
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
			switch(u8PortIdCopy){
				case DIO_PORTA:	u8ResultLocal = GET_BIT(PINA,u8PinIdCopy); break;
				case DIO_PORTB: u8ResultLocal = GET_BIT(PINB,u8PinIdCopy); break;
				case DIO_PORTC: u8ResultLocal = GET_BIT(PINC,u8PinIdCopy); break;
				case DIO_PORTD: u8ResultLocal = GET_BIT(PIND,u8PinIdCopy); break;
			}
	}else{
		//out of range
		u8ResultLocal = 0xff;
	}
	return u8ResultLocal;
}


void 	DIO_TogglePin(u8 u8PortIdCopy, u8 u8PinIdCopy){
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
		switch(u8PortIdCopy){
			case DIO_PORTA:	TOG_BIT(PORTA,u8PinIdCopy);	break;
			case DIO_PORTB: TOG_BIT(PORTB,u8PinIdCopy); break;
			case DIO_PORTC: TOG_BIT(PORTC,u8PinIdCopy); break;
			case DIO_PORTD: TOG_BIT(PORTD,u8PinIdCopy); break;
		}
	}else{
		//out or range
	}
}









/* IO Ports*/
void 	DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValCopy){
	if(u8PortIdCopy <= DIO_PORTD){
		switch(u8PortIdCopy){
			case DIO_PORTA:	PORTA = u8PortValCopy; break;
			case DIO_PORTB: PORTB = u8PortValCopy; break;
			case DIO_PORTC: PORTC = u8PortValCopy; break;
			case DIO_PORTD: PORTD = u8PortValCopy; break;
		}
	}else{
			//out of range
	}

	/*if(u8PortIdCopy <= DIO_PORTD){
		if(u8PortValCopy == DIO_HIGH){
			switch(u8PortIdCopy){
				case DIO_PORTA:	SET_PORT(PORTA);	break;
				case DIO_PORTB: SET_PORT(PORTB); break;
				case DIO_PORTC: SET_PORT(PORTC); break;
				case DIO_PORTD: SET_PORT(PORTD); break;
			}
		}
		else if(u8PortValCopy == DIO_LOW){
			switch(u8PortIdCopy){
				case DIO_PORTA:	CLR_PORT(PORTA); break;
				case DIO_PORTB: CLR_PORT(PORTB); break;
				case DIO_PORTC: CLR_PORT(PORTC); break;
				case DIO_PORTD: CLR_PORT(PORTD); break;
			}
		}else{
			//didn't enter high or low
		}

	}else{
		//out of range
	}*/
}

void 	DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy){
	if(u8PortIdCopy <= DIO_PORTD){
		switch(u8PortIdCopy){
			case DIO_PORTA:	DDRA = u8PortDirCopy; break;
			case DIO_PORTB: DDRB = u8PortDirCopy; break;
			case DIO_PORTC: DDRC = u8PortDirCopy; break;
			case DIO_PORTD: DDRD = u8PortDirCopy; break;
		}
	}else{
			//out of range
	}
}
