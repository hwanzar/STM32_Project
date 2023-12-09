/*
 * scheduler.c
 *
 *  Created on: Nov 13, 2023
 *      Author: hhaof
 */

#include "scheduler.h"
#include "main.h"
#include "stdio.h"
#include "stdlib.h"

struct sTask{
	struct sTask *left, *right;
	void (*funcPointer)();
	uint32_t delay, period, taskID;
	uint8_t run_flag;
}*sTaskList = 0;

char str[100];
uint8_t tracker[MAX_SCHEDULER_TASKS], mutex_lock;

void SCH_Find_Position(struct sTask *index){
	if(index == sTaskList){
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "FIND POSITION: only 1 task\r\n"), 200);
		return;
	}
	struct sTask *iterator = sTaskList;
	//Not yet found position
	uint8_t check = 0;
	while(iterator->delay <= index->delay){
		if(iterator == sTaskList) check += 1;
		if(check == 2) break;
		index->delay -= iterator->delay;
		iterator = iterator->right;
	}
	//Found position
	if(index->delay == 0) index->run_flag = 1;
	index->right = iterator;
	index->left = iterator->left;
	iterator->left->right = index;
	iterator->left = index;
	//Update the immediately after
	if(iterator != sTaskList){
		iterator->delay -= index->delay;
		if(iterator->delay == 0) iterator->run_flag = 1;
	}
	//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "FIND POSITION: %lu %lu\r\n", index->taskID, index->delay), 200);
	//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "FIND POSITION: Before %lu %lu\r\n", index->left->taskID, index->left->delay), 200);
	//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "FIND POSITION: After %lu %lu\r\n", index->right->taskID, index->right->delay), 200);
}

int SCH_Add_Task(void (*funcPointer)(), uint32_t delay, uint32_t period){
	if(!funcPointer){
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "ADD TASK: Function pointer invalid\r\n"), 200);
		return -1;
	}
	uint32_t runnerID = 0;
	while((runnerID < MAX_SCHEDULER_TASKS) && (tracker[runnerID])){
		runnerID += 1;
	}
	if(runnerID == MAX_SCHEDULER_TASKS){
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "ADD TASK: Scheduler full\r\n"), 200);
		return -1;
	}else tracker[runnerID] = 1;
	mutex_lock = 1;
	struct sTask *curTask = (struct sTask*)malloc(sizeof(struct sTask));
	curTask->delay = delay/TIMER_INTERRUPT_PERIOD;
	curTask->period = period/TIMER_INTERRUPT_PERIOD;
	curTask->funcPointer = funcPointer;
	curTask->taskID = runnerID;
	curTask->run_flag = 0;
	if(sTaskList){
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "ADD TASK: Added %lu\r\n", curTask->taskID), 200);
		SCH_Find_Position(curTask);
	}else{
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "ADD TASK: Added first %lu\r\n", curTask->taskID), 200);
		curTask->left = curTask;
		curTask->right = curTask;
		sTaskList = curTask;
	}
	mutex_lock = 0;
	return runnerID;
}

void SCH_Update(){
	if((sTaskList) && (!sTaskList->run_flag) && (!mutex_lock)){
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "UPDATE: %lu\r\n", sTaskList->taskID), 50);
		if(sTaskList->delay > 0) sTaskList->delay -= 1;
		if(sTaskList->delay <= 0) sTaskList->run_flag = 1;
	}
}

void SCH_Dispatch_Tasks(){
	mutex_lock = 1;
	while((sTaskList) && (sTaskList->run_flag)){
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "DISPATCH: Task executing %lu\r\n", sTaskList->taskID), 200);
		(*sTaskList->funcPointer)();
		if(sTaskList->period == 0){
			struct sTask *toDelete = sTaskList;
			sTaskList = sTaskList->right;
			SCH_Delete_Task(toDelete->taskID);
		}else{
			struct sTask *toFind = sTaskList;
			sTaskList->right->left = sTaskList->left;
			sTaskList->left->right = sTaskList->right;
			sTaskList = sTaskList->right;
			toFind->run_flag = 0;
			toFind->delay = toFind->period;
			SCH_Find_Position(toFind);
		}
	}
	mutex_lock = 0;
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}

void SCH_Delete_Task(uint32_t index){
	if(tracker[index]){
		tracker[index] = 0;
		struct sTask *iterator = sTaskList;
		if(iterator->left == iterator){
			sTaskList=0;
		}else{
			while(iterator->taskID != index){
				iterator = iterator->right;
			}
			iterator->right->left = iterator->left;
			iterator->left->right = iterator->right;
		}		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "DELETE: Free %lu\r\n", iterator->taskID), 200);
		free(iterator);
	}else{
		//HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "DELETE: Position empty\r\n"), 200);
	}
}

/*void SCH_Force_End(){
	if(sTaskList)return;
	while(sTaskList->right != sTaskList){
		struct sTask *toDelete = sTaskList->right;
		sTaskList->right = toDelete->right;
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "FORCE END: Free %lu\r\n", toDelete->taskID), 200);
		free(toDelete);
	}
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "FORCE END: Free final %lu\r\n", sTaskList->taskID), 200);
	free(sTaskList);
}*/
