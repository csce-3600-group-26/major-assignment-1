#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "major1.h"

// Ask the user for an integer. Ask again if the user's input is not an integer or if the integer is not between <min>
// and <max> inclusively. If the integer is valid, return the integer.
//
// <prompt>:  The message that is displayed to the user.
// <min>:     The lowest value that the integer can be equal to.
// <max>:     The highest value that the integer can be equal to.
unsigned long ask_integer(char *prompt, unsigned long min, unsigned long max)
{
    ask_for_integer:
    {
        printf("%s", prompt);
        char input[21] = {0};
        scanf("%20s%*[^\n]", input);
        for (unsigned char i = 0; i < 21; i++)
        {
            if (input[i] == 0)
                break;
            else if (!isdigit(input[i]))
                goto ask_for_integer;
        }
        unsigned long long input_integer = strtoull((const char *) input, NULL, 10);
        if (input_integer >= min && input_integer <= max)
            return (unsigned long) input_integer;
        else
            goto ask_for_integer;
    }
}

int main()
{
    menu:
    {
        // Prompt the user to select an operation to perform.
        printf("Enter the menu option for the operation to perform:\n");
        printf("(1) Count Leading Zeroes\n");
        printf("(2) Endian Swap\n");
        printf("(3) Rotate-right\n");
        printf("(4) Parity\n");
        printf("(5) EXIT\n");
        printf("--> ");
        char menu_option[2] = {0};
        scanf("%1s%*[^\n]", menu_option);
        // Ask the user for an integer.
        unsigned long integer;
        if (menu_option[0] == '1' || menu_option[0] == '2' || menu_option[0] == '3' || menu_option[0] == '4')
            integer = ask_integer("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ", 1, 4294967295);
        // If the user selected the rotate operation, ask the user for the number of bit positions to rotate the
        // integer by.
        unsigned long bit_positions;
        if (menu_option[0] == '3')
            bit_positions = ask_integer("Enter the number of positions to rotate-right the input (between 0 and 31, "
                                        "inclusively): ", 0, 31);
        // Perform the selected operation.
        switch (menu_option[0])
        {
            case '1':
                printf("The number of leading zeroes in %lu is %d\n", integer, clz(integer));
                break;
            case '2':
                printf("Endian swap of %lu gives %lu\n", integer, endian(integer));
                break;
            case '3':
                printf("%lu rotated by %lu position gives: %lu\n", integer, bit_positions,
                       rotate(integer, bit_positions));
                break;
            case '4':
                printf("Parity of %lu is %lu\n", integer, parity(integer));
                break;
            case '5':
                printf("Program terminating. Goodbye...\n");
                return 0;
            default:
                printf("Error: Invalid option. Please try again.\n");
                break;
        }
        goto menu;
    }
}