#include "helpers.h"
#include "math.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct
{
    int pixelBlue;
    int pixelGreen;
    int pixelRed;
} Pixel;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double total = 0.0;
    double average = 0.0;
    int roundedAverage = 0;

    double blue = 0.0;
    double green = 0.0;
    double red = 0.0;

    for (int h = 0; h <= height - 1; h++)
    {
        for (int w = 0; w <= width - 1; w++)
        {
            // take the average of the pixels - round and divide by 3.0
            blue = (double)image[h][w].rgbtBlue;
            green = (double)image[h][w].rgbtGreen;
            red = (double)image[h][w].rgbtRed;

            total = (double)blue + (double)green + (double)red;
            average = total / 3.0;
            roundedAverage = round(average);

            // set the average to all 3 colors
            image[h][w].rgbtBlue = roundedAverage;
            image[h][w].rgbtGreen = roundedAverage;
            image[h][w].rgbtRed = roundedAverage;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    double sepiaRed = 0.0;
    double sepiaBlue = 0.0;
    double sepiaGreen = 0.0;

    double blue = 0.0;
    double green = 0.0;
    double red = 0.0;

    for (int h = 0; h <= height - 1; h++)
    {
        for (int w = 0; w <= width - 1; w++)
        {
            // store original image pixel values
            blue = (double)image[h][w].rgbtBlue;
            green = (double)image[h][w].rgbtGreen;
            red = (double)image[h][w].rgbtRed;

            // convert the original values to sepia colors based on provided formula.
            sepiaRed = (double)((double)(0.393 * red) + (double)(0.769 * green) + (double)(0.189 * blue));
            sepiaGreen = (double)((double)(0.349 * red) + (double)(0.686 * green) + (double)(0.168 * blue));
            sepiaBlue = (double)((double)(.272 * red) + (double)(0.534 * green) + (double)(0.131 * blue));

            // Verify range falls in inclusive range
            if (sepiaBlue > 255.0)
            {
                sepiaBlue = 255.0;
            }

            if (sepiaBlue < 0.0)
            {
                sepiaBlue = 0.0;
            }

            if (sepiaGreen > 255.0)
            {
                sepiaGreen = 255.0;
            }

            if (sepiaGreen < 0.0)
            {
                sepiaGreen = 0.0;
            }

            if (sepiaRed > 255.0)
            {
                sepiaRed = 255.0;
            }

            if (sepiaRed < 0.0)
            {
                sepiaRed = 0.0;
            }

            // set the average to all 3 colors
            image[h][w].rgbtBlue = round(sepiaBlue);
            image[h][w].rgbtGreen = round(sepiaGreen);
            image[h][w].rgbtRed = round(sepiaRed);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    Pixel myPix[height][width];
    double tempRed = 0.0;
    double tempGreen = 0.0;
    double tempBlue = 0.0;

    // Create a temporary 2d array for storing the column values in reverse
    for (int h = 0; h <= height - 1; h++)
    {
        for (int w = 0; w <= width - 1; w++)
        {
            tempRed = (double)(image[h][(width-1) - w].rgbtRed);
            tempGreen = (double)(image[h][(width-1) - w].rgbtGreen);
            tempBlue = (double)(image[h][(width-1) - w].rgbtBlue);

            myPix[h][w].pixelRed = round(tempRed);
            myPix[h][w].pixelGreen = round(tempGreen);
            myPix[h][w].pixelBlue = round(tempBlue);
        }
    }

    // Redraw picture in reverse based on 2d array created in reverse order.
    for (int h = 0; h <= height - 1; h++)
    {
        for (int w = 0; w <= width - 1; w++)
        {
            image[h][w].rgbtBlue = myPix[h][w].pixelBlue;
            image[h][w].rgbtGreen = myPix[h][w].pixelGreen;
            image[h][w].rgbtRed = myPix[h][w].pixelRed;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    Pixel myPix[height][width];
    double blurElements = 0.0;
    double blurRed = 0.0;
    double blurGreen = 0.0;
    double blurBlue = 0.0;

    //  Nested outer for loop to track current pixel about to change
    for (int h = 0; h <= height - 1; h++)
    {
        for (int w = 0; w <= width - 1; w++)
        {
            blurRed = 0.0;
            blurGreen = 0.0;
            blurBlue = 0.0;
            blurElements = 0.0;

            // Nested inner for loop to track the surrounding pixels 1 row or 1 column over.
            for (int i = 0; i <= height - 1; i++)
            {
                if (abs(h - i) <= 1)
                {
                    for (int j = 0; j <= width - 1; j++)
                    {
                        // Is this particular pixel within 1 of currentBlur'd pixel
                        if (abs(w - j) <= 1)
                        {
                            blurElements = blurElements + 1.0;
                            blurRed = (double)((double)blurRed + (double)image[i][j].rgbtRed);
                            blurGreen = (double)((double)blurGreen + (double)image[i][j].rgbtGreen);
                            blurBlue = (double)((double)blurBlue + (double)image[i][j].rgbtBlue);
                        }
                    }
                }
            }

            // After totaling all surrounding valid nodes values, average them
            // then add to a seprate struct array per where the original pixel from outer loop resides
            myPix[h][w].pixelRed = round((double)(blurRed / blurElements));
            myPix[h][w].pixelGreen = round((double)(blurGreen / blurElements));
            myPix[h][w].pixelBlue = round((double)(blurBlue / blurElements));
        }
    }

    // After populating 2 dimensional grid array containing a struct of color values
    // Redraw that newly created array onto the image.
    for (int h = 0; h <= height - 1; h++)
    {
        for (int w = 0; w <= width - 1; w++)
        {
            image[h][w].rgbtBlue = myPix[h][w].pixelBlue;
            image[h][w].rgbtGreen = myPix[h][w].pixelGreen;
            image[h][w].rgbtRed = myPix[h][w].pixelRed;
        }
    }

    return;
}