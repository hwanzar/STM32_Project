/*
 * global.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */


#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "main.h"

#define TIMER_INTERRUPT_PERIOD	10

typedef enum {
	INIT,
	RED1_GREEN2,
	RED1_YELLOW2,
	GREEN1_RED2,
	YELLOW1_RED2,

	// manual
	MAN_RG,
	MAN_GR,

	// Tuning
	MOD_RED,
	MOD_YELLOW,
	MOD_GREEN,
} finState;

extern finState state;

extern const int timeCycle;

extern int timeRed;
extern int timeYellow;
extern int timeGreen;
//for tuning mode to update default value (timeRed = time_red;)
extern int time_red, time_yellow, time_green;

extern int buffer7SEG[4];
extern int index7SEG;
extern int timeWay1;
extern int timeWay2;
extern int blink;
extern int ped_flag;
extern int buzzer_flag;
#define PED_INIT 10
#define PED_ACTIVE 11
#define PED_OFF 12
extern int ped_state;
extern int i;
extern int volume[4];
void updateBuffer(int a, int b);
void clearScreen();

#endif /* INC_GLOBAL_H_ */
