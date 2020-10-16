#include "major1.h"

int clz(unsigned long input)
{
    int sum = 0;

    for(int i =31; i >= 0; i--)
    {
            int temp = input >> i;
            if(temp & 1)
            {
                    break;
            }
            else
            {
                    sum++;
            }
    }

    return sum;
}