#include <stdio.h>

void converter(char*);

int main(int argc, char **argv)
{
    char input[40];
    fgets(input, 40, stdin);
    converter(input);
    return 0;
}

void converter(char *input)
{
    for (int i = 0; input[i] != '.'; i++)
    {
        if (input[i] >= 97 && input[i] <= 122)
        {
            printf("%c", input[i] - 32);
        }
        else
        {
            printf("%c", input[i]);
        }
    }
}
