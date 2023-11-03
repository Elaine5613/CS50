#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // user input
    int tall;
    do
    {
        tall = get_int("Height: ");
    }
    while (tall < 1 || tall > 8);

    // create blocks
    int length = tall * 2 + 2;
    for (int i = 0; i < tall; i++)
    {
        for (int j = 0; j <= (length / 2) + (i + 1); j++)
        {
            if (j < length / 2 - 1 - (i + 1) || j == length / 2 - 1 || j == length / 2)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
