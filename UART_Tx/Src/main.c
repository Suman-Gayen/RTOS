#include <stdint.h>

#include "uart.h"

int main(void)
{
	uart_init(115200);
	while(1){
		for(int i=0;i<500000;i++);
		uart_transfer("Suman \n");
	}

}
