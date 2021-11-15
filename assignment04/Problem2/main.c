int func1(int a, int b, int c, int d, int e)
{
  int sum = a + b + c + d + e;
  return sum;
}

void func2()
{
  func1(1, 2, 3, 4, 5);
}

int main()
{
  func2();
  return 0;
}
