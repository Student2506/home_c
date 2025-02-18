#include <stdio.h>

int to_digit(char c);

int main(int argc, char **argv)
{
    char input[40];
    fgets(input, 40, stdin);
    int accum = 0;
    for (int i = 0; input[i] != '.'; i++)
    {
        if(to_digit(input[i]) != -1) accum += to_digit(input[i]);
    }
    printf("%d", accum);
    return 0;
}

int to_digit(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    else return -1;
}