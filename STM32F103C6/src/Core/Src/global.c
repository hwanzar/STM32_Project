/*
 * global.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Lenovo
 */


#include "global.h"



finState state = INIT;

const int timeCycle = 1000/TIMER_INTERRUPT_PERIOD;

//int currentDuration = timeRed*timeCycle;

int timeRed = 5*timeCycle;
int timeGreen = 3*timeCycle;
int timeYellow = 2*timeCycle;
// *100 if applied setTimer(0, timeRed*100);

int time_red = 5;
int time_green = 3;
int time_yellow = 2;


int buffer7SEG[4] = {0,0,0,0};
int index7SEG = 0;
int timeWay1 = 0;
int timeWay2 = 0;
int blink = 0;
void updateBuffer(int a, int b){
	buffer7SEG[0] = a/10;
	buffer7SEG[1] = a%10;
	buffer7SEG[2] = b/10;
	buffer7SEG[3] = b%10;
}

