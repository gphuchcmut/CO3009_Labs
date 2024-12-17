/*
 * timer.h
 *
 *  Created on: Nov 3, 2024
 *      Author: LENOVO
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "global.h"

#define TIMER_CYCLE		10
#define NO_TIMER		10 //3 Led x 2 Road + 4 Led7Seg

extern int timerDuration[NO_TIMER];
extern int timerFlag[NO_TIMER];

void setTimerNO(int, int);
void resetTimerNO(int);
void timerRun();

#endif /* INC_TIMER_H_ */
