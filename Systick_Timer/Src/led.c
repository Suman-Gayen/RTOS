/*
 * led.c
 *
 *  Created on: Mar 14, 2026
 *      Author: Suman Gayen
 */
#include "led.h"

void led_init(){
	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (1<<10);
	GPIOA->MODER &= (~(1<<11));
}
void led_on(){
	GPIOA->ODR |= (1<<5);
}
void led_off(){
	GPIOA->ODR &= (~(1<<5));
}

