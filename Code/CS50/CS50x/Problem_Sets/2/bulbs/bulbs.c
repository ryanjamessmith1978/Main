// Take a message and convert it to a set of bulbs
// Turning the text into decimal numbers.
// Turning decimal numbers into binary numbers,

// My problems with this was converting dec to binary
// Specifically visualizing a nested for loop and function calls within function calls.
// I got hung up on the return value of the decToBinary array.  Changed the prototype 3 or 4 times.  Tried returning a char array
// To get solved I got messy and solved everything in main - I was trying to tie everything together without taking it step by step.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

int charToDecimal(char text);
int decToBinary(int dec, int index);

void print_bulb(int bit);

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int dec = 0;

    int remainder = 0;

    for(int i = 0; i < length; i++)
    {
        dec = charToDecimal(text[i]);

        // This part fucked me up.  I keep forcing the idea that the constant needed to be used in an array somehow.
        for(int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            dec = decToBinary(dec, j);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

int charToDecimal(char text)
{
    return (int)text;
}

// Check for largest bit per decimal %64 > 0 = 1, decimal %32 > 0 = 1.  Add one's to array then flip them.
int decToBinary(int dec, int index)
{
    int binaryIndex = pow(2, index); // this was a stroke of genius to reduce the overall size of the code allowing for easy looping.

    if(dec / binaryIndex > 0) // I used the modulus operator as part of this check originally, which was wrong.  Just because you have a remainder
                                // Just because you have a remainder, doesn't mean it's greater than the current binaryIndex value.

    {
        dec = dec % binaryIndex;
        print_bulb(1);
    }
    else
    {
        print_bulb(0);
    }

    return dec;
}