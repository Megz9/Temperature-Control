/**************************************/
/******     Author: Abdelmagid   ******/
/******     Layer: HAL   		 ******/
/******     Component: CLCD      ******/
/******     Version: 1.00        ******/
/******     Date: 8/14/2023      ******/
/**************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include "util/delay.h"
#include "string.h"

void CLCD_voidSendCommand(u8 u8CommandCopy){
	//step 1:
		//RS=0
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_LOW);
		// Rw=0
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);
	//step 2:
		DIO_SetPortValue(CLCD_DATA_PORT,u8CommandCopy);
	//step 3:
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}

void CLCD_voidSendData(u8 u8DataCopy){
	//step 1:
		//RS=1
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_HIGH);
		//RW=1
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);
	//step 2:
		DIO_SetPortValue(CLCD_DATA_PORT,u8DataCopy);
	//step 3:
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);

}

void CLCD_voidInit(void){
	//////Initialize DIO/////
	DIO_SetPortDirection(CLCD_DATA_PORT,0xFF);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_OUTPUT);

	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001110);
	CLCD_voidSendCommand(0b00000001);

	//_delay_ms(2);
	//CLCD_voidSendCommand(0b00000010);

	//////LCD init 8bit mode//////
	//N =1 -> 2 lines , N =0 -> 1 line
	//font F =0 -> 5x8, F=1 -> 5x11
	//no need for delay as we put additional delay in command
	//D: display
	//C: cursor
	//B: blink

}


void CLCD_voidClearLCD(){
	CLCD_voidSendCommand(0b00000001);
}

void CLCD_voidSendString(u8 u8ArrDataCopy[]){
	u8 length = strlen(u8ArrDataCopy);
	for(u8 i =0;i<length;i++){
		CLCD_voidSendData(u8ArrDataCopy[i]);
	}
}

void CLDC_voidReturnHome(){
	CLCD_voidSendCommand(0b00000010);
}
void CLCD_voidMoveCursor(u8 row, u8 col){
	u8 pos=0;
	if (row == 1){
		pos = (0x80) +col-1;
	}else if(row == 2){
		pos = (0xC0) + col-1;
	}else{
		pos = 0x80; //reset to row=1,col=0
	}
	CLCD_voidSendCommand(pos);
}

void CLCD_voidClearRow(u8 row){
	CLCD_voidMoveCursor(row,1);
	CLCD_voidSendString("                ");
	CLCD_voidMoveCursor(row,1);
}

void CLCD_voidClearCell(u8 row,u8 col){
	CLCD_voidMoveCursor(row,col);
	CLCD_voidSendData(' ');
	CLCD_voidMoveCursor(row,col);
}

void CLCD_character(u8 row,u8 col)
{
CLCD_voidSendCommand(64);  // Address where customized character is to be stored
CLCD_voidSendData(0);
CLCD_voidSendData(0);
CLCD_voidSendData(0b01010);
CLCD_voidSendData(0);
CLCD_voidSendData(0b10001);
CLCD_voidSendData(0b01110);
CLCD_voidSendData(0);
CLCD_voidSendData(0);
if(row ==1){
CLCD_voidSendCommand(0x80+col-1);  // Location of LCD where the character is to be displayed
}
if(row ==2){
CLCD_voidSendCommand(0xC0+col-1);  // Location of LCD where the character is to be displayed
}
CLCD_voidSendData(0);  // Displaying the character created at address 0x64
_delay_ms(10);
}
