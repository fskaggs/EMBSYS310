#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE  20
#define STACK_EMPTY 1
#define STACK_NOTEMPTY 0
#define STACK_FULL  1
#define STACK_NOTFULL 0
#define STACK_ERROR -1
#define STACK_SUCCESS 1

void InitializeStack();
int Push(int value);
int Pop();
int StackIsEmpty();
int StackIsFull();

#endif

