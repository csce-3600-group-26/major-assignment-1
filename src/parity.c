#include "major1.h"

unsigned long parity(unsigned long input)
{
    int i, count = 0;
    for (i = 0; i < 32; i++)
    {
	    count += input%2;
	    input /= 2;
    }
	 return count%2;
}
