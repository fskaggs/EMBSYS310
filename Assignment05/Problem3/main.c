#include <assert.h>

extern int SwapChar(char * PtrA, char * PtrB);

int main()
{
  char A = 'A';
  char B = 'B';
  char C = 'A';
  
  // Swap the contents of the A and B variables where A <> B
  SwapChar((char*)&A, (char*)&B);
  assert(A == 'B');
  assert(B == 'A');
  
  // Swap the contents of B and C variables there B == C
  SwapChar((char*)&B, (char*)&C);
  assert(B == C);
  
  return 0;
}
