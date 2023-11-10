#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // To detect every single pixel to see if it is black
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0)
            {
                image[i][j].rgbtBlue = 0xff;
                image[i][j].rgbtRed = 0xef; // The color should be kind of purple
            }
        }
    }
}
