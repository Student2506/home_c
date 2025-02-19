#include <stdio.h>

int recurs_power(int n, int p);

int main(int argc, char **argv)
{
    int number = 0ll;
    int power = 0ll;
    scanf("%d%d", &number, &power);
    printf("%d", recurs_power(number, power));
    return 0;
}

int recurs_power(int n, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    n *= recurs_power(n, p - 1);
    return n;
}