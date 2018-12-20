#include "stm32f10x.h"                  // Device header

int sviBrojevi[]={0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F}; //sa zajednickom katodom, nula pali

void PortA_output(int pocetak, int kraj){


		for(int i=pocetak;i<=kraj;i++){
	
		GPIOA->CRL&=((1<<(i*4+2))|(1<<(i*4+3)));
	}
	
	for(int i=pocetak;i<=kraj;i++){
	
		GPIOA->CRL|=(1<<(i*4+1));
	}

}

void PortB_output(int pocetak, int kraj){


	for(int i=pocetak;i<=kraj;i++){
	
		GPIOB->CRL&=((1<<(i*4+2))|(1<<(i*4+3)));
	}
	
	for(int i=pocetak;i<=kraj;i++){
	
		GPIOB->CRL|=(1<<(i*4+1));
	}

}
void ispisBroja(int broj)
	
{
	
	GPIOA ->BSRR=sviBrojevi[broj];
	
}

void delay(){

	for(int i=0;i<50000;i++);

}

void restartovanje()
	
{
	
	for(int i=16;i<32;i++)
		GPIOA -> BSRR |=(1<<i);
	
}

int main(){


	RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
	

	PortB_output(0, 1);

	PortA_output(0, 6);	
		
	while(1)

{
	

	for(int k=0;k<10;k++){
	for(int p=0;p<10;p++){
	
				
		for(int i=0;i<100;i++){
			
		GPIOB->BSRR|=(1<<0);
		ispisBroja(p);
		delay();
			
		GPIOB->BSRR|=(1<<16);
		restartovanje();
		
		
			
		GPIOB->BSRR|=(1<<1);
		ispisBroja(k);
		delay();
			
		GPIOB->BSRR|=(1<<17);
		restartovanje();
			
		}
		}
	}
}
}
