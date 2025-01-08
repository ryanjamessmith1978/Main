#include "helpers.h"
#include "stdio.h"
#include "stdlib.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    //RGBTRIPLE color_image[height][width]; // = {.rgbtBlue = 1, .rgbtGreen = 0, .rgbtRed = 0};
    //color_image[height][width] = (RGBTRIPLE){.rgbtBlue = 55, .rgbtGreen = 25, .rgbtRed = 66};

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if((image[i][j].rgbtRed == 0) && (image[i][j].rgbtGreen == 0) && (image[i][j].rgbtBlue == 0))
            {
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 25;
                image[i][j].rgbtBlue = 25;
            }
        }
    }
}
