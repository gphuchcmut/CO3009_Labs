/*
 * button.h
 *
 *  Created on: Nov 15, 2024
 *      Author: LENOVO
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NO_BUTTONS	3

#define PRESSED		1
#define RELEASED	0

int isButtonNOPressed(int);
void buttonReading();

#endif /* INC_BUTTON_H_ */
