#include "major1.h"

unsigned long endian(unsigned long input)
{
    //assign number address to pointer
    char *num = (char*)(&input);
    
    //swap byte B0 and B3 
    num[0] = num[0] ^ num[3];
    num[3] = num[0] ^ num[3];
    num[0] = num[0] ^ num[3];

    // Swap byte B1 and B2 
    num[1] = num[1] ^ num[2];
    num[2] = num[1] ^ num[2];
    num[1] = num[1] ^ num[2];

    
    return input;
    
}