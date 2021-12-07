Generate the map file for your program and provide details on:
a. How much total ROM your program is occupying?

According to the MAP file this is the readonly memory usage:
    180 bytes of readonly  code memory
     64 bytes of readonly  data memory

Which indicates 244 bytes of ROM

b. How much total RAM your program is using?

    8192 bytes of readwrite data memory

c. What part of your program is using the most ROM?

    The main.o code takes up 98 bytes of ROM which is the largest component of the fully linked project.

d. What part of your program is using the most RAM?

    My program only uses RAM for the stack which is 0x2000 (8192) bytes allocated by the linker.