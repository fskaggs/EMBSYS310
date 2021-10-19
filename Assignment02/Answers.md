Question 1:
- A) The value of Counter in the "Locals" window is: 0x80000006
- B) The value of Counter in the "Registers" window is: 0X80000006
- C) The ASPR flags:
    N = 1
    Z = 0
    C = 0
    V = 0
    Q = 0
    GE = 0

Question 2:
- A) The value of Counter in the "Locals" window is: 0x00000000
- B) The ASPR flags are:
    N = 0
    Z = 1
    C = 1
    V = 0
    Q = 0
    GE = 0

    The Zero and Carry flags are set because the register is a signed int (32-bit value). When we add 1
    to a 0xFFFFFFFF, the result is 0x00000000 with a carry out; causing the Z and C flags to be set.

Question 3:
- A) The value of Counter in the "Locals" window is: 0x80000000
- B) The Negative (N) and Overflow (V) flags are set.  This occurs because the Counter variable is 
   defined as an unsigned integer.  When you add two positive integers (0x7FFFFFFF and 0x01) the high
   bit is set which indicates a negative number, thus the hardware sets the N and V flags to indicate
   a change in sign occured following the add.

Question 4:
- A) The value of Counter in the "Locals" window is: 0x00000000
- B) The Zero and Carry flags are set in the ASPR register.  This is because the operation of adding 1 to 0xFFFFFFFF exceeds the maximum possible value of a 32-bit unsigned integer. As a result, all bits are 
set to zero and the cary flag is set to indicate that we exceeded the maximum value.

Question 5:
- A) The scope of the Counter variable is global.
- B) The Counter variable is no longer visible in the "Locals" window.
- C) The Counter variable can be viewed in the Auto window or in by adding it to the Watch window. The value 
   of the counter can also be viewed in the Memory window by explicitly looking at the memory contents
   of found at address 0x20000000.
- D) The value contained in the Counter variable is stored at address 0x20000000.

Question 6:
- A) The value of Counter is 4 at the end of the program.
- B) Counter is a global variable occupying the first available memory location at 0x20000000. The variable
   p_int is a pointer to the same memory location (0x20000000). The value of the contents of memory pointed
   to by p_int is incremented 3 times. Then the value of the Counter variable is also incremented once. Thus
   the final value of Counter, and the contents of memory at 0x20000000 is 4.

Question 7:
- A) The value of Counter is stored at memory location 0x20000000.
-- B) The Counter value is stored in RAM, static RAM bank 1 (SRAM1) according to the device technical specification.
- C) The final value of Counter is 4.