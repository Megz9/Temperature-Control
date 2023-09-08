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
