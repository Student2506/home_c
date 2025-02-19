#include <stdio.h>
#include <limits.h>

int summation(int);

int main(int argc, char **argv)
{
    int input;
    scanf("%d", &input);
    printf("%d", summation(input));
    return 0;
}

int summation(int number)
{
    int accum = 0;
    for (int i = 1; i <= number; i++)
    {
        accum += i;
    }
    return accum;
}