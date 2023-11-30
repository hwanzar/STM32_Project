/*
 * fsm_pedestrian.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */

#ifndef INC_FSM_PEDESTRIAN_H_
#define INC_FSM_PEDESTRIAN_H_
#include "global.h"
#include "led_control.h"
#include "button.h"
#include "software_timer.h"
#include "main.h"

void syncLED();
void fsm_pedestrian();
void buzzer();
void buzzer_off();
#endif /* INC_FSM_PEDESTRIAN_H_ */
