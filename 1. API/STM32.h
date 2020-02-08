#include "stm32f10x.h"                  // Device header
#ifndef STM32_h
#define STM32_h

// MODE
#define INPUT 0
#define OUTPUT 1

// SPEED
#define SLOW 2
#define MEDIUM 1
#define FAST 3

// VALUE
#define HIGH 1
#define LOW 0

// A CRL PORT
#define A0 0x00
#define A1 0x01
#define A2 0x02
#define A3 0x03
#define A4 0x04
#define A5 0x05
#define A6 0x06
#define A7 0x07

// A CRH PORT
#define A8 0x08
#define A9 0x09
#define A10 0x0a
#define A11 0x0b
#define A12 0x0c
#define A13 0x0d
#define A14 0x0e
#define A15 0x0f


// B CRL PORT
#define B0 0x00
#define B1 0x01
#define B2 0x02
#define B3 0x03
#define B4 0x04
#define B5 0x05
#define B6 0x06
#define B7 0x07

// B CRH PORT
#define B8 0x08
#define B9 0x09
#define B10 0x0a
#define B11 0x0b
#define B12 0x0c
#define B13 0x0d
#define B14 0x0e
#define B15 0x0f

// C CRH PORT
#define C13 0x0d
#define C14 0x0e
#define C15 0x0f

// function for enable clock on ports
void clock_enable(GPIO_TypeDef *PortName, bool EnOrDi);

// function which defines pin as INPUT/OUTPUT
void pinMode(GPIO_TypeDef *PortName, int pinNumber, int mode, int speed = FAST);
void digitalWrite(GPIO_TypeDef *PortName, int pinNumber, bool value);
bool digitalRead(GPIO_TypeDef *PortName, int pinNumber);

#endif