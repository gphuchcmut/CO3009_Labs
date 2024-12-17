/*
 * timer.c
 *
 *  Created on: Nov 15, 2024
 *      Author: LENOVO
 */

#include "timer.h"
#include "global.h"
#include "scheduler.h"

int timerDuration[NO_TIMER] = {0, 0, 0, 0, 0,
							   0, 0, 0, 0, 0 };

int timerFlag[NO_TIMER] = {0, 0, 0, 0, 0,
						   0, 0, 0, 0, 0 };

void setTimerNO(int timerNO, int duration){
	timerDuration[timerNO] = duration / TIMER_CYCLE;
	timerFlag[timerNO] = 0;
}

void resetTimer(int timerNO){
	timerDuration[timerNO] = 0;
	timerFlag[timerNO] = 0;
}

void timerRun(){
	for(int i = 0; i < NO_TIMER; i++){
		timerDuration[i]--;
		if (timerDuration[i] == 0){
			timerFlag[i] = 1;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
	buttonReading();
	SCH_Update();
}


