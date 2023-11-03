#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // let user to decide just how tall the pyramid should be
    int tall;
    do
    {
        tall = get_int("Height: ");
    }
    while (tall < 1 || tall > 8);

    // create a right-aligned pyramid of blocks
    int index = 1;
    for (int i = 0; i < tall; i++)
    {
        for (int j = 0; j < tall; j++)
        {
            if (j < tall - index)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
        index++;
    }
}
