/*
 * uart.h
 *
 *  Created on: Mar 14, 2026
 *      Author: Suman Gayen
 */

#ifndef UART_H_
#define UART_H_

extern void uart_init();
extern void uart_transfer(char *);
extern void uart_write(unsigned char data);

#endif /* UART_H_ */
