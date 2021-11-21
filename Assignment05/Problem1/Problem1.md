# Create a function in “C” that allows swapping of two pointers. 

## a. Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function? 

Prior to calling the Swap_Pointer function, the "main" function places the data values and the addresses
of the data values onto the stack.  

## b. What are the values in R0 & R1 when swap_pointer() is called? 

R0 contains 0x200003EC, which is the address of the pointer to the int variable A on the stack.
R1 contains 0x200003E8, which is the address of the pointer to the int variable B on the stack.

![Stack and Register Content Before Swap](https://github.com/fskaggs/EMBSYS310/blob/main/Assignment05/Problem1/CallSetup.png)

c. Share a screen shot of the local variables inside of “main” after the function 
swap_pointer() returns showing the values of the pointers and what they are pointing to. 

![Swap Completed](https://github.com/fskaggs/EMBSYS310/blob/main/Assignment05/Problem1/SwapCompleted.PNG)