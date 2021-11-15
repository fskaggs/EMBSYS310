#include "Stack.h"
// Implementation of a stack data structure designed to hold integer values


int stack[STACK_SIZE];
int stack_idx = 0;

void InitializeStack()
{
    stack_idx = 0;
    return;
}

int Push(int value)
{
  if (StackIsFull() == STACK_FULL)
  {
    return STACK_ERROR;
  }
  else
  {
    stack[stack_idx] = value;
    stack_idx++;
  }
  
  return STACK_SUCCESS;
}

int Pop()
{
  if (StackIsEmpty() == STACK_NOTEMPTY)
  {
    stack_idx--;
    return stack[stack_idx];
  }
  return STACK_ERROR;
}

int StackIsEmpty()
{
    if (stack_idx == 0)
    {
      return STACK_EMPTY;
    }
    else
    {
      return STACK_NOTEMPTY;
    }
}

int StackIsFull()
{
  if (stack_idx == STACK_SIZE)
  {
    return STACK_FULL;
  }
  else
  {
    return STACK_NOTFULL;
  }
}