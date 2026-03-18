/*
 * uart.c
 *
 *  Created on: Mar 14, 2026
 *      Author: Suman Gayen
 */
#include "uart.h"
#include "stm32f446xx.h"

void uart_init(unsigned long baudrate)
{
	RCC->AHB1ENR |= (1<<0); // Enable GPIOA clock
	GPIOA->MODER |= (1<<5);
	GPIOA->MODER &= (~(1<<4)); // Set GPIOA as a alternate function
	RCC->APB1ENR |= (1<<17); // Enable UART clock
	GPIOA->AFR[0] |= (1<<8) | (1<<9) | (1<<10);
	GPIOA->AFR[0] &= (~(1<<11)); // set AF& alt func for PA@ as USART Tx
	USART2->BRR = ((16000000+(baudrate/2U))/baudrate); // Configure baudrate
	USART2->CR1 |= (1<<3); // Configure transfer direction
	USART2->CR1 |= (1<<13); // Enable UART module
}
void uart_transfer(char *buffer)
{
	unsigned char i =0;
	while(buffer[i] != '\0')
	{
		uart_write(buffer[i]);
		i++;
	}

}
void uart_write(unsigned char data)
{
	while(!(USART2->SR & (1<<7)));
	USART2->DR = (data & 0xFF);
}
