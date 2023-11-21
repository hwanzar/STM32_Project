/*
 * 7SEG_control.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Lenovo
 */


#include "7SEG_control.h"

void reset7SEG(){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, 1);
}

void display7SEG(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB,SEG1_Pin|SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin|SEG5_Pin, 1);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB,SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, 1);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB,SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, 1);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG4_Pin, 1);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB,SEG4_Pin, 1);
			break;
	}
}

void switch7SEG(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, 1);
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, 1);
			break;
	}
	display7SEG(buffer7SEG[index]);
}
