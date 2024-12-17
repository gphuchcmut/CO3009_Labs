/*
 * led_display.c
 *
 *  Created on: Nov 15, 2024
 *      Author: LENOVO
 */

#include "led.h"

void dispLedX(int color){
	switch(color){
		case RED:
			HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, LED_ON);
			HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, LED_OFF);
			HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, LED_OFF);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, LED_OFF);
			HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, LED_ON);
			HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, LED_OFF);
			break;
		case GREEN:
			HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, LED_OFF);
			HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, LED_OFF);
			HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, LED_ON);
			break;
		case ALL:
			HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, LED_ON);
			HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, LED_ON);
			HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, LED_ON);
			break;
		default:
			HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, LED_OFF);
			HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, LED_OFF);
			HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, LED_OFF);
			break;
	}
}

void dispLedY(int color){
	switch(color){
		case RED:
			HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, LED_ON);
			HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, LED_OFF);
			HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, LED_OFF);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, LED_OFF);
			HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, LED_ON);
			HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, LED_OFF);
			break;
		case GREEN:
			HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, LED_OFF);
			HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, LED_OFF);
			HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, LED_ON);
			break;
		case ALL:
			HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, LED_ON);
			HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, LED_ON);
			HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, LED_ON);
			break;
		default:
			HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, LED_OFF);
			HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, LED_OFF);
			HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, LED_OFF);
			break;
	}
}

void blink_Led(int led_Color){
	switch (led_Color) {
		case RED:
			HAL_GPIO_TogglePin(RED_X_GPIO_Port, RED_X_Pin);
			HAL_GPIO_TogglePin(RED_Y_GPIO_Port, RED_Y_Pin);
			break;
		case YELLOW:
			HAL_GPIO_TogglePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin);
			HAL_GPIO_TogglePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin);
			break;
		case GREEN:
			HAL_GPIO_TogglePin(GREEN_X_GPIO_Port, GREEN_X_Pin);
			HAL_GPIO_TogglePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin);
			break;
		default:
			break;
	}
}

