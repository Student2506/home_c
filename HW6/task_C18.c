#include <stdio.h>

#define LIMIT 100

int is_digit(char c);

int main(int argc, char **argv)
{
    char input[LIMIT];
    fgets(input, LIMIT, stdin);
    int accum = 0;
    for (int i = 0; input[i] != '.'; i++)
    {
        if (is_digit(input[i]) == 1)
            accum++;
    }
    printf("%d", accum);
    return 0;
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}