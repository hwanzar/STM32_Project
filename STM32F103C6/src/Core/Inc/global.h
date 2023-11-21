/*
 * global.h
 *
 *  Created on: Nov 18, 2023
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


void updateBuffer(int a, int b);

#endif /* INC_GLOBAL_H_ */
