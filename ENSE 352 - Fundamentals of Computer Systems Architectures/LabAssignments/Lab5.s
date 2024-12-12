#include "stm32f10x.h"

void setup() {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN; 		//clocks for GPIOA and GPIOB
	
		//PA0 = A0
		//PA1 = A1
		//PA4 = A2
		//PB0 = A3
		//PB8 = D15, inputs will pull up pull down.
		//PB0 = D14
		//PB4 = D5
		//PB6 = D10
	
		// being configured as push pull resistors, remember sinking and sourcing.
    GPIOA->CRL = 0x00030033; //A0-A2
    GPIOB->CRL = 0x04040003; //PB0 as output. PB4, PB6 as inputs will pullup/pull down.
    GPIOB->CRH = 0x00000044; //PB8, PB9 as inputs
}
void delay()
{
    for (int i =0; i<1000; i++)
    { 
        for (int i=0; i<1000; i++)
            {}
    }
}

int main() {
    setup();
	
    GPIOA->CRL &= ~(GPIO_CRL_CNF5_0 | GPIO_CRL_CNF5_1);
    GPIOA->CRL |= (GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1);
    int count = 10;
    while(count > 0)
    {
        GPIOA->BSRR |= GPIO_BSRR_BS5;
        delay();
        GPIOA->BSRR |= GPIO_BSRR_BR5;
        delay();
        count --;
    }
		
    while (1) 
    {
        if (!(GPIOB->IDR & (1 << 4))) { // If PB4 is low 
            GPIOA->ODR |= (1 << 0);     
        } 
        else {
            GPIOA->ODR &= ~(1 << 0);    
        }

        
        if (!(GPIOB->IDR & (1 << 6))) { // If PB6 is low 
            GPIOA->ODR |= (1 << 1);     
        } 
        else {
            GPIOA->ODR &= ~(1 << 1);    
        }

       
        if (!(GPIOB->IDR & (1 << 8))) { // If PB8 is low (button pressed)
            GPIOA->ODR |= (1 << 4);     
        } 
        else {
            GPIOA->ODR &= ~(1 << 4);    
        }

       
        if (!(GPIOB->IDR & (1 << 9))) { // If PB9 is low (button pressed)
            GPIOB->ODR |= (1 << 0);    
        } 
        else {
            GPIOB->ODR &= ~(1 << 0);    
        }
    }
}