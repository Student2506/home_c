#include <stdio.h>

#define LIMIT 1000

int is_digit(char c);

int main(int argc, char **argv)
{
    char input[LIMIT];
    fgets(input, LIMIT, stdin);
    int accum = 0;
    int ch = input[0];
    for (int i = 1; input[i] != '.'; i++)
    {
        if (ch == input[i])
        {
            accum++;
        }
        else
        {
            printf("%c%d", ch, accum + 1);
            accum = 0;
            ch = input[i];
        }
    }
    printf("%c%d", ch, accum + 1);
    return 0;
}
