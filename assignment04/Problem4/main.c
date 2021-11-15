// To test for endianess, get a pointer to an unsigned integer value
// in memory. Then try to read the address using a single byte sized type.
// If the value at the address 
char * TestEndianess()
{
  unsigned int x = 0x76543210;
  unsigned char* x_ptr = (unsigned char*)&x;
  char * result;
  
  if (*x_ptr == 0x10) 
  {
    result = "Little Endian";
  }
  else
  {
    result = "Big Endian";
  }
  
  return result;
}

int main()
{
  TestEndianess();
  
  return 0;
}
