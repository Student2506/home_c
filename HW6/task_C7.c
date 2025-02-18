#include <stdio.h>

void converter(int, int);

int main(int argc, char **argv)
{
    int input, system;
    scanf("%d%d", &input, &system);
    converter(input, system);
    return 0;
}

void converter(int number, int system)
{
    if (number < system)
    {
        printf("%d", number);
        return;
    }
    converter(number / system, system);
    printf("%d", number % system);
}
