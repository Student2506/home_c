#include <stdio.h>

void print(char *current);

int main(int argc, char **argv)
{
    char input[40];
    fgets(input, 40, stdin);
    print(input);
    return 0;
}

void print(char *current)
{
    if (*current == '\n')
    {
        return;
    }
    print(current + 1);
    printf("%c ", current[0]);
}
