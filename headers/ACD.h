/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : ADC		                    ***********/
/***********	Version   : 2.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#ifndef ACD_H_
#define ACD_H_


// ADMUX   :  ADC multiplexer selection register
#define ADMUX_REFS1          7          //Reference selection bitl
#define ADMUX_REFS0          6          //Reference selection bit0
#define ADMUX_ADLAR          5          //ADC left adjust result
#define ADMUX_MUX4           4
#define ADMUX_MUX3           3
#define ADMUX_MUX2           2
#define ADMUX_MUX1           1
#define ADMUX_MUX0           0

//ADCSRA   :  ADC control and status register A
#define ADCSRA_ADEN          7          //ADC enable
#define ADCSRA_ADSC          6          //Start conversion
#define ADCSRA_ADATE         5          //Auto trigger enable
#define ADCSRA_ADIF          4          //Interrupt flag
#define ADCSRA_ADIE          3          //Interrupt enable
#define ADCSRA_ADPS2         2          //Prescaler bit2
#define ADCSRA_ADPS1         1          //Prescaler bitl
#define ADCSRA_ADPS0         0          //Prescaler bit0

//SFIOR  : ADC Function IO register used for Auto triggering mode
#define SFIOR_ADTS2          7
#define SFIOR_ADTS1          6
#define SFIOR_ADTS0          5


// 8  PINS :
#define ADC_PINS_PORT                     DIO_PORTA

#define ADC0_PIN                          DIO_PIN0
#define ADC1_PIN                          DIO_PIN1
#define ADC2_PIN                          DIO_PIN2
#define ADC3_PIN                          DIO_PIN3
#define ADC4_PIN                          DIO_PIN4
#define ADC5_PIN                          DIO_PIN5
#define ADC6_PIN                          DIO_PIN6
#define ADC7_PIN                          DIO_PIN7



//Configure table 84 as macro here to bus it as channel in u8 Copy_u8Channel
#define SINGLE_ENDED_ADC0                  0
#define SINGLE_ENDED_ADC1                  1
#define SINGLE_ENDED_ADC2                  2
#define SINGLE_ENDED_ADC3                  3
#define SINGLE_ENDED_ADC4                  4
#define SINGLE_ENDED_ADC5                  5
#define SINGLE_ENDED_ADC6                  6
#define SINGLE_ENDED_ADC7                  7

#define DIFF_ENDED_ADC0_POS_ADC0_NEG_G10   8
#define DIFF_ENDED_ADC1_POS_ADC0_NEG_G10   9
#define DIFF_ENDED_ADC0_POS_ADC0_NEG_G200  10
#define DIFF_ENDED_ADC1_POS_ADC0_NEG_G200  11
#define DIFF_ENDED_ADC2_POS_ADC2_NEG_G10   12
#define DIFF_ENDED_ADC3_POS_ADC2_NEG_G10   13
#define DIFF_ENDED_ADC2_POS_ADC2_NEG_G200  14
#define DIFF_ENDED_ADC3_POS_ADC2_NEG_G200  15
#define DIFF_ENDED_ADC0_POS_ADC1_NEG_G1    16
#define DIFF_ENDED_ADC1_POS_ADC1_NEG_G1    17
#define DIFF_ENDED_ADC2_POS_ADC1_NEG_G1    18
#define DIFF_ENDED_ADC3_POS_ADC1_NEG_G1    19
#define DIFF_ENDED_ADC4_POS_ADC1_NEG_G1    20
#define DIFF_ENDED_ADC5_POS_ADC1_NEG_G1    21
#define DIFF_ENDED_ADC6_POS_ADC1_NEG_G1    22
#define DIFF_ENDED_ADC7_POS_ADC1_NEG_G1    23
#define DIFF_ENDED_ADC0_POS_ADC2_NEG_G1    24
#define DIFF_ENDED_ADC1_POS_ADC2_NEG_G1    25
#define DIFF_ENDED_ADC2_POS_ADC2_NEG_G1    26
#define DIFF_ENDED_ADC3_POS_ADC2_NEG_G1    27
#define DIFF_ENDED_ADC4_POS_ADC2_NEG_G1    28
#define DIFF_ENDED_ADC5_POS_ADC2_NEG_G1    29


void ADC_Init (void);   // ADC Initialization And Enable

s16 ADC_Read (u8 channel);  // Read From The ADC Channel


#endif /* ACD_H_ */
