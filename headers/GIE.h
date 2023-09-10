/******************************************************************/
/***********	Author    : Team 5                  	***********/
/***********	Layer     : MCAL     	                ***********/
/***********	Component : GIE		                    ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 4/9/2023		            ***********/
/******************************************************************/

#ifndef GIE_H_
#define GIE_H_

//SREG register bit 7
#define SREG_I 7

void GIE_Enable(void);
void GIE_Disable(void);


#endif /* GIE_H_ */
