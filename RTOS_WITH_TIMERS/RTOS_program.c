/*
 * RTOS_program.c
 *
 *  Created on: 10 Nov 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RTOS_config.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"

void Task_Create(u8 priority,u32 periodicity,void (*FPTR)(void),u32 first_delay)
{
	Task_arr[priority].periodicity = periodicity;
	Task_arr[priority].first_delay = first_delay;
	Task_arr[priority].FPTR = FPTR;
}
void RTOS_Init(void)
{
	u32 i = 0;
	for(i = 0;i <NO_TASKS;i++)
	{
		Task_arr[i].periodicity = 0;
		//Task_arr[i].first_delay = 0;
		Task_arr[i].FPTR = NULL;
	}
}
void Schedular(void)
{
	u32 i = 0;
	for(i = 0;i <NO_TASKS;i++)
	{
		if(TICK_COUNTER % Task_arr[i].periodicity == 0)
		{
			Task_arr[i].FPTR();
			Task_arr[i].first_delay = Task_arr[i].periodicity -1;
		}
		else
		{
			Task_arr[i].first_delay--;
		}
		TICK_COUNTER++;
	}
}
