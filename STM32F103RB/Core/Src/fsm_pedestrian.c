/*
 * fsm_pedestrian.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */
#include "fsm_pedestrian.h"
void syncLED(){
	if(state == RED1_GREEN2 || state == RED1_YELLOW2){
		pedRed();
	}
	else if(state == GREEN1_RED2 || state == YELLOW1_RED2){
		pedGreen();
	}
}
void fsm_pedestrian(){
	switch(ped_state){
		case PED_OFF:
			pedReset();
			if(isButtonPressed(3)){
				ped_state = PED_INIT;
			}
			break;
		case PED_INIT:
			setTimer(1, 1000);
			ped_state = PED_ACTIVE;
			break;
		case PED_ACTIVE:
			syncLED();
			if(timer_flag[1]){
				ped_state = PED_OFF;
			}
			break;
		default:
			break;
	}
}
