/*
 * Systick.c
 *
 *  Created on: Mar 14, 2026
 *      Author: Suman Gayen
 */
#include "Systick.h"

volatile unsigned long current_tick;
volatile unsigned long g_current_tick;
volatile unsigned long tick_frequecy = 1;

void Systick_init(void){
	SysTick->LOAD = Timer_Load - 1; // reload timer with number of cycles per second
	SysTick->VAL = 0;         // clear  systick timer value register
	SysTick->CTRL |= (1U<<2); // select 16 000 000 internal clock source
	SysTick->CTRL |= (1U<<1); // enable interrupt
	SysTick->CTRL |= (1U<<0); // enable systick
	__enable_irq();            // enable global interrupt
}
unsigned long get_tick(void){
	__disable_irq();
	current_tick = g_current_tick;
	__enable_irq();
	return current_tick;

}
void delay_ms(unsigned long delay){
	unsigned long tickstart = get_tick();
	unsigned long wait = delay;
	if(wait < 0xFFFFFFFF){     // 0xFFFFFFFF is a range of unsigned int
		wait += (unsigned long)(tick_frequecy);
	}
	while((get_tick() - tickstart) < wait){}
}
void SysTick_Handler(void){
	g_current_tick = g_current_tick + tick_frequecy;
}
