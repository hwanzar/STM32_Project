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


void fsm_auto(){
	switch(state){
		case INIT:
			resetLED();
//			timeWay1 = timeRed/timeCycle;
//			timeWay2 = timeGreen/timeCycle;
			state = RED1_GREEN2;
			setTimer(0, timeGreen);
			onRed1();
			onGreen2();
//			setTimer(1, 100);// timer for 7SEG
			break;
		case RED1_GREEN2:
			onRed1();
			onGreen2();
			if(timer_flag[0]){
				state = RED1_YELLOW2;
				setTimer(0, timeYellow);
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
				setTimer(0, timeGreen);
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
			if(timer_flag[0]){
				state = YELLOW1_RED2;
				setTimer(0, timeYellow);
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
			if(timer_flag[0]){
				state = RED1_GREEN2;
				setTimer(0, timeGreen);
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
		case MAN_GR:
			if(isButtonPressed(1)){
				state = MAN_RG;
				onRed1();
				onGreen2();
			}
	}
}
