#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int s; // Define the start size
    do
    {
        s = get_int("Start size: ");
    }
    while (s < 9);

    // TODO: Prompt for end size
    int e; // Define the end size
    do
    {
        e = get_int("End Size: ");
    }
    while (e < s);
    // TODO: Calculate number of years until we reach threshold
    int y = 0; // Define the number of years
    int n = s; // Define a variable to track current number of llamas
    while (n < e)
    {
        n = n + (n / 3) - (n / 4);
        y++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", y);
}
