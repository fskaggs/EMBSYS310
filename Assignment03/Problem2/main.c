#define RCC_BASE   0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define RCC_GPIOA_ENABLE 0x00000001

#define GPIOA_BASE 0x48000000
#define GPIOA_PA5_OUTPUT (0x01 << 11)
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define COUNT_DOWN 100000
#define TOGGLE_BIT(a, b) ((a) ^= (1 << (b)))
#define ODR_LED1 5

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
  RCC_AHB2ENR |= RCC_GPIOA_ENABLE;

  // Configure GPIOA for Output
  GPIOA_MODER &= ~GPIOA_PA5_OUTPUT;
  
  // Toggle the LED1
  while(1)
  {
    TOGGLE_BIT(GPIOA_ODR, ODR_LED1);
    Delay(COUNT_DOWN);
  }

  return 0;
}
