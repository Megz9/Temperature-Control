#ifndef CLDC_H
#define CLDC_H


#define CLCD_DATA_PORT 	DIO_PORTC
#define CLCD_CTRL_PORT 	DIO_PORTA

#define CLCD_RS_PIN 	DIO_PIN5
#define CLCD_RW_PIN 	DIO_PIN6
#define CLCD_E_PIN 		DIO_PIN7

void CLCD_voidSendData(u8 u8DataCopy);
void CLCD_voidSendCommand(u8 u8CommandCopy);
void CLCD_voidInit(void);

void CLCD_voidSendString(u8 u8ArrDataCopy[]);
void CLCD_voidClearLCD();
void CLCD_voidClearCell(u8 row,u8 col);
void CLDC_voidReturnHome();


void CLCD_voidMoveCursor(u8 row, u8 col);
void CLCD_voidClearRow(u8 row);
void CLCD_character(u8 row,u8 col);

#endif
