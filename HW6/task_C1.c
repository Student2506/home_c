#include <stdio.h>

int module(int);

int main(int argc, char **argv)
{
    int input;

    scanf("%d", &input);
    printf("%d", module(input));
    return 0;
}

int module(int number)
{
    if (number >= 0) return number;
    return -number;
}
