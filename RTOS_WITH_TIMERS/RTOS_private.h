/*
 * RTOS_private.h
 *
 *  Created on: 10 Nov 2023
 *      Author: Ali
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


typedef struct
{
	u32 periodicity;
	u32 first_delay;
	void (*FPTR)(void);
}Task;


Task Task_arr[NO_TASKS];

u32 TICK_COUNTER = 0;

#endif /* RTOS_PRIVATE_H_ */
