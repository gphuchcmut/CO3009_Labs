/*
 * fsm.c
 *
 *  Created on: Nov 29, 2024
 *      Author: LENOVO
 */

#ifndef SRC_FSM_C_
#define SRC_FSM_C_

#include "fsm.h"

int status = INIT;

int status_X = INIT;
int status_Y = INIT;

int red_Value = 25;
int yellow_Value = 5;
int green_Value = 20;

int red_Draft = 25;
int yellow_Draft = 5;
int green_Draft = 20;

int count_X;
int count_Y;

void fsm_run(){
	switch(status){
		case INIT:
			status = MODE1;
			break;
		case MODE1:
			fsm_traffic_light();		//Normal Mode
			mode_button_scan(); 		//SW0 Scan
			break;
		case MODE2:
			fsm_led_blink();
			mode_button_scan(); 		//SW0 Scan
			increase_button_scan(); 	//SW1 Scan
			set_button_scan();			//SW2 Scan
			break;
		case MODE3:
			fsm_led_blink();
			mode_button_scan();			//SW0 Scan
			increase_button_scan();		//SW1 Scan
			set_button_scan();			//SW2 Scan
			break;
		case MODE4:
			fsm_led_blink();
			mode_button_scan();			//SW0 Scan
			increase_button_scan();		//SW1 Scan
			set_button_scan();			//SW2 Scan
			break;
		default:
			break;
	}
}

void fsm_traffic_light(){
	//Status X Case
	switch(status_X){
		case INIT:
			status_X = RED;
			count_X = red_Value;
			setTimerNO(timerX_LED, red_Value * 1000); //25000ms = 25s
			setTimerNO(timerX_Led7Seg, 100);
			setTimerNO(timer_countX, 1000);
			break;
		case RED:
			//Next Status
			if(timerFlag[timerX_LED] == 1){
				status_X = GREEN;
				count_X = green_Value;
				setTimerNO(timerX_LED, green_Value * 1000);
				setTimerNO(timerX_Led7Seg, 100);
				setTimerNO(timer_countX, 1000);
			}
			//Task for this Status
			dispLedX(RED);
			if(timerFlag[timerX_Led7Seg] == 1){
				setTimerNO(timerX_Led7Seg, 100);
				update7segX(count_X);
				scan7segX();
			}
			if(timerFlag[timer_countX] == 1){
				count_X--;
				setTimerNO(timer_countX, 1000);
			}
			break;
		case YELLOW:
			//Next Status
			if (timerFlag[timerX_LED] == 1){
				status_X = RED;
				count_X = red_Value;
				setTimerNO(timerX_LED, red_Value * 1000);
				setTimerNO(timerX_Led7Seg, 100);
				setTimerNO(timer_countX, 1000);
			}
			//Task for this Status
			dispLedX(YELLOW);
			if(timerFlag[timerX_Led7Seg] == 1){
				setTimerNO(timerX_Led7Seg, 100);
				update7segX(count_X);
				scan7segX();
			}
			if(timerFlag[timer_countX] == 1){
				setTimerNO(timer_countX, 1000);
				count_X--;
			}
			break;
		case GREEN:
			//Next Status
			if (timerFlag[timerX_LED] == 1){
				status_X = YELLOW;
				count_X = yellow_Value;
				setTimerNO(timerX_LED, yellow_Value * 1000);
				setTimerNO(timerX_Led7Seg, 100);
				setTimerNO(timer_countX, 1000);
			}
			//Task for this Status
			dispLedX(GREEN);
			if(timerFlag[timerX_Led7Seg] == 1){
				setTimerNO(timerX_Led7Seg, 100);
				update7segX(count_X);
				scan7segX();
			}
			if(timerFlag[timer_countX] == 1){
				setTimerNO(timer_countX, 1000);
				count_X--;
			}
			break;
		default:
			break;
	}
	//Status Y Case
	switch(status_Y){
		case INIT:
			status_Y = GREEN;
			count_Y = green_Value;
			setTimerNO(timerY_LED, green_Value * 1000); //25000ms = 25s
			setTimerNO(timerY_Led7Seg, 100);
			setTimerNO(timer_countY, 1000);
			break;
		case RED:
			//Next Status
			if(timerFlag[timerY_LED] == 1){
				status_Y = GREEN;
				count_Y = green_Value;
				setTimerNO(timerY_LED, green_Value * 1000);
				setTimerNO(timerY_Led7Seg, 100);
				setTimerNO(timer_countY, 1000);
			}
			//Task for this Status
			dispLedY(RED);
			if(timerFlag[timerY_Led7Seg] == 1){
				setTimerNO(timerY_Led7Seg, 100);
				update7segY(count_Y);
				scan7segY();
			}
			if(timerFlag[timer_countY] == 1){
				setTimerNO(timer_countY, 1000);
				count_Y--;
			}
			break;
		case YELLOW:
			//Next Status
			if (timerFlag[timerY_LED] == 1){
				status_Y = RED;
				count_Y = red_Value;
				setTimerNO(timerY_LED, red_Value * 1000);
				setTimerNO(timerY_Led7Seg, 100);
				setTimerNO(timer_countY, 1000);
			}
			//Task for this Status
			dispLedY(YELLOW);
			if(timerFlag[timerY_Led7Seg] == 1){
				setTimerNO(timerY_Led7Seg, 100);
				update7segY(count_Y);
				scan7segY();
			}
			if(timerFlag[timer_countY] == 1){
				setTimerNO(timer_countY, 1000);
				count_Y--;
			}
			break;
		case GREEN:
			//Next Status
			if (timerFlag[timerY_LED] == 1){
				status_Y = YELLOW;
				count_Y = yellow_Value;
				setTimerNO(timerY_LED, yellow_Value * 1000);
				setTimerNO(timerY_Led7Seg, 100);
				setTimerNO(timer_countY, 1000);
			}
			//Task for this Status
			dispLedY(GREEN);
			if(timerFlag[timerY_Led7Seg] == 1){
				setTimerNO(timerY_Led7Seg, 100);
				update7segY(count_Y);
				scan7segY();
			}
			if(timerFlag[timer_countY] == 1){
				setTimerNO(timer_countY, 1000);
				count_Y--;
			}
			break;
		default:
			break;
	}
}

