#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user to type in the height he/she whats for the pyramid
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8); // The input must between 1 and 8
    // Print the pyramid
    int s = 7; // Define a variable for number of '#'
    int l = 0; // Define a variable for how many times the loop for one row runs
    while (l < h)
    {
        int i = 0; // The number of space before each line
        while (i < (h - l - 1))
        {
            printf(" ");
            i++;
        }
        int j = 0; // The number of '#'
        while (j < (8 - s))
        {
            printf("#");
            j++;
        }
        printf("  "); // The number of spaces is a constant
        int k = 0; // The opposite ones :)
        while (k < (8 - s))
        {
            printf("#");
            k++;
        }
        printf("\n");
        s--;
        l++;
    }
}