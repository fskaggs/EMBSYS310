#include "stm32l475xx.h"
#include "system_stm32l4xx.h"

#define COUNT_DOWN 100000
#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    GPIOB->ODR ^= GPIO_ODR_OD14;
}

void Delay(int Time)
{
  int count = 0;
  
  while(count < Time)
  {
    count++;
  }
}

int main()
{
  // Enable GPIOA Clocking
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
 
  // Configure GPIOA for Output
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  SysTick_Initialize();
  
  
  // Toggle the LED1
  while(1)
  {
  //  GPIOA->ODR |= GPIO_ODR_OD5;
  //  Delay(COUNT_DOWN);
    
  //  GPIOA->ODR &= ~GPIO_ODR_OD5;
  //  Delay(COUNT_DOWN);
  }
  
  
  return 0;
}


