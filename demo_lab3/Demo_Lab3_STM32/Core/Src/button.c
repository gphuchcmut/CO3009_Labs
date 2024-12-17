/*
 * button.c
 *
 *  Created on: Nov 15, 2024
 *      Author: LENOVO
 */

#include "button.h"

int buttonFlag[NO_BUTTONS] = {0, 0, 0};
int timeOut[NO_BUTTONS] = {100, 100, 100};

int keyReg0[NO_BUTTONS] = {RELEASED, RELEASED, RELEASED};
int keyReg1[NO_BUTTONS] = {RELEASED, RELEASED, RELEASED};
int keyReg2[NO_BUTTONS] = {RELEASED, RELEASED, RELEASED};
int keyReg3[NO_BUTTONS] = {RELEASED, RELEASED, RELEASED};

int TimeOutForKeyPress;

int isButtonNOPressed(int NO){
	if (buttonFlag[NO] == 1){
		buttonFlag[NO] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	buttonFlag[index] = 1;
}

GPIO_PinState button_detector(int index){
	switch (index) {
		case 0:
			return HAL_GPIO_ReadPin(SW0_GPIO_Port, SW0_Pin); //Change Mode
			break;
		case 1:
			return HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin); //Change Time
			break;
		case 2:
			return HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin); //Set Time
			break;
		default:
			return RELEASED;
			break;
	}
}

void buttonReading(){
	for (int i = 0; i < 3; i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		keyReg2[i] = button_detector(i);
		if ((keyReg1[i] == keyReg0[i]) && (keyReg1[i] == keyReg2[i])){
			if (keyReg2[i] != keyReg3[i]){
				keyReg3[i] = keyReg2[i];
				if (keyReg3[i] == PRESSED){
					TimeOutForKeyPress = 100;
					subKeyProcess(i);
				}
			}
			else{
				TimeOutForKeyPress --;
				if (TimeOutForKeyPress == 0) {
					keyReg3[i] = RELEASED;
				}
			}
		}
	}
}

