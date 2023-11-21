/*
 * led_control.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Lenovo
 */
#include "led_control.h"


void resetLED(){
	HAL_GPIO_WritePin(GPIOA, RED1_Pin | RED2_Pin | YELLOW1_Pin | YELLOW2_Pin | GREEN1_Pin | GREEN2_Pin, 0);
}

void onRed1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
}
void onYellow1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
}
void onGreen1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
}
void onRed2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
}
void onYellow2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
}
void onGreen2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
}
