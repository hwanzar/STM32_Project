/*
 * fsm_auto.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */



#include "fsm_auto.h"

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
			break;
		case RED1_YELLOW2:
			onRed1();
			onYellow2();
			if(timer_flag[0]){
				state = GREEN1_RED2;
				setTimer(0, timeGreen);
			}
			break;
		case GREEN1_RED2:
			onGreen1();
			onRed2();
			if(timer_flag[0]){
				state = YELLOW1_RED2;
				setTimer(0, timeYellow);
			}
			break;
		case YELLOW1_RED2:
			onYellow1();
			onRed2();
			if(timer_flag[0]){
				state = RED1_GREEN2;
				setTimer(0, timeGreen);
			}
			break;
		default:
			break;
	}
}

