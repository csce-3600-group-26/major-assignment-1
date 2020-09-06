#include <stdio.h>
#include "major1.h"

int main()
{
    printf("%lu %lu %lu %lu\n", clz(1), endian(1), rotate(1, 1), parity(1));
    return 0;
}