void mode_button_scan(){
	if(isButtonNOPressed(0) == 1){
		red_Draft = red_Value;
		yellow_Draft = yellow_Value;
		green_Draft = green_Value;
		dispLedX(NONE);
		dispLedY(NONE);
		switch(status){
			case MODE1:
				status = MODE2;
				break;
			case MODE2:
				status = MODE3;
				break;
			case MODE3:
				status = MODE4;
				break;
			case MODE4:
				status = MODE1;
				status_X = INIT;
				status_Y = INIT;
				break;
			default:
				break;
		}
	}
}

void increase_button_scan(){
	if(isButtonNOPressed(1) == 1){
		switch (status) {
			case MODE2:
				red_Draft++;
				if (red_Draft > 99) red_Draft = 1;
				break;
			case MODE3:
				yellow_Draft++;
				if (yellow_Draft > 99) yellow_Draft = 1;
				break;
			case MODE4:
				green_Draft++;
				if (green_Draft > 99) green_Draft = 1;
				break;
			default:
				break;
		}
	}
}


void set_button_scan(){
	if(isButtonNOPressed(2) == 1){
		switch (status) {
			case MODE2:
				red_Value = red_Draft;
				green_Value = red_Value - yellow_Value;
				break;
			case MODE3:
				yellow_Value = yellow_Draft;
				green_Value = red_Value - yellow_Value;
				break;
			case MODE4:
				green_Value = green_Draft;
				red_Value = yellow_Value + green_Value;
				break;
			default:
				break;
		}
	}
}

void fsm_led_blink()
{
	switch (status) {
		case MODE2:
			blink_Led(RED);
			//if(timerFlag[timerX_Led7Seg] == 1){
				//setTimerNO(timerX_Led7Seg, 10);
				update7segX(red_Draft);
				scan7segX();
			//}
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN2_Pin, LED_OFF);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, LED_ON);
			disp7segY(2);
			HAL_Delay(500);
			break;
		case MODE3:
			blink_Led(YELLOW);
			//if(timerFlag[timerX_Led7Seg] == 1){
				//setTimerNO(timerX_Led7Seg, 10);
				update7segX(yellow_Draft);
				scan7segX();
			//}
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN2_Pin, LED_OFF);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, LED_ON);
			disp7segY(3);
			HAL_Delay(500);
			break;
		case MODE4:
			blink_Led(GREEN);
			//if(timerFlag[timerX_Led7Seg] == 1){
				//setTimerNO(timerX_Led7Seg, 10);
				update7segX(green_Draft);
				scan7segX();
			//}
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN2_Pin, LED_OFF);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, LED_ON);
			disp7segY(4);
			HAL_Delay(500);
			break;
		default:
			break;
	}
}

#endif /* SRC_FSM_C_ */
