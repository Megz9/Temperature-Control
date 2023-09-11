/*
 * STD_TYPES.h
 *
 *  Created on: Aug 10, 2023
 *      Author: abdel
 */
//#define F_CPU 8000000


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned	   char 	u8;
typedef signed 		   char 	s8;

typedef unsigned short int  	u16;
typedef signed 	 short int      s16;

typedef unsigned long  int      u32;
typedef signed 	 long  int      s32;

/*Types for float data */
typedef float 		f32;
typedef double 		f64;
typedef long double f128;

#define OK		0
#define NOK		1


#define NULL 0
#define NULL_POINTER	2

#endif /* STD_TYPES_H_ */
