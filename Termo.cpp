#include "stm32f10x.h"                  // Device header

int main(){

	
	//enable adc1 in rcc	RCC->APB2ENR|=(1<<9); same as one above
	
	RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;
	
	//set adc clock -> cpgr prescaler 
	
	RCC->CFGR|=((1<<14)|(1<<15));
	
	//select sampling time on ch0 pin a0 "SMPR2 register" -> Tconve= cycles / adcclk
	
	ADC1->SMPR2|=7;
	
	//enable adon bit -> wake upp adc 
	
	ADC1->CR2&=~(1<<0);
	
	//cr2 register->set reset calibration bit and wait until hardware return it to 0
	
	ADC1->CR2|=4;
	while(ADC_CR2_RSTCAL & 1);

	
	//cr2 rewgister -> init calibrfation bit and wait until hw reset it
	
	ADC1->CR2|=2;
	while(ADC_CR2_CAL & 1);
	
	while(1){
	
		//point to sqr3 register 1st conversion in  regular sequence register

		ADC1->SQR3 = 0x00000002;
		
		//once again set 1 to adon bit -> fikrst time wake up second time start coversion
		// wate until endf of conversion eoc bit is 0
		// read raw binaey data from adc 1->dr register
		
		//v=(raw*3,3)/4096 voltage
		// t=v*100 temperature
	
	
	}



}