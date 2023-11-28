/*
 * button.h
 *
 *  Created on: Nov 28, 2023
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
int isButtonPressed(int num);

#endif /* INC_BUTTON_H_ */
