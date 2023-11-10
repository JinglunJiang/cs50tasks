#include <stdio.h>
#include <cs50.h> // used to use the function 'get_string'

int main(void)
{
    string name; // Define a string variable to store the name
    name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}