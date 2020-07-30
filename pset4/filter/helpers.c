#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average;
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.000000);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            int sepiaRed = round((blue * 0.189) + (red * 0.393) + (green * 0.769));
            int sepiaBlue = round((blue * 0.131) + (red * 0.272) + (green * 0.534));
            int sepiaGreen = round((blue * 0.168) + (red * 0.349) + (green * 0.686));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
    return;
}

void swap(BYTE *a, BYTE *b)
{
    BYTE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            swap (&image[i][j].rgbtBlue, &image[i][width - 1 - j].rgbtBlue);
            swap (&image[i][j].rgbtRed, &image[i][width - 1 - j]. rgbtRed);
            swap (&image[i][j].rgbtGreen, &image[i][width - 1 - j].rgbtGreen);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // a temporary variable to copy the image to
    RGBTRIPLE temp[height][width];

    // to go over all the rows in the image
    for (int i = 0; i < height; i++)
    {
        // to go over all the coloumns in the image
        for (int j = 0; j < width; j++)
        {
            float Bsum = 0.0;
            float Rsum = 0.0;
            float Gsum = 0.0;
            int counter = 0;

            if (i != (height - 1) || j != (width - 1))
            {
                //loop over the rows for certain pixel
                for (int a = -1; a < 2; a++)
                {
                    //if height = 0, no row to the left
                    if (i == 0)
                    {
                        a = 0;
                    }

                    //loop pver the coloumns for a certain pixel
                    for (int b = -1; b < 2; b++)
                    {
                        //if width = 0, no coloumn to the left
                        if (j == 0)
                        {
                            b = 0;
                        }

                        //to find the sums of the rgb values for surrounding pixels
                        Bsum += image[i + a][j + b].rgbtBlue;
                        Rsum += image[i + a][j + b].rgbtRed;
                        Gsum += image[i + a][j + b].rgbtGreen;
                        //to find the number to divide by for the average
                        counter++;
                    }
                }

                //to find the averages
                temp[i][j].rgbtBlue = round(Bsum / counter);
                temp[i][j].rgbtRed = round(Rsum / counter);
                temp[i][j].rgbtGreen = round(Gsum / counter);
            }

            else //if width = max, b cannot equal 1. if height = max, a cannot equal 1
            {
                //loop over the rows for certain pixel
                for (int a = -1; a < 1; a++)
                {
                    //if height = 0, no row to the left
                    if (i == 0)
                    {
                        a = 0;
                    }

                    //loop pver the coloumns for a certain pixel
                    for (int b = -1; b < 1; b++)
                    {
                        //if width = 0, no coloumn to the left
                        if (j == 0)
                        {
                            b = 0;
                        }

                        //to find the sums of the rgb values for surrounding pixels
                        Bsum += image[i + a][j + b].rgbtBlue;
                        Rsum += image[i + a][j + b].rgbtRed;
                        Gsum += image[i + a][j + b].rgbtGreen;
                        //to find the number to divide by for the average
                        counter++;
                    }
                }

                //to find the averages
                temp[i][j].rgbtBlue = round(Bsum / counter);
                temp[i][j].rgbtRed = round(Rsum / counter);
                temp[i][j].rgbtGreen = round(Gsum / counter);
            }
        }
    }

    //to copy the temp values to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}
