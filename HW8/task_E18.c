#include <stdio.h>

int primes(int, int);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    for (int i = 2; i <= 9; i++)
    {
        printf("%d %d\n", i, primes(first, i));
    }
    return 0;
}

int primes(int number, int divider)
{
    int accum = 0;
    for (int i = 2; i <= number; i++)
    {
        if (i % divider == 0)
        {
            accum++;
        }
    }
    return accum;
}
