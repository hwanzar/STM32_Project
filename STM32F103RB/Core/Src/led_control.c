/*
 * led_control.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Lenovo
 */

#include "led_control.h"
void resetLED(){
	HAL_GPIO_WritePin(LED_00_GPIO_Port, LED_00_Pin, 0);
	HAL_GPIO_WritePin(LED_01_GPIO_Port, LED_01_Pin, 0);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, 0);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, 0);
}
void onRed1(){
	HAL_GPIO_WritePin(LED_00_GPIO_Port, LED_00_Pin, 1);
	HAL_GPIO_WritePin(LED_01_GPIO_Port, LED_01_Pin, 0);
}
void onYellow1(){
	HAL_GPIO_WritePin(LED_00_GPIO_Port, LED_00_Pin, 1);
	HAL_GPIO_WritePin(LED_01_GPIO_Port, LED_01_Pin, 1);
}
void onGreen1(){
	HAL_GPIO_WritePin(LED_00_GPIO_Port, LED_00_Pin, 0);
	HAL_GPIO_WritePin(LED_01_GPIO_Port, LED_01_Pin, 1);
}

void onRed2(){
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, 1);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, 0);
}
void onYellow2(){
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, 1);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, 1);
}
void onGreen2(){
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, 0);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, 1);
}
