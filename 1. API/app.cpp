#include "stm32f10x.h"                  // Device header
#include "STM32.h"

int main(){
	
	clock_enable(GPIOC, ENABLE);
	pinMode(GPIOC, C13, OUTPUT);
	
	while(1){
	
		digitalWrite(GPIOC, C13, HIGH);
	}

	return 0;
}