#include <stdio.h>

int factorial(int);

int main(int argc, char **argv)
{
    int input;
    scanf("%d", &input);
    printf("%d", factorial(input));
    return 0;
}

int factorial(int input)
{
    int accum = 1;
    for (int i = 1; i <= input; i++)
    {
        accum *= i;
    }
    return accum;
}
