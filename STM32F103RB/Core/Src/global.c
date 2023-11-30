/*
 * global.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */


#include "global.h"
#include "main.h"
#include "stdio.h"
#include "stdlib.h"



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
int ped_flag = 0;
int ped_state = PED_OFF;
int buzzer_flag = 1;
int i = 30;
void updateBuffer(int a, int b){
	buffer7SEG[0] = a/10;
	buffer7SEG[1] = a%10;
	buffer7SEG[2] = b/10;
	buffer7SEG[3] = b%10;
}

void clearScreen() {
    // ANSI escape code for clearing the screen
    HAL_UART_Transmit(&huart2, (uint8_t*)"\033[2J", 4, HAL_MAX_DELAY);
    // Move the cursor to the top-left corner
    HAL_UART_Transmit(&huart2, (uint8_t*)"\033[H", 3, HAL_MAX_DELAY);
}
