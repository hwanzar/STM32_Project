/*
 * fsm_auto.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */



#include "fsm_auto.h"

void auto_man(){
	if (isButtonPressed(0) == 1) {
		resetLED();
//		reset7SEG();
		state = MAN_RG;
		onRed1();
		onGreen2();
	}
}
void man_tuning(){
	if(isButtonPressed(0) == 1){
		resetLED();
//		reset7SEG();
		state = MOD_RED;
		onRed1();
		onRed2();
	}
}
void tuning_auto(){
	if(isButtonPressed(0) == 1){
		resetLED();
//		reset7SEG();
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
			state = RED1_GREEN2;
			setTimer(0, timeGreen);
			break;
		case RED1_GREEN2:
			onRed1();
			onGreen2();
			if(timer_flag[0]){
				state = RED1_YELLOW2;
				setTimer(0, timeYellow);
			}
			auto_man();
			break;
		case RED1_YELLOW2:
			onRed1();
			onYellow2();
			if(timer_flag[0]){
				state = GREEN1_RED2;
				setTimer(0, timeGreen);
			}
			auto_man();
			break;
		case GREEN1_RED2:
			onGreen1();
			onRed2();
			if(timer_flag[0]){
				state = YELLOW1_RED2;
				setTimer(0, timeYellow);
			}
			auto_man();
			break;
		case YELLOW1_RED2:
			onYellow1();
			onRed2();
			if(timer_flag[0]){
				state = RED1_GREEN2;
				setTimer(0, timeGreen);
			}
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
//			man_tuning();
			tuning_auto();
			break;
		case MAN_GR:
			if(isButtonPressed(1)){
				state = MAN_RG;
				onRed1();
				onGreen2();
			}
//			man_tuning();
			tuning_auto();
			break;
		default:
			break;
	}
}

