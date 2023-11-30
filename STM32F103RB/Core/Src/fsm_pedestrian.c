/*
 * fsm_pedestrian.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */
#include "fsm_pedestrian.h"

int change;

void syncLED()
{
	if (state == RED1_GREEN2 || state == RED1_YELLOW2)
	{
		pedRed();
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
	else if (state == GREEN1_RED2 || state == YELLOW1_RED2)
	{
		pedGreen();
		if (timeWay2 <= 3)
		{
			if (timer_flag[3] == 1)
			{
				buzzer(volume[timeWay2 - 1]);
				setTimer(3, change);
				//				if(i <= 0){
				//					i = 5;
				//				}
			}
			if (timer_flag[9])
			{
				change -= 1;
				setTimer(9, 15);
			}
		}
	}
}
void fsm_pedestrian()
{
	switch (ped_state)
	{
	case PED_OFF:
		pedReset();
		buzzer_off();
		if (ped_flag)
		{
			ped_state = PED_INIT;
		}
		break;
	case PED_INIT:
		setTimer(2, 1000);
		ped_state = PED_ACTIVE;
		change = 20;
		setTimer(9, 1);
		break;
	case PED_ACTIVE:
		syncLED();
		if (timer_flag[2])
		{
			ped_state = PED_OFF;
			ped_flag = 0;
		}
		break;
	default:
		break;
	}
}
void buzzer(int vol)
{
	if (buzzer_flag == 1)
	{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, vol);
	}
	else if (buzzer_flag == 0)
	{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
	buzzer_flag = 1 - buzzer_flag;
}
void buzzer_off()
{
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
}
