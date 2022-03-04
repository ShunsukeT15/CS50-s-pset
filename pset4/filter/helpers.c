#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <stdlib.h>
#include <memory.h>

#include "helpers.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return ;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtRed = sepiaRed;

            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtGreen = sepiaGreen;

            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return ;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE pxa = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] =  pxa;
        }
    }
    return ;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int k, l;
    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(RGBTRIPLE[height][width]));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int flame = 0;


            for (k = i - 1; k <= i + 1; k++)
            {
                for (l = j - 1; l <= j + 1; l++)
                {
                    if ((k >= 0 && k <= height - 1) && (l >= 0 && l <= width - 1))
                    {
                        sumRed += copy[k][l].rgbtRed;
                        sumGreen += copy[k][l].rgbtGreen;
                        sumBlue += copy[k][l].rgbtBlue;
                        flame = flame + 1;
                    }

                }
            }
            image[i][j].rgbtRed = round((float)sumRed / (float)flame);
            image[i][j].rgbtGreen = round((float)sumGreen / (float)flame);
            image[i][j].rgbtBlue = round((float)sumBlue / (float)flame);
        }
    }
    return;
}
