# Problem 2 Answers

## 1. How does the calling function “func2” pass the values to the called function “func1”?

  The first 4 parameters are stored in registers R0 - R3.  The fifth parameter is stored on the stack, prior to calling "func1".

## 2. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?

Prior to calling "func1", the compiler generates code to store the contens of R7 and LR on the stack.

## 3. What extra code did the compiler generate inside the called function “func1” with the list of multiple arguments?

First, "func1" preserves the contents of registers it needs to use for variables on the stack.  It then loads the parameter that was stored on the stack into another register.  At this point all parameters have been stored into a register and can be used by the function.

## 4. Any other observations?

Prior to function calls, the compiler generated assembly stores registers R7 and LR. This is odd because in the generated code, R7 is not apparently being used.