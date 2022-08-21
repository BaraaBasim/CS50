#include <cs50.h>
#include <stdio.h>
#include <math.h>
void checksum(long n);
int main(void)
{
    int length = 0;
    long n;
    // int total = 0;
    // int total1 = 0;
    // int total2 = 0;
    n = get_long("Number: ");
    length = (int)log10(n) + 1;
    if (length == 13 || length == 15 || length == 16)
    {
        checksum(n);
    }
     else
    {
        printf("INVALID\n");
    }
}

void checksum(long n)
{
    int total = 0;
    int total1 = 0;
    int total2 = 0;
    int length = (int)log10(n) + 1;
    int c = length - 1; // digit position
    int numberArray[length];

    while (n != 0)
    {
        numberArray[c] = n % 10;
        n /= 10;
        // printf("numberArray[c] : %i \n",numberArray[c]);
        c--;
    }

    for (int i = length - 2; i >= 0; i -= 2)
    {
        int buffer = numberArray[i] * 2;
        if (buffer > 9)
        {
            int n1 = buffer % 10;
            // printf("numberArray[i] = %i \n", numberArray[i]);
            // printf("n1 = %i \n", n1);
            buffer /= 10;
            int n2 = buffer;
            // printf("n2 = %i \n", n2);
            total1 += n1 + n2;
            // printf("total1 = %i \n", total1);
            continue;
        }
        total1 += buffer;
    }
    // printf("total1 : %i \n",total1);

    for (int i = length - 1; i >= 0; i -= 2)
    {
        total2 += numberArray[i];
    }
    // printf("total2 : %i \n", total2);
    total = total1 + total2;
    // printf("total1 + total2 = %i \n", total);
    if (total % 10 == 0)
    {
        if (length == 15)\
        {
            if ((numberArray[0] == 3 && numberArray[1] == 4) || (numberArray[0] == 3 && numberArray[1] == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }


        if ((length == 16 || length == 13) && numberArray[0] == 4)
        {
            printf("VISA\n");
        }



        if (length == 16 && numberArray[0] == 5)
        {
            if (numberArray[1] == 1 || numberArray[1] == 2 || numberArray[1] == 3 || numberArray[1] == 4 || numberArray[1] == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

