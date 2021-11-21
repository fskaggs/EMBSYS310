void Swap(int **PtrA, int **PtrB)
{
  int *PtrTemp;
  
  PtrTemp = *PtrA;
  *PtrA = *PtrB;
  *PtrB = PtrTemp;
  return;
}

int main()
{
  int A = 10;
  int B = 20;
  int *ptr_A = &A;
  int *ptr_B = &B;
  
  Swap(&ptr_A, &ptr_B);
  
  return 0;
}
