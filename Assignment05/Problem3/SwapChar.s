/*******************************************************************************
File name       : SwapChar.s
Description     : Assembly language function for square
*******************************************************************************/   
 
    PUBLIC SwapChar     // Exports symbols to other modules
                        // Making SwapChar available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.

// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : SwapChar
Description     : Swaps the contents of two char type variables.
C Prototype     : int SwapChar(val1, val2)
                : Where val1 and val2 are char pointers to the values to swap.
Parameters      : R0: integer val1
                  R1: integer val2
Return value    : R0
*******************************************************************************/  
 
SwapChar
    LDRB R2, [R0]   // Copy the byte at location in R0
    LDRB R3, [R1]   // Copy the byte at location in R1
    STRB R2, [R1]   // Store the value from Val1 at address in R1
    STRB R3, [R0]   // Store the value from Val2 at address in R0
    EORS.W R0, R2, R3 // Set R0 = 0 if value in Val1 == value in Val2; also set APSR
    BEQ Ret         // If Val1 == Val2 return from function
    MOV R0, #1      // else return 1 in R0
Ret:    BX LR       // return 

    END
