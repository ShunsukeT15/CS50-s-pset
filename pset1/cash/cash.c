#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int Q, D, N, P, n, m, l;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);

    Q = cents / 25;
    n = cents % 25;

    D = n / 10;
    m = n % 10;

    N = m / 5;
    l = m % 5;

    P = l;

    printf("%i\n", Q + D + N + P);
}