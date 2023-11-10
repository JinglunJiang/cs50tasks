#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool itsjpeg(unsigned char buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2) // Make sure to have only one command line argument
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    else
    {
        FILE *file = fopen(argv[1], "r");
        unsigned char *buffer = malloc(sizeof(char) * 512); // Don't know why it is unsigned but okayy
        int image_count = 0;
        char *filename = malloc(sizeof(char) * 8);
        FILE *img = NULL;
        while (fread(buffer, 1, 512, file) == 512) // The fread function
        {
            if (itsjpeg(buffer))
            {
                if (img != NULL)
                {
                    fclose(img);
                }
                sprintf(filename, "%03i.jpg", image_count);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                image_count++; // Name the file
            }
            else if (img != NULL)
            {
                fwrite(buffer, 512, 1, img);
            }
        }
        if (img != NULL)
        {
            fclose(img);
        }
        fclose(file); // Remember to close the main file
        free(filename); // Remember to free the memory
        free(buffer);
    }
    return 0;
}

bool itsjpeg(unsigned char buffer[]) // Another function that check if it is jpeg
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}