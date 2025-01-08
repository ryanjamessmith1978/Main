#include "helpers.h"
#include <stdlib.h>

/*
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
}
RGBTRIPLE;
*/ // RGBTRIPLE (*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
// RGBTRIPLE pixel = image[0][0]

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE *pixel = malloc(sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel2 = image[i][j];

            if(pixel2.rgbtBlue == 0 && pixel2.rgbtGreen == 0 && pixel2.rgbtRed == 0)
            {
                pixel->rgbtBlue = 155;
                pixel->rgbtGreen = 0;
                pixel->rgbtRed = 202;
                image[i][j] = *pixel;
            }
        }
    }
}