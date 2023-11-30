/*
 * fsm_auto.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */

#include "fsm_auto.h"
#include "fsm_pedestrian.h"
#include "main.h"
#include "stdio.h"
#include "stdlib.h"

char str[40];

void auto_man()
{
	if (isButtonPressed(0) == 1)
	{
		resetLED();
		//		reset7SEG();
		state = MAN_RG;
		onRed1();
		onGreen2();
		HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Manual: Road 1: Red\r\nRoad 2: Green\r\n"), 200);
	}
}
void man_tuning()
{
	if (isButtonPressed(0) == 1)
	{
		resetLED();
		//		reset7SEG();
		state = MOD_RED;
		onRed1();
		onRed2();
		HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Tuning: Red\r\nTime: %d\r\n", timeRed), 200);
	}
}

void fsm_auto()
{
	switch (state)
	{
	case INIT:
		resetLED();
		timeWay1 = timeRed / timeCycle;
		timeWay2 = timeGreen / timeCycle;
		state = RED1_GREEN2;
		setTimer(0, timeGreen);
		setTimer(1, 100);
		break;
	case RED1_GREEN2:
		onRed1();
		onGreen2();
		if (timer_flag[1])
		{
			setTimer(1, 100);
			clearScreen();
			timeWay1--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 1: Red\r\nTime:%d\r\n", timeWay1), 200);
			timeWay2--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 2: Green\r\nTime:%d\r\n", timeWay2), 200);
			if (timeWay2 <= 0)
				timeWay2 = timeYellow / timeCycle;
		}
		if (timer_flag[0])
		{
			state = RED1_YELLOW2;
			setTimer(0, timeYellow);
		}
		if (isButtonPressed(3))
		{
			ped_flag = 1;
		}
		auto_man();
		break;
	case RED1_YELLOW2:
		onRed1();
		onYellow2();
		if (timer_flag[1])
		{
			setTimer(1, 100);
			clearScreen();
			timeWay1--;
			if (timeWay1 <= 0)
				timeWay1 = timeGreen / timeCycle;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 1: Red\r\nTime:%d\r\n", timeWay1), 200);
			timeWay2--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 2: Yellow\r\nTime:%d\r\n", timeWay2), 200);
			if (timeWay2 <= 0)
			{
				timeWay1 = timeGreen / timeCycle;
				timeWay2 = timeRed / timeCycle;
			}
		}
		if (timer_flag[0])
		{
			state = GREEN1_RED2;
			setTimer(0, timeGreen);
		}
		if (isButtonPressed(3))
		{
			ped_flag = 1;
		}
		auto_man();
		break;
	case GREEN1_RED2:
		onGreen1();
		onRed2();
		if (timer_flag[1])
		{
			setTimer(1, 100);
			clearScreen();
			timeWay1--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 1: Green\r\nTime:%d\r\n", timeWay1), 200);
			timeWay2--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 2: Red\r\nTime:%d\r\n", timeWay2), 200);
			if (timeWay1 <= 0)
				timeWay1 = timeYellow / timeCycle;
		}
		if (timer_flag[0])
		{
			i = 50;
			state = YELLOW1_RED2;
			setTimer(0, timeYellow);
		}
		if (isButtonPressed(3))
		{
			ped_flag = 1;
		}
		auto_man();
		break;
	case YELLOW1_RED2:
		onYellow1();
		onRed2();
		if (timer_flag[1])
		{
			setTimer(1, 100);
			clearScreen();
			timeWay1--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 1: Yellow\r\nTime:%d\r\n", timeWay1), 200);
			if (timeWay1 <= 0)
				timeWay1 = timeRed / timeCycle;
			timeWay2--;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Road 2: Red\r\nTime:%d\r\n", timeWay2), 200);
			if (timeWay2 <= 0)
			{
				timeWay1 = timeRed / timeCycle;
				timeWay2 = timeGreen / timeCycle;
			}
		}
		if (timer_flag[0])
		{

			state = RED1_GREEN2;
			setTimer(0, timeGreen);
		}
		if (isButtonPressed(3))
		{
			ped_flag = 1;
		}
		//			if(ped_flag){
		//				if(timeWay2 <= 3){
		//					if(timer_flag[3] == 1){
		//						buzzer(volume[timeWay2--]);
		//						setTimer(3, i);
		//						i = i-5;
		//						if(i <= 0){
		//							i = 1;
		//						}
		//					}
		//				}
		//			}
		auto_man();
		break;
	default:
		break;
	}
}
void fsm_manual()
{
	switch (state)
	{
	case MAN_RG:
		if (isButtonPressed(1))
		{
			state = MAN_GR;
			onRed2();
			onGreen1();
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Manual: Road 1: Green\r\nRoad 2: Red\r\n"), 200);
		}
		man_tuning();

		break;
	case MAN_GR:
		if (isButtonPressed(1))
		{
			state = MAN_RG;
			onRed1();
			onGreen2();
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Manual: Road 1: Red\r\nRoad 2: Green\r\n"), 200);
		}
		man_tuning();

		break;
	default:
		break;
	}
}
