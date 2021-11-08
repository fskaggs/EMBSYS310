#define RCC_BASE   0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define RCC_GPIOA_ENABLE 0x00000001

#define GPIOA_BASE 0x48000000
#define GPIOA_PA5_OUTPUT (0x01 << 11)
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define TOGGLE_BIT(a, b) ((a) ^= (1 << (b)))
#define SET_BIT(a, b) ((a) |= (1 << (b)))
#define CLEAR_BIT(a, b) ((a) &= ~(1 << (b)))

#define COUNT_DOWN 300000
#define ODR_LED1 5

#define DIT 1  // Signal for one time unit
#define DAH 3  // Signal for three time units
#define EOS 1  // End of Signal
#define EOL 3  // End of Letter
#define EOW 7  // End of Word

// Lookup table for what signals are required to transmit a letter in Morse code.
// Structure is as follows:
// Byte 0 - Number of signals in array
// Byte 1 - n - Specific signals required for a given letter
char Morse_Code[26][5] = {
  { 2, DIT, DAH },            // A
  { 4, DAH, DIT, DIT, DIT },  // B
  { 4, DAH, DIT, DAH, DIT },  // C
  { 3, DAH, DIT, DIT },       // D
  { 1, DIT },                 // E
  { 4, DIT, DIT, DAH, DIT },  // F
  { 3, DAH, DAH, DIT },       // G
  { 4, DIT, DIT, DIT, DIT },  // H
  { 2, DIT, DIT },            // I
  { 4, DIT, DAH, DAH, DAH },  // J
  { 3, DAH, DIT, DAH },       // K
  { 4, DIT, DAH, DIT, DIT },  // L
  { 2, DAH, DAH },            // M
  { 2, DAH, DIT },            // N
  { 3, DAH, DAH, DAH },       // O
  { 4, DIT, DAH, DAH, DIT },  // P
  { 4, DAH, DAH, DIT, DAH },  // Q
  { 3, DIT, DAH, DIT },       // R
  { 3, DIT, DIT, DIT },       // S
  { 1, DAH },                 // T
  { 3, DIT, DIT, DAH },       // U
  { 4, DIT, DIT, DIT, DAH },  // V
  { 3, DIT, DAH, DAH },       // W
  { 4, DAH, DIT, DIT, DAH },  // X
  { 4, DAH, DIT, DAH, DAH },  // Y
  { 4, DAH, DAH, DIT, DIT },  // Z
 };

// Simple delay function used to control timing for LED to be on or off
void Delay(int Multiplier)
{
  int count = 0;
  int period = COUNT_DOWN * Multiplier;

  while(count < period)
  {
    count++;
  }
}

// Function transmits a single character in Morse code by flashing LED1
void SendLetter(char Letter)
{
  int index;
  char *sequence;
  int  count;
  int symbolDelay;
  
  index = (int)(Letter - 'A');
  sequence = Morse_Code[index];
  count = sequence[0];

  for(index = 1; index <= count; index++)
  {
    // Light LED for time corresponding to a DIT or DAH
    SET_BIT(GPIOA_ODR, ODR_LED1);
    symbolDelay = sequence[index];
    Delay(symbolDelay);
    
    // Turn off LED for break between DITs and DAHs
    CLEAR_BIT(GPIOA_ODR, ODR_LED1);
    Delay(EOS);
  }
}

// Function flashes LED1 to transmit the given word (string) in Morse code
void SendWord(char Word[])
{
  char *letter;

  // Get each character in the word and send it one at a time
  for(letter = Word; *letter != '\0'; letter++)
  {
    SendLetter(*letter);
      
    // Pause before sending next letter
    Delay(EOL);
  }
  Delay(EOW);
}

int main()
{
  // Enable GPIOA Clocking
  RCC_AHB2ENR |= RCC_GPIOA_ENABLE;

  // Configure GPIOA for Output
  GPIOA_MODER &= ~GPIOA_PA5_OUTPUT;
  
  CLEAR_BIT(GPIOA_ODR, ODR_LED1);
  
  // Toggle the LED1
  while(1)
  {
    // Transmit my name in flashing Morse code on LED1
    SendWord("FRED");
  }

  return 0;
}
