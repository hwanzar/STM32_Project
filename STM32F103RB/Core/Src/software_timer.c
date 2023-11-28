
/*
 * software_timer.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Lenovo
 */




#include "software_timer.h"

int timer_flag[10] = {0};
int timer_cnt[10] = {0};

void setTimer(int i, int duration){
	timer_flag[i] = 0;
	timer_cnt[i] = duration;
}

void timer_run(int i){
	if(timer_cnt[i] > 0){
		timer_cnt[i]--;
		if(timer_cnt[i] <= 0) timer_flag[i] = 1;
	}
}

void timerRun(){
	timer_run(0);
	timer_run(1);
//	timer_run(2);
//	timer_run(3);
	timer_run(4);
}
