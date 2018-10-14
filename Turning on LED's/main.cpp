#include "stm32f10x.h"                  // Device header

int main(void)
{
	//init PortA
	RCC->APB2ENR |=(1<<2);
	
	// PortA GPIO su output-i
	GPIOA->CRL &= ~((1<<2)|(1<<3));
	GPIOA->CRL &= ~((1<<6)|(1<<7));
	GPIOA->CRL &= ~((1<<10)|(1<<11));
	GPIOA->CRL &= ~((1<<14)|(1<<15));
	GPIOA->CRL &= ~((1<<18)|(1<<19));

	
	GPIOA->CRL |= (1<<1);
	GPIOA->CRL |= (1<<5);
	GPIOA->CRL |= (1<<9);
	GPIOA->CRL |= (1<<13);
	GPIOA->CRL |= (1<<17);



	while(1)
	{
		GPIOA ->BSRR=(1<<0);//Set pinA0 HIGH
		for(int i=0;i<5;i++);
		GPIOA ->BSRR=(1<<1);//Set pinA1HIGH
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<2);//Set pinA2HIGH
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<3);//Set pinA3HIGH
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<4);//Set pinA4HIGH
		for(int i=0;i<1000000;i++);

		
		
		
		GPIOA ->BSRR=(1<<16);//Set pinA0
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<17);//Set pinA1
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<18);//Set pinA2
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<19);//Set pinA3
		for(int i=0;i<1000000;i++);
		GPIOA ->BSRR=(1<<20);//Set pinA4
		for(int i=0;i<1000000;i++);
	}
	
	}
	
	