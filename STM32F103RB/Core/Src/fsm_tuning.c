/*
 * fsm_tuning.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */

#include "fsm_tuning.h"
//void fsm_tuning(){
//	switch(state){
//		case MOD_RED:
//			if(timer_flag[4] == 1){
//				setTimer(4,25);
//				if(blink == 0){
//					onRed1(); // MOD_RED
//					onRed2();
//					blink = 1;
//				}
//				else{
//					resetLED();
//					blink = 0;
//				}
//			}
//			if(isButtonPressed(1)){
//				state = MOD_YELLOW;
//				setTimer(4,25);
//			}
//			if(isButtonPressed(2) == 1){
//				time_red++;
//				if(time_red >= 10) time_red =  5;
//				timeWay1 = time_red;
//			}
//			if(isButtonPressed(3)){
//				timeRed = time_red*timeCycle;
//			}
//			tuning_auto();
//			break;
//		case MOD_YELLOW:
//			if(timer_flag[4] == 1){
//				setTimer(4,25);
//				if(blink == 0){
//					onYellow1(); // MOD_YELLOW
//					onYellow2();
//					blink = 1;
//				}
//				else{
//					resetLED();
//					blink = 0;
//				}
//			}
//			if(isButtonPressed(1)){
//				state = MOD_GREEN;
//				setTimer(4,25);
//			}
//			if(isButtonPressed(2) == 1){
//				time_yellow++;
//				if(time_yellow >= 10) time_yellow =  2;
//				timeWay1 = time_yellow;
//			}
//			if(isButtonPressed(3)){
//				timeYellow = time_yellow*timeCycle;
//			}
//			tuning_auto();
//			break;
//		case MOD_GREEN:
//			if(timer_flag[4] == 1){
//				setTimer(4,25);
//				if(blink == 0){
//					onGreen1(); // MOD_GREEN
//					onGreen2();
//					blink = 1;
//				}
//				else{
//					resetLED();
//					blink = 0;
//				}
//			}
//			if(isButtonPressed(1)){
//				state = MOD_RED;
//				setTimer(4,25);
//			}
//			if(isButtonPressed(2) == 1){
//				time_green++;
//				if(time_green >= 10) time_green =  3;
//				timeWay1 = time_green;
//			}
//			if(isButtonPressed(3)){
//				timeGreen = time_green*timeCycle;
//			}
//			tuning_auto();
//			break;
//	}
//}
