	/*
 * fsm_tuning.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */

#include "fsm_tuning.h"
#include "main.h"
#include "stdio.h"
#include "stdlib.h"

char str[40];

void tuning_auto(){
	if(isButtonPressed(0) == 1){
		resetLED();
//		reset7SEG();
		timeYellow = timeRed - timeGreen;
		state = RED1_GREEN2;
		setTimer(4,2);
//		onRed1();
//		onGreen2();
	}
}

void fsm_tuning(){
	switch(state){
		case MOD_RED:
			if(timer_flag[4] == 1){
				setTimer(4,25);
				if(blink == 0){
					onRed1(); // MOD_RED
					onRed2();
					blink = 1;
				}
				else{
					resetLED();
					blink = 0;
				}
			}
			if(isButtonPressed(1)){
				state = MOD_YELLOW;
				setTimer(4,25);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Yellow\r\nTime: %d\r\n",timeYellow/timeCycle), 200);
			}
			if(isButtonPressed(2) == 1){
				time_red++;
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Red\r\nIncrease time to: %d\r\n",time_red), 200);
				if(time_red >= 10) time_red =  5;
				timeWay1 = time_red;
			}
			if(isButtonPressed(3)){
				timeRed = time_red*timeCycle;
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Red\r\nTime set to: %d\r\n",time_red), 200);
			}
			tuning_auto();
			break;
		case MOD_YELLOW:
			if(timer_flag[4] == 1){
				setTimer(4,25);
				if(blink == 0){
					onYellow1(); // MOD_YELLOW
					onYellow2();
					blink = 1;
				}
				else{
					resetLED();
					blink = 0;
				}
			}
			if(isButtonPressed(1)){
				state = MOD_GREEN;
				setTimer(4,25);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Green\r\nTime: %d\r\n",timeGreen/timeCycle), 200);
			}
			if(isButtonPressed(2) == 1){
				time_yellow++;
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Yellow\r\nIncrease time to: %d\r\n",time_yellow), 200);
				if(time_yellow >= 10) time_yellow =  2;
				timeWay1 = time_yellow;
			}
			if(isButtonPressed(3)){
				timeYellow = time_yellow*timeCycle;
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Yellow\r\nTime set to: %d\r\n",time_yellow), 200);
			}
			tuning_auto();
			break;
		case MOD_GREEN:
			if(timer_flag[4] == 1){
				setTimer(4,25);
				if(blink == 0){
					onGreen1(); // MOD_GREEN
					onGreen2();
					blink = 1;
				}
				else{
					resetLED();
					blink = 0;
				}
			}
			if(isButtonPressed(1)){
				state = MOD_RED;
				setTimer(4,25);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Red\r\nTime: %d\r\n",timeRed/timeCycle), 200);
			}
			if(isButtonPressed(2) == 1){
				time_green++;
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Green\r\nIncrease time to: %d\r\n",time_green), 200);
				if(time_green >= 10) time_green =  3;
				timeWay1 = time_green;
			}
			if(isButtonPressed(3)){
				timeGreen = time_green*timeCycle;
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Tuning: Green\r\nTime set to: %d\r\n",time_green), 200);
			}
			tuning_auto();
			break;
	}
}
