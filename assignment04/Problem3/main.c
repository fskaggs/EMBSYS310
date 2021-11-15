#include <assert.h>
#include "Stack.h"

// Test 1 - Stack Initialization
void Test1()
{
  InitializeStack();
  assert(STACK_EMPTY == StackIsEmpty());
  assert(STACK_NOTFULL == StackIsFull());
  return;
}

// Test 2 - Push and Pop Stack Values
void Test2()
{
  int result1, result2, result3, result4, result5, result6;
  
  InitializeStack();
  
  result1 = Push(10);
  result2 = Push(20);
  result3 = Push(30);
  result4 = Pop();
  result5 = Pop();
  result6 = Pop();
  
  assert(STACK_SUCCESS == result1);
  assert(STACK_SUCCESS == result2);
  assert(STACK_SUCCESS == result3);
  assert(30 == result4);
  assert(20 == result5);
  assert(10 == result6);
  return;
}

// Test 3 - Pop from an empty stack
void Test3()
{
  int result1, result2;
  
  InitializeStack();
  
  result1 = StackIsEmpty();
  result2 = Pop();
  
  // Pop with an empty stack should return a stack error. The StackIsEmpty function should return a stack is empty result.
  assert(STACK_EMPTY == result1);
  assert(STACK_ERROR == result2);
}

// Test 4 - Push to a full stack and also check result of StackIsFull results when the stack is empty or full
void Test4()
{
  int result1, result2, result3; 
  
  InitializeStack();
  
  result1 = StackIsFull();
  
  // Fill up the stack
  for(int i = 0; i < STACK_SIZE; i++)
  {
    Push(i);
  }
  
  result2 = StackIsFull();
  
  result3 = Push(100);
  
  assert(STACK_NOTFULL == result1);
  assert(STACK_FULL == result2);
  assert(STACK_ERROR == result3);
}

int main()
{ 
  Test1();
  Test2();
  Test3();
  Test4();
  return 0;
}

