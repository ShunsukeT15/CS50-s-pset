#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j, k;
    do
    {
        n = get_int("Hight: ");

    }
    while (n <= 0 || 8 < n);

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }


}
