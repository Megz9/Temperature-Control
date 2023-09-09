/*
 * TIMER.h
 *
 *  Created on: Aug 20, 2023
 *      Author: abdel
 */

//page 78
#ifndef TIMER_H_
#define TIMER_H_

#define TCCR0_F0C0		7	//force the output as it we reached the compare value
#define TCCR0_WGM00		6	//waveform generation mode(overflow(normal), compare and match(CTC))
#define TCCR0_WGM01		3	//waveform generation mode(overflow(normal), compare and match(CTC))


#define TCCR0_COM01		5	//compare match output mode (set,tog,clr,disable) on OC0
#define TCCR0_COM00		4	//compare match output mode (set,tog,clr,disable) on OC0

//clock we will use prescalar 8: 010 (last thing to be written)
//110 , 111 -->counter like count rising or falling edge of certaim signal input to T0
#define TCCR0_CS02		2
#define TCCR0_CS01		1
#define TCCR0_CS00		0


// TCNT0 --> write preload here or read from it (overflow)
// OCRO --> put output compare value (compare and match)

//timer mask register
#define TIMSK_OCIE0		1	//enable interrupt compare and match
#define TIMSK_TOIE0		0	 //enable interrupt overflow

//------timer2-------//


#define TCCR2_F0C2		7	//force the output as it we reached the compare value
#define TCCR2_WGM20		6	//waveform generation mode(overflow(normal), compare and match(CTC))
#define TCCR2_WGM21		3	//waveform generation mode(overflow(normal), compare and match(CTC))


#define TCCR2_COM21		5	//compare match output mode (set,tog,clr,disable) on OC0
#define TCCR2_COM20		4	//compare match output mode (set,tog,clr,disable) on OC0

//clock we will use prescalar 8: 010 (last thing to be written)
//110 , 111 -->counter like count rising or falling edge of certaim signal input to T0
#define TCCR2_CS22		2
#define TCCR2_CS21		1
#define TCCR2_CS20		0


// TCNT2 --> write preload here or read from it (overflow)
// OCR2 --> put output compare value (compare and match)

//timer mask register
#define TIMSK_OCIE2		7	//enable interrupt compare and match
#define TIMSK_TOIE2		6	 //enable interrupt overflow


#define TIFR_OCF2       7
//////////////////////

void TIMER0_Init(void);
u8 TIMER0_u8SetCallBack(void (*pvCallBackFunc_Copy)(void));


void TIMER2_Init(void);
u8 TIMER2_u8SetCallBack(void (*pvCallBackFunc_Copy)(void));
void TIMER2_Disable(void);


/*PWM functions*/
void TIMER0_PWM_voidSetTon(u8 ton);
void TIMER0_PWM_voidIncreaseDutyCycle(void);
void TIMER0_PWM_voidDecreaseDutyCycle(void);


#endif /* TIMER_H_ */
