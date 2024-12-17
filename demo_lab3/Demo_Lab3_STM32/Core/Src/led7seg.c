/*
 * led7seg.c
 *
 *  Created on: Nov 28, 2024
 *      Author: LENOVO
 */

#include "led7seg.h"

int led7seg_buffer[4] = {0, 0, 0, 0};

GPIO_PinState pinArr[11][7] = {
		{0 , 0, 0 , 0 , 0 , 0, 1} , //0
		{1 , 0, 0 , 1 , 1 , 1, 1} , //1
		{0 , 0, 1 , 0 , 0 , 1, 0} , //2
		{0 , 0, 0 , 0 , 1 , 1, 0} , //3
		{1 , 0, 0 , 1 , 1 , 0, 0} , //4
		{0 , 1, 0 , 0 , 1 , 0, 0} , //5
		{0 , 1, 0 , 0 , 0 , 0, 0} , //6
		{0 , 0, 0 , 1 , 1 , 1, 1} , //7
		{0 , 0, 0 , 0 , 0 , 0, 0} , //8
		{0 , 0, 0 , 0 , 1 , 0, 0} , //9
		{1 , 1, 1 , 1 , 1 , 1, 1}   //All Led turn off
};

void disp7segX(int num){
	if((num >= 0) && (num <=9)){
		for(int state = 0; state < 7; state++){
			HAL_GPIO_WritePin(SEG_A_X_GPIO_Port, SEG_A_X_Pin << state, pinArr[num][state]);
		}
	}
	else{ //Turn Off
		for(int state = 0; state < 7; state++){
			HAL_GPIO_WritePin(SEG_A_X_GPIO_Port, SEG_A_X_Pin << state, pinArr[10][state]);
		}
	}
}

void disp7segY(int num){
	if((num >= 0) && (num <=9)){
		for(int state = 0; state < 7; state++){
			HAL_GPIO_WritePin(SEG_A_Y_GPIO_Port, SEG_A_Y_Pin << state, pinArr[num][state]);
		}
	}
	else{ //Turn Off
		for(int state = 0; state < 7; state++){
			HAL_GPIO_WritePin(SEG_A_Y_GPIO_Port, SEG_A_Y_Pin << state, pinArr[10][state]);
		}
	}
}

void update7segX(int numX){
	led7seg_buffer[0] = numX / 10;
	led7seg_buffer[1] = numX % 10;
}

void update7segY(int numY){
	led7seg_buffer[2] = numY / 10;
	led7seg_buffer[3] = numY % 10;
}

int ledDigitX = 0;
int ledDigitY = 0;

void scan7segX(){
	switch(ledDigitX){
	case 0: //Display First Led of X
		HAL_GPIO_WritePin(EN0_GPIO_Port , EN0_Pin , 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port , EN1_Pin , 1);
		disp7segX(led7seg_buffer[0]) ;
		ledDigitX = 1;
		break ;
	case 1: //Display Second Led of X
		HAL_GPIO_WritePin(EN0_GPIO_Port , EN0_Pin , 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port , EN1_Pin , 0);
		disp7segX(led7seg_buffer[1]) ;
		ledDigitX = 0;
		break ;
	}
}

void scan7segY(){
	switch(ledDigitY){
	case 0: //Display First Led of Y
		HAL_GPIO_WritePin(EN2_GPIO_Port , EN2_Pin , 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port , EN3_Pin , 1);
		disp7segY(led7seg_buffer[2]) ;
		ledDigitY = 1;
		break ;
	case 1: //Display Second Led of Y
		HAL_GPIO_WritePin(EN2_GPIO_Port , EN2_Pin , 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port , EN3_Pin , 0);
		disp7segY(led7seg_buffer[3]) ;
		ledDigitY = 0;
		break ;
	}
}







