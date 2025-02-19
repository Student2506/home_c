#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum_of_numbers(int x);

int main(int argc, char **argv)
{
    int first;

    scanf("%d", &first);
    if (sum_of_numbers(first) == 10)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}

int sum_of_numbers(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}