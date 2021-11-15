#define RCC_BASE   0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define RCC_GPIOA_ENABLE 0x00000001
#define GPIOA_BASE 0x48000000
#define GPIOA_PA5_OUTPUT (0x01 << 11)
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ODR_ENABLE (0x01 << 5)
#define COUNT_DOWN 100000
#define BITBAND_PBASE 0x42000000
#define AHB2ENR_OFFSET 0x2104C
#define GPIOA_ENABLE_BIT 0x00
#define BITBAND_ADDR(BASE, OFFSET, BITNUM) ((unsigned int*)((BASE) + (OFFSET*32)+(BITNUM*4)))

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
  //RCC_AHB2ENR |= RCC_GPIOA_ENABLE;

  // Enable GPIOA Clocking using BIT Banding
  unsigned int* ClkEnable_BitAddr = BITBAND_ADDR(BITBAND_PBASE, AHB2ENR_OFFSET, GPIOA_ENABLE_BIT);
  *ClkEnable_BitAddr = 0x01;
  
  // Configure GPIOA for Output
  GPIOA_MODER &= ~GPIOA_PA5_OUTPUT;
  
  // Toggle the LED1
  while(1)
  {
    GPIOA_ODR |= ODR_ENABLE;
    Delay(COUNT_DOWN);
    GPIOA_ODR &= ~ODR_ENABLE;
    Delay(COUNT_DOWN);
  }

  return 0;
}
