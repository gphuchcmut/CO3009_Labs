/*
 * global.h
 *
 *  Created on: Nov 3, 2024
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "button.h"
#include "main.h"
#include "led.h"
#include "scheduler.h"
#include "stdint.h"


#define INIT				999

/*
#define NONE 			0
#define IDLE 			-1
*/

//LED
#define RED					11
#define YELLOW				22
#define GREEN				33
#define ALL					44
#define NONE				55

//FSM MODE
#define MODE1				111
#define MODE2				222
#define MODE3				333
#define MODE4 				444

//Timer Counter
#define timerX_LED			0
#define timerY_LED			1
#define timerX_Led7Seg		2
#define timerY_Led7Seg		3
#define timer_countX		4
#define timer_countY		5

extern int status; //for Mode


#endif /* INC_GLOBAL_H_ */
