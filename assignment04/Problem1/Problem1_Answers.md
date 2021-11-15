# Problem 1 Answers

## Question 1: What instructions does the compiler produce in assembly for “writing” to the RCC_AHB2ENR bit when using bit-band address?

To write a value of 1 to the RCC_AHB2ENR bit, the compiler generates the following code:
```
MOVS R0, #1
STR  R0, [R4]
```

This code loads register 0 with the value of 1 and then writes it to the memory address contained in the R4 register which corresponds to the bit-band address of the RCC_AHB2ENR bit 0.

## What were the instructions produced when writing to the RCC_AHB2ENR without using bit-banding?

Without using bit-banding, significantly more instructions are required. The generated assembler code must first load a register with the address of RCC_AHB2ENR and then load the memory contents of that address. It then computes the bitwise OR of the value of bit 0 and the value 1. Lastly, it stores the result to the RCC_AHB2ENR address.

```
LDR.N  R0, [PC, #0x3C]
LDR    R1, [R0]
ORRS.W R1, R1, #1
STR    R1, [R0]
```