#include "main.h"

void Delay(uint32_t time);

int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; /* Clock GPIOA */

	GPIOA->MODER |= GPIO_MODER_MODER4_0; /* 01: General purpose output mode */
	GPIOA->MODER &= ~GPIO_MODER_MODER4_1;

	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_4; /* 0: Output push-pull */

	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4_0; /* 01: Medium speed */
	GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR4_1;

	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR4_0; /* 00: No pull-up, pull-down */
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR4_1;

    while(1){

    	/* LED on */
    	GPIOA->BSRR |= GPIO_BSRR_BR_4;
    	Delay(100000);

    	/* LED off */
		GPIOA->BSRR |= GPIO_BSRR_BS_4;
		Delay(100000);

    }
}

void Delay(uint32_t time){

	while(time > 0){
		time--;
	}
}
