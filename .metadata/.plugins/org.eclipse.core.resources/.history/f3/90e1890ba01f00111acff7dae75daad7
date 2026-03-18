

#include <stdint.h>
#include "led.h"
#include "Systick.h"

int main(void)
{
	led_init();
	Systick_init();
	while(1){
		led_on();
		delay_ms(10000);
//		for(int i=0; i<500000; i++);
		led_off();
		delay_ms(10000);
//		for(int i=0; i<500000; i++);
	}
}
