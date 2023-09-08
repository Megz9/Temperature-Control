/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : EXTI		                ***********/
/***********	Version   : 3.00			            ***********/
/***********	Date      : 6/9/2023		            ***********/
/******************************************************************/

#ifndef EXTI_H_
#define EXTI_H_

//MCUCR register
#define MCUCR_ISC00    0
#define MCUCR_ISC01    1
#define MCUCR_ISC10    2
#define MCUCR_ISC11    3

//MCUCSR Register
#define MCUCSR_ISC2    6

//GICR register
#define GICR_INT1      7
#define GICR_INT0      6
#define GICR_INT2      5

//GIFR Register
#define GIFR_INTF1      7
#define GIFR_INTF0      6
#define GIFR_INTF2      5

//External Interrupt Pins INT0 , INT1 , INT2
#define EXTI0_PORT     DIO_PORTD
#define EXTI0_PIN      DIO_PIN2


#define EXTI1_PORT     DIO_PORTD
#define EXTI1_PIN      DIO_PIN3


#define EXTI2_PORT     DIO_PORTB
#define EXTI2_PIN      DIO_PIN2


/*Config file : Options
 *      1-  RISING_EDGE
 *      2-  FALLING_EDGE
 *      3-  LOW_LEVEL
 *      4-  HIGH_LEVEl  */

//Sense Control Options
#define EXTI_RISING_EDGE   1
#define EXTI_FALLING_EDGE  2
#define EXTI_LOW_LEVEL     3
#define EXTI_ON_CHANGE     4

#define EXTI_SENSE_CONTROL EXTI_LOW_LEVEL


/*Config file : Options
 *      1- Enable
 *      2- Disable
 */

#define  EXTI_ENABLED        1
#define  EXTI_DISABLED        2

#define INT0_INITIAL_STATE        EXTI_ENABLED

void initExternalInterrupt();
void    EXTI_void_Int0Init(void);
void    EXTI_void_Int1Init(void);
void    EXTI_void_Int2Init(void);

u8 EXTI_u8Int0SetSenseControl(u8 u8SenseCopy );
u8 EXTI_u8Int1SetSenseControl(u8 u8SenseCopy );
u8 EXTI_u8Int2SetSenseControl(u8 u8SenseCopy );

/*
 *  TO DO Functions (assignment )
 *                                  */

u8 EXTI_u8Int0Enable(u8 u8Int0_Copy);
u8 EXTI_u8Int0Disable(u8 u8Int0_Copy);

u8 EXTI_u8Int1Enable(u8 u8Int1_Copy);
u8 EXTI_u8Int1Disable(u8 u8Int1_Copy);

u8 EXTI_u8Int2Enable(u8 u8Int2_Copy);
u8 EXTI_u8Int2Disable(u8 u8Int2_Copy);

u8 EXTI_u8Int0SetCallBack (void (*PvInt0Func_Copy) (void));
u8   EXTI0_u8SetCallBack(void ( *Copy_userISR)(void));

#endif /* EXTI_H_ */
