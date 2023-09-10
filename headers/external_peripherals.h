/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : HAL     	                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#ifndef EXTERNAL_PERIPHERALS_H_
#define EXTERNAL_PERIPHERALS_H_

#define RED_LED_PORT           DIO_PORTD
#define RED_LED_PIN            DIO_PIN5

#define GREEN_LED_PORT         DIO_PORTD
#define GREEN_LED_PIN          DIO_PIN4

#define BUZZER_PORT            DIO_PORTD
#define BUZZER_PIN             DIO_PIN3

#define RELAY_PORT             DIO_PORTB
#define RELAY_PIN              DIO_PIN4

void RELAY_voidInit(void);
void LEDS_voidInit(void);
void BUZZER_voidInit(void);

void openRELAY(void);
void closeRELAY(void);
void useBuzzer(u8 toggleNumber);
void openBuzzer(void);
void closeBuzzer(void);

void GreenLedON(void);
void GreenLedOFF(void);
void RedLedBlink();
void RedLedOFF(void);
void RedLedON(void);


#endif /* EXTERNAL_PERIPHERALS_H_ */
