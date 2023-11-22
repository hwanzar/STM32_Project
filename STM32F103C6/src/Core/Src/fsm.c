/*
 * fsm.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Lenovo
 */


#include "fsm.h"


void auto_man(){
	if (isButtonPressed(0) == 1) {
		resetLED();
		reset7SEG();
		state = MAN_RG;
		onRed1();
		onGreen2();
	}
}
void man_tuning(){
	if(isButtonPressed(0) == 1){
		resetLED();
		reset7SEG();
		state = MOD_RED;
		onRed1();
		onRed2();
	}
}
void tuning_auto(){
	if(isButtonPressed(0) == 1){
		resetLED();
		reset7SEG();
		timeYellow = timeRed - timeGreen;
		state = RED1_GREEN2;
		onRed1();
		onGreen2();
	}
}

void fsm_auto(){
	switch(state){
		case INIT:
			resetLED();
//			timeWay1 = timeRed/timeCycle;
//			timeWay2 = timeGreen/timeCycle;
			state = RED1_GREEN2;
			setTimer(0, 300);

//			setTimer(1, 100);// timer for 7SEG
			break;
		case RED1_GREEN2:
			onRed1();
			onGreen2();
			if(timer_flag[0]){
				state = RED1_YELLOW2;
				setTimer(0, 200);
			}
//			if(timer_flag[1]){
//				setTimer(1, 100);
//				timeWay1--;
//				timeWay2--;
//				if(timeWay2 <= 0) timeWay2 = timeYellow / timeCycle;
//			}
			auto_man();
			break;
		case RED1_YELLOW2:
			onRed1();
			onYellow2();
			if(timer_flag[0]){
				state = GREEN1_RED2;
				setTimer(0, 300);
			}
//			if(timer_flag[1]){
//				setTimer(1, 100);
//				timeWay1--;
//				if(timeWay1 <= 0) timeWay1 = timeGreen / timeCycle;
//				timeWay2--;
//				if(timeWay2 <= 0) timeWay2 = timeRed / timeCycle;
//			}
			auto_man();
			break;
		case GREEN1_RED2:
			onRed2();
			onGreen1();
			if(timer_flag[0]){
				state = YELLOW1_RED2;
				setTimer(0, 200);
			}
//			if(timer_flag[1]){
//				setTimer(1, 100);
//				timeWay1--;
//				timeWay2--;
//				if(timeWay1 <= 0) timeWay1 = timeYellow / timeCycle;
//			}
			auto_man();
			break;
		case YELLOW1_RED2:
			onYellow1();
			onRed2();
			if(timer_flag[0]){
				state = RED1_GREEN2;
				setTimer(0, 300);
			}
//			if(timer_flag[1]){
//				setTimer(1, 100);
//				timeWay1--;
//				if(timeWay1 <= 0) timeWay1 = timeRed / timeCycle;
//				timeWay2--;
//				if(timeWay2 <= 0) timeWay2 = timeGreen / timeCycle;
//			}
			auto_man();
			break;
		default:
			break;
	}
}

void fsm_manual(){
	switch(state){
		case MAN_RG:
			if(isButtonPressed(1)){
				state = MAN_GR;
				onRed2();
				onGreen1();
			}
			man_tuning();
			break;
		case MAN_GR:
			if(isButtonPressed(1)){
				state = MAN_RG;
				onRed1();
				onGreen2();
			}
			man_tuning();
			break;
		default:
			break;
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
			}
			if(isButtonPressed(2) == 1){
				time_red++;
				if(time_red >= 10) time_red =  5;
				timeWay1 = time_red;
			}
			if(isButtonPressed(3)){
				timeRed = time_red*timeCycle;
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
			}
			if(isButtonPressed(2) == 1){
				time_yellow++;
				if(time_yellow >= 10) time_yellow =  2;
				timeWay1 = time_yellow;
			}
			if(isButtonPressed(3)){
				timeYellow = time_yellow*timeCycle;
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
			}
			if(isButtonPressed(2) == 1){
				time_green++;
				if(time_green >= 10) time_green =  3;
				timeWay1 = time_green;
			}
			if(isButtonPressed(3)){
				timeGreen = time_green*timeCycle;
			}
			tuning_auto();
			break;
	}
}
