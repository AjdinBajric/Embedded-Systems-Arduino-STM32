#include "stm32f10x.h"                  // Device header
#include "STM32.h"
#include <iostream>

using namespace std;

void clock_enable(GPIO_TypeDef *PortName, bool EnOrDi){
	
	cout<<&PortName;
	
	if(PortName == GPIOA){
		
		EnOrDi == true? RCC->APB2ENR |= (1<<2):RCC->APB2ENR &= ~(1<<2);

	}
	
	if(PortName == GPIOB){
	
		EnOrDi == true? RCC->APB2ENR |= (1<<3):RCC->APB2ENR &= ~(1<<3);

	}
	
	if(PortName == GPIOC){
	
		EnOrDi == true? RCC->APB2ENR |= (1<<4):RCC->APB2ENR &= ~(1<<4);
		
	}
}
	
void configPinAsOutput(GPIO_TypeDef *PortName, int pinNumber){

	if(pinNumber < 8){
			
			//Mode part
			PortName->CRL |= (1<<pinNumber * 4);
			PortName->CRL |= (1<<((pinNumber * 4) + 1));
			
			// CNF part
			PortName->CRL &= ~((1<<pinNumber * 4) + 2);
			PortName->CRL &= ~(1<<((pinNumber * 4) + 3));
	}
	
	else{	
		
			//Mode part
			PortName->CRH |= (1<<(pinNumber - 8) * 4);
			PortName->CRH |= (1<<(((pinNumber - 8) * 4) + 1));
			
			// CNF part
			PortName->CRH &= ~(1<<(((pinNumber - 8) * 4) + 2));
			PortName->CRH &= ~(1<<(((pinNumber - 8) * 4) + 3));
	}
}


void configPinAsInput(GPIO_TypeDef *PortName, int pinNumber){
	
	if(pinNumber < 8){
		
		//Mode part
		PortName->CRL &= ~(1<<pinNumber * 4);
		PortName->CRL &= ~(1<<((pinNumber * 4) + 1));
	
		//CNF part
		PortName->CRL &= ~(1<<(((pinNumber - 8) * 4) + 2));
		PortName->CRL |=  (1<<(((pinNumber - 8) * 4) + 3));	
	}
	
	else{
		//Mode part
		PortName->CRH &= ~(1<<(pinNumber - 8) * 4);
		PortName->CRH &= ~(1<<(((pinNumber - 8) * 4) + 1));
	
		//CNF part
		PortName->CRH &= ~(1<<(((pinNumber - 8) * 4) + 2));
		PortName->CRH |=  (1<<(((pinNumber - 8) * 4) + 3));
	}
}


void pinMode(GPIO_TypeDef *PortName, int pinNumber, int mode, int speed){

	if(mode == OUTPUT){
		
		configPinAsOutput(PortName, pinNumber);
	
	}
	else{
		
		configPinAsInput(PortName, pinNumber);
		
	}
}

void digitalWrite(GPIO_TypeDef *PortName, int pinNumber, bool value){

	if(PortName == GPIOA){
	
		value == true? GPIOA->ODR |= (1<<pinNumber): GPIOA->ODR &= ~(1<<pinNumber);
		
	}
	
	if(PortName == GPIOB){
	
		value == true? GPIOB->ODR |= (1<<pinNumber): GPIOA->ODR &= ~(1<<pinNumber);
		
	}
	
	if(PortName == GPIOC){
	
		value == true? GPIOC->ODR |= (1<<pinNumber): GPIOA->ODR &= ~(1<<pinNumber);
		
	}
}

bool digitalRead(GPIO_TypeDef *PortName, int pinNumber){

	uint32_t idr_val = PortName->IDR;
	
	if (idr_val & (1 << pinNumber)) {
		return true;
	}
	
	else return false;
}
