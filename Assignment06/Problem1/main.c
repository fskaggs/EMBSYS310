#include <stm32l475xx.h>
#include <system_stm32l4xx.h>

#define COUNT_DOWN 100000

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
  
  // Toggle the LED1
  while(1)
  {
    GPIOA->ODR |= GPIO_ODR_OD5;
    Delay(COUNT_DOWN);
    
    GPIOA->ODR &= ~GPIO_ODR_OD5;
    Delay(COUNT_DOWN);
  }
  return 0;
}
