/*
 * button.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Lenovo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button_flag[4];
extern int TimeOutForKeyPress[4];

void getKeyInput();
int isButtonPressed(int i);

#endif /* INC_BUTTON_H_ */
