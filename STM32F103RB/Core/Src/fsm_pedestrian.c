/*
 * fsm_pedestrian.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */
#include "fsm_pedestrian.h"

void syncLED(){
	if(state == RED1_GREEN2 || state == RED1_YELLOW2 ){
		pedRed();
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
	else if(state == GREEN1_RED2 || state == YELLOW1_RED2 ){
		pedGreen();

//		if(timeWay2 <= 3 && timeWay2 >=0){
////			int i = 20;
////			setTimer(3, i);
////			if(timer_flag[3]){
////				setTimer(3, i);
////				buzzer();
//////				if(i == 0){
//////					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
//////				}
////				i -= 4;
////			}
////			setTimer(3, 50);
//			if(timer_flag[3]){
//				setTimer(3, 50);
//				buzzer();
//			}
//
//		}

	}
}
void fsm_pedestrian(){
	switch(ped_state){
		case PED_OFF:
			pedReset();
			if(ped_flag){
				ped_state = PED_INIT;
			}
			break;
		case PED_INIT:
			setTimer(2, 1000);
			ped_state = PED_ACTIVE;
			break;
		case PED_ACTIVE:
			syncLED();
			if(timer_flag[2]){
				ped_state = PED_OFF;
				ped_flag = 0;
			}
			break;
		default:
			break;
	}
}
void buzzer(){
	if(buzzer_flag == 1){
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 100);
	}
	else if(buzzer_flag == 0){
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
	buzzer_flag = 1 - buzzer_flag;
}
void buzzer_off(){
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
}

