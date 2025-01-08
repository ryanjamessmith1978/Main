#include "helpers.h"
#include <math.h>

// ./filter -g INFILE.bmp OUTFILE.bmp
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // RGBTRIPLE pixel = image[0][0];
    int average = 0;

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            average = (pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3;
            pixel.rgbtRed = average;
            pixel.rgbtGreen = average;
            pixel.rgbtBlue = average;

            image[i][j] = pixel;
        }
    }

    // grab the pixel's rgb information for each byte(B, R, G)
    // average those values
    // change the image[i][j] value by creating a new pixel with the average values and passing it in there

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // RGBTRIPLE pixel = image[0][0];
    double originalRed = 0.0;
    double originalGreen = 0.0;
    double originalBlue = 0.0;
    int newRed = 0;
    int newGreen = 0;
    int newBlue = 0;

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            originalRed = (double)pixel.rgbtRed;
            originalGreen = (double)pixel.rgbtGreen;
            originalBlue = (double)pixel.rgbtBlue;

            newRed = round((double)(0.393 * originalRed) + (double)(0.769 * originalGreen) + (double)(0.189 * originalBlue));
            newGreen = round((double)(0.349 * originalRed) +  (double)(0.686 * originalGreen) + (double)(0.168 * originalBlue));
            newBlue = round((double)(0.272 * originalRed) + (double)(0.534 * originalGreen) + (double)(0.131 * originalBlue));

            if(newRed < 0)
            newRed = 0;
            if(newRed > 255)
            newRed = 255;

            if(newGreen < 0)
            newGreen = 0;
            if(newGreen > 255)
            newGreen = 255;

            if(newBlue < 0)
            newBlue = 0;
            if(newBlue > 255)
            newBlue = 255;

            pixel.rgbtRed = newRed;
            pixel.rgbtGreen = newGreen;
            pixel.rgbtBlue = newBlue;

            image[i][j] = pixel;
        }
    }
}

// Reflect image horizontally
// left side of the image should end up on the right
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // RGBTRIPLE pixel = image[0][0];
    // count array backwards - populating new array - setting image of array
    RGBTRIPLE pixelArr[height][width];
    RGBTRIPLE pixel1;
    int iIndex = 0;
    int jIndex = 0;

    for(int i = 0; i < height; i++)
    {
        jIndex = 0;

        for (int j = width - 1; j >= 0; j--)
        {
            pixel1 = image[i][j];
            pixelArr[iIndex][jIndex] = pixel1;
            jIndex++;
        }
        iIndex++;
    }

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel2 = pixelArr[i][j];

            image[i][j] = pixel2;
        }
    }
}

// Blur image
// find all pixels one row or column over, put it into an array
// take all the RGB values of each element and computer the average for all elements in array for each RGB value
// assign average to original pixel.

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // fill array with pixels that are one row or column over from current pixel.
    RGBTRIPLE blurArr[9];
    int numElements = 0;
    int blurRed = 0;
    int blurGreen = 0;
    int blurBlue = 0;
    int blurRedAverage = 0;
    int blurGreenAverage = 0;
    int blurBlueAverage = 0;

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            numElements = 0;
            blurArr[numElements] = image[i][j];
            numElements++;

            if (j + 1 < width) // && image[i][j+1] != NULL)
            {
                blurArr[numElements] = image[i][j+1];
                numElements++;
            }

            if (i + 1 < height)
            {
                blurArr[numElements] = image[i+1][j];
                numElements++;
            }

            if (j + 1 < width && i + 1 < height)
            {
                blurArr[numElements] = image[i+1][j+1];
                numElements++;
            }

            if (j - 1 >= 0) // && image[i][j+1] != NULL)
            {
                blurArr[numElements] = image[i][j-1];
                numElements++;
            }

            if (i - 1 >= 0)
            {
                blurArr[numElements] = image[i-1][j];
                numElements++;
            }

            if (j - 1 >= 0 && i - 1 >= 0)
            {
                blurArr[numElements] = image[i-1][j-1];
                numElements++;
            }
            if (j - 1 >= 0 && i + 1 < height)
            {
                blurArr[numElements] = image[i+1][j-1];
                numElements++;
            }
            if (j + 1 < width && i - 1 >= 0)
            {
                blurArr[numElements] = image[i-1][j+1];
                numElements++;
            }

            blurRed = 0;
            blurGreen = 0;
            blurBlue = 0;

            for(int k = 0; k < numElements; k++)
            {
                blurRed = blurArr[k].rgbtRed + blurRed;
                blurGreen = blurArr[k].rgbtGreen + blurGreen;
                blurBlue = blurArr[k].rgbtBlue + blurBlue;
            }

            blurRedAverage = round(blurRed / (double)numElements);
            blurGreenAverage = round(blurGreen / (double)numElements);
            blurBlueAverage = round(blurBlue / (double)numElements);

            if(blurRedAverage > 255)
            blurRedAverage = 255;
            if(blurRedAverage < 0)
            blurRedAverage = 0;

            if(blurGreenAverage > 255)
            blurGreenAverage = 255;
            if(blurGreenAverage < 0)
            blurGreenAverage = 0;

            if(blurBlueAverage > 255)
            blurBlueAverage = 255;
            if(blurBlueAverage < 0)
            blurBlueAverage = 0;

            RGBTRIPLE pixel;
            pixel.rgbtRed = blurRedAverage;
            pixel.rgbtGreen = blurGreenAverage;
            pixel.rgbtBlue = blurBlueAverage;

            image[i][j] = pixel;
        }
    }
}
