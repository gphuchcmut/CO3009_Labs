/*
 * fsm.h
 *
 *  Created on: Nov 29, 2024
 *      Author: LENOVO
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "global.h"
#include "led7seg.h"
#include "button.h"
#include "led.h"

extern int status_X;
extern int status_Y;

extern int red_Value;
extern int yellow_Value;
extern int green_Value;

extern int red_Draft;
extern int yellow_Draft;
extern int green_Draft;

extern int count_X;
extern int count_Y;

void fsm_run();

void fsm_traffic_light();
void mode_button_scan(); 		//SW0
void increase_button_scan();	//SW1
void set_button_scan();			//SW2
void fsm_led_blink();


#endif /* INC_FSM_H_ */
