#include <stdio.h>
#include <math.h>

unsigned long long int progression(int);

int main(int argc, char **argv)
{
    int input;
    scanf("%d", &input);
    printf("%llu", progression(input - 1));
    return 0;
}

unsigned long long int progression(int number)
{
    long long int accum = 1;
    for (int i = 0; i < number; i++)
    {
        accum *= 2;
    }
    return accum;
}
