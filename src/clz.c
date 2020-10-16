#include "major1.h"

int clz(unsigned long input)
{
    int sum = 0; // sum for the number of leading zeroes

    for(int i = 31; i >= 0; i--)
    {
            int temp = input >> i; 
            if(temp & 1) //checking if each bit is 1
            {
                    break; //if the bit is 1 leave the loop
            }
            else
            {
                    sum++; // if the leading bit is 0 add 1 to sum
            }
    }

    return sum; //return number of leading zeroes
}