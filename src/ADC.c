/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : ADC		                    ***********/
/***********	Version   : 3.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"

#include "avr/io.h"
#include "ACD.h"


void ADC_Init (void)
{
	// ADC Enable
	SET_BIT(ADCSRA , ADCSRA_ADEN);

	// Prescaler Configuration as 128, so Frequency of ADC  = CLK/128
	SET_BIT(ADCSRA , ADCSRA_ADPS2);
	SET_BIT(ADCSRA , ADCSRA_ADPS1);
	SET_BIT(ADCSRA , ADCSRA_ADPS0);


	// Referance Voltage as AVCC with external capacitor
	CLR_BIT (ADMUX  , ADMUX_REFS1);
	SET_BIT (ADMUX  , ADMUX_REFS0);

	/*ADC Data Right Adjustment 10 bits*/
	CLR_BIT(ADMUX , ADMUX_ADLAR);

}

s16 ADC_Read (u8 channel)
{
	//step 1 : Clear MUX bits in ADMUX
	ADMUX   &= 0b11100000;


	//Step 2 : Set the required  ADC Channel Selection into the MUX bits
	ADMUX   |=channel;


	// Step 3 : Start Single Conversion
	SET_BIT(ADCSRA , ADCSRA_ADSC );


	// Step 4 :  Polling (busy wait ) until the conversion complete flag is set
	while((GET_BIT(ADCSRA , ADCSRA_ADIF)) == 0);

	// Step 5:	Get the value of ADC from ADCL and ADCH
	s16 local = ADCL;
	local = local +256*GET_BIT(ADCH, 0) - 512*GET_BIT(ADCH,1);
	
	// Step 6 :  Clear Conversion Complete Flag by setting it
	SET_BIT(ADCSRA,ADCSRA_ADIF);


	// Step 7 :   return value (Right adjustment result 10 bits)

	return local;
	
}
