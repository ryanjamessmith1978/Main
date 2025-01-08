#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int returnAsciiNum(char n);
void convertToBinary(string message);
void populateBinaryArray(int dec);
void print_bulb(int bit);

// Globals for setting up the binary number array
const int BITS_IN_BYTE = 8;
int binArray[BITS_IN_BYTE] = {0};

int main(void)
{
    // Take in the message
    string text = get_string("Message: ");
    convertToBinary(text);
}

// Graphics pre-made
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

// Covert char to int using Ascii table
int returnAsciiNum(char n)
{
    return (int)n;
}

// Convert dec to binary
void convertToBinary(string message)
{
    int dec = 0;

    for(int i = 0; i < strlen(message); i++)
    {
        dec = returnAsciiNum(message[i]);
        populateBinaryArray(dec);
    }
}
// Convert dec to binary and populate array
// Show conversion visually
void populateBinaryArray(int dec)
{
    int decimal = dec;
    int binary = 0;

    for(int i = 7; i >= 0; i--)
    {
        binary = decimal % 2;
        binArray[i] = binary;
        decimal = decimal / 2;
    }

    for(int i = 0; i < 8; i++)
    {
        print_bulb(binArray[i]);
    }
    printf("\n");
}