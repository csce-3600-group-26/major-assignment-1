#include "major1.h"

unsigned long rotate(unsigned long input, unsigned long bit_positions)
{
    unsigned long bit_mask = (1 << bit_positions) - 1;
    unsigned long masked_input = input & bit_mask;
    masked_input = masked_input << (8 * sizeof(unsigned long) - bit_positions);
    return input >> bit_positions | masked_input;
}