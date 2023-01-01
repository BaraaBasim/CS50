
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;
    do
    {
        input = get_int("Height: ");
    } while (input <= 0 || input > 8) ;

    for (int i = 1; i <= input; i++)
    {
        for (int j = input - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = i; k < i * 2; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = i; k < i * 2; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
