/*
 * led7seg.h
 *
 *  Created on: Nov 28, 2024
 *      Author: LENOVO
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_

#include "global.h"

extern int led7seg_buffer[4]; //EN0, EN1 for X; EN2, EN3 for Y

extern int ledDigit;

void disp7segX(int);
void disp7segY(int);

void scan7segX();
void scan7segY(); //Scan first Led of X,Y or second Led of X,Y repeatly

void update7segX(int);
void update7segY(int);

#endif /* INC_LED7SEG_H_ */
