#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for x
    long x = get_long("x: ");  // 9 Quintillion

    // prompt user for y
    long y = get_long("y: ");

    printf("Adding x and y equals: %li\n", x + y);

    float z = x / y; // Truncation

    printf("Dividing 2 longs, x / y that make a decimal point value: %f\n", z);

    z = (float) x / (float) y;
    printf("Casting x and y to float then dividing: %f\n", z);

    printf("%.20f\n", z); // floating point imprecision

}