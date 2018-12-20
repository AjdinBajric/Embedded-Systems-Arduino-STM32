#include "stm32f10x.h"                  // Device header

int bits[7];

void PortA_output(int pocetak, int kraj){


	for(int i=pocetak;i<=kraj;i++){
	
		GPIOA->CRL&=((1<<(i*4+2))|(1<<(i*4+3)));
	}
	
	for(int i=pocetak;i<=kraj;i++){
	
		GPIOA->CRL|=(1<<(i*4+1));
	}

}

void delay(){

	for(int i=0;i<1000000;i++);
}

void resetPins(){

		for(int h=16;h<=21;h+=4){
		
			RCC->APB2ENR|=(1<<h);
		}
		
}
int main(){

	RCC->APB2ENR|=(1<<2);
	
	PortA_output(0,5);
	
while(1){

	int mask = 1, count = 0,y;

	for(int j=0;j<65;j++){
		count = 0,y=j;
		
    for (int i = 0; i < 32; i++) {
			
      if ((y & mask) == 1)				
        bits[count]=1;
				count++;
				y >>= 1;
			
    }

    for(int i=0;i<6;i++){

    if(bits[i]==1)GPIOA->BSRR|=(1<<i);
			
		else GPIOA->BSRR|=(1<<(i+16));
			
		}
		
		delay();
			
		for(int g=0;g<6;g++){
			
			bits[g]=0;
		
		}
		
		resetPins();
		delay();		
}	
}
}