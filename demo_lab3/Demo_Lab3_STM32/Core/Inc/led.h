/*
 * led_display.h
 *
 *  Created on: Nov 3, 2024
 *      Author: LENOVO
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "global.h"

#define LED_ON		0
#define LED_OFF		1

extern int stateX; //state: Red, Yellow, Green
extern int stateY;

void dispLedX(int);
void dispLedY(int);

void blink_Led();

#endif /* INC_LED_DISPLAY_H_ */
