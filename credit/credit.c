#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool card_validity(long n); // Make c identify my next function
int main(void)
{
    long n; // Define a long to put user's input
    n = get_long("Number: "); // Store the user's input into n
    char str[20]; // Define a string that store the long converted to string
    snprintf(str, 20, "%ld", n); // Convert the long to string
    int num = strlen(str); // Get the number of digits from string
    if (num == 15) // Seperate AMEX by the number of digits
    {
        int first_two_digits = n / 10000000000000;
        if (first_two_digits == 34 || first_two_digits == 37) // Check if the first 2 digits are valid
        {
            if (card_validity(n))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (num == 13) // Identify VISA
    {
        int first_digit = n / 1000000000000;
        if (first_digit == 4)
        {
            if (card_validity(n))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (num == 16) // Both Visa and Mastercard can have 16 digits
    {
        int first_digit = n / 1000000000000000;
        int first_two_digits = n / 100000000000000;
        if (first_digit == 4)
        {
            if (card_validity(n))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if
        (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55)
        {
            if (card_validity(n))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool card_validity(long n) // Seperated function to check according to Luhn's Algorithm
{
    int sum = 0; // Will be aggregated during the loop
    bool is_second = false; // Check if its the odd position or even position
    int digit;
    while (n > 0)
    {
        digit = n % 10;
        if (is_second)
        {
            digit = digit * 2; // For even places of the long
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10); // Add both digits together
            }
        }
        sum = sum + digit;
        is_second = !is_second; // Check if its odd
        n = n / 10; // Move one digit forward
    }
    return (sum % 10 == 0); // Return true or false
}