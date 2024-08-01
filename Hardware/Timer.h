#ifndef _TIMER_H_
#define _TIMER_H_
#include "stm32f10x.h" // Device header
void Timer_Init(void);
extern u32 timeDht11[2];
extern u32 timedKey[2];
extern u32 timed8266[2];
extern u32 timedAuto[2];
#endif