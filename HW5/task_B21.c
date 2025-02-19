#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_prime(int x);

int main(int argc, char **argv)
{
    char *first;
    char code;

    while ((code = getchar()) != '\n' && code != EOF)
    {
        if (code == '.')
            continue;
        if (code >= 65 && code <= 90)
        {
            printf("%c", code + 32);
        }
        else
        {
            printf("%c", code);
        }
    }
    return 0;
}
