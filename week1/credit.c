#include <cs50.h>
#include <stdio.h>

bool check(long number, long digit, bool isOdd);
long calculate(long result, bool shouldMultiple);

int main(void)
{
    // Ask user to input credit number.
    long number = get_long("Number: ");

    // Types of digit.
    long digit13 = 1000000000000;
    long digit15 = 100000000000000;
    long digit16 = 1000000000000000;
    bool isOdd;

    // Type of card. Master/Visa(16 digits), Amex(15 digits), Visa(13 digits).
    if (number / digit13 >= 1 && number / digit13 < 10)
    {
        if (number < 4000000000000)
        {
            printf("INVALID\n");
        }
        else
        {
            isOdd = true;
            bool checkResult = check(number, digit13, isOdd);
            if (checkResult == false)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("VISA\n");
            }
        }
    }
    else if (number / digit15 >= 1 && number / digit15 < 10)
    {
        if ((number >= 340000000000000 && number < 350000000000000) || (number >= 370000000000000 && number < 380000000000000))
        {
            isOdd = true;
            bool checkResult = check(number, digit15, isOdd);
            if (checkResult == false)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("AMEX\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (number / digit16 >= 1 && number / digit16 < 10)
    {
        if (number < 4000000000000000 || (number >= 5000000000000000 && number < 5100000000000000) || number >= 5600000000000000)
        {
            printf("INVALID\n");
        }
        else
        {
            isOdd = false;
            bool checkResult = check(number, digit16, isOdd);
            if (checkResult == false)
            {
                printf("INVALID\n");
            }
            else
            {
                if (number >= 5100000000000000)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("VISA\n");
                }
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check(long number, long digit, bool isOdd)
{
    bool shouldMultiple;
    if (isOdd)
    {
        shouldMultiple = false;
    }
    else
    {
        shouldMultiple = true;
    }
    long sum = 0;

    while (number > 10)
    {
        // Get every digit by dividing.
        long result = number / digit;
        // Multiple or add depends on flag.
        sum += calculate(result, shouldMultiple);
        shouldMultiple = !shouldMultiple;

        number -= (result * digit);
        digit /= 10;
    }

    // Last digit
    shouldMultiple = false;
    sum += calculate(number, shouldMultiple);

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long calculate(long result, bool shouldMultiple)
{
    if (shouldMultiple == true)
    {
        if (result < 5)
        {
            return (result * 2);
        }
        else
        {
            return (1 + result * 2 - 10);
        }
    }
    else
    {
        return result;
    }
}
