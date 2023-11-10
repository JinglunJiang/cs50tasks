#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0;
            int rounded = round(average);
            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtBlue = rounded;
            image[i][j].rgbtGreen = rounded; // Make the three colors to the smae value
        }
    }
    return; //The easiest one
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // It doesn't really matter if the width is even or odd
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp; // Use a temp to swap
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_red = 0;
            int total_green = 0;
            int total_blue = 0;
            int count = 0;
            for (int di = -1; di < 2; di++) // Another layer
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        total_red += image[ni][nj].rgbtRed;
                        total_green += image[ni][nj].rgbtGreen;
                        total_blue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round(total_red / (float)count);
            temp[i][j].rgbtGreen = round(total_green / (float)count);
            temp[i][j].rgbtBlue = round(total_blue / (float)count); // Use the float then round it up
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edged_image[height][width];
    int x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; // The kernels should be defined first, and can be multiplied directly
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gx_red = 0.0;
            float gx_blue = 0.0;
            float gx_green = 0.0;
            float gy_red = 0.0;
            float gy_green = 0.0;
            float gy_blue = 0.0;
            for (int di = -1; di < 2; di++)
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    if (i + di >= 0 && i + di < height && j + dj >= 0 && j + dj < width)
                    {
                        gx_red = gx_red + image[i + di][j + dj].rgbtRed * x[di + 1][dj + 1]; //If it is -1 location should multiply 0th
                        gx_blue = gx_blue + image[i + di][j + dj].rgbtBlue * x[di + 1][dj + 1];
                        gx_green = gx_green + image[i + di][j + dj].rgbtGreen * x[di + 1][dj + 1];
                        gy_red = gy_red + image[i + di][j + dj].rgbtRed * y[di + 1][dj + 1];
                        gy_green = gy_green + image[i + di][j + dj].rgbtGreen * y[di + 1][dj + 1];
                        gy_blue = gy_blue + image[i + di][j + dj].rgbtBlue * y[di + 1][dj + 1];
                    }
                }
            }
            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            if (red > 255)
            {
                red = 255; // Stucked here for three hours, you have to check if it is bigger than 255 in advance
            }
            edged_image[i][j].rgbtRed = red;
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            if (green > 255)
            {
                green = 255;
            }
            edged_image[i][j].rgbtGreen = green;
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));
            if (blue > 255)
            {
                blue = 255;
            }
            edged_image[i][j].rgbtBlue = blue;
        }
    }
    for (int i = 0; i < height; i++) // Move it back to the original image
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = edged_image[i][j];
        }
    }
    return;
}