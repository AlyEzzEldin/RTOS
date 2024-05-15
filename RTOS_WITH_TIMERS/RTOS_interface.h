/*
 * RTOS_interface.h
 *
 *  Created on: 10 Nov 2023
 *      Author: Ali
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void Task_Create(u8 priority,u32 periodicity,void (*FPTR)(void),u32 first_delay);
void RTOS_Init(void);
void Schedular(void);

#endif /* RTOS_INTERFACE_H_ */
