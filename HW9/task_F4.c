#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 1001

void print_digit(char s[]);

int main(int argc, char **argv)
{
    char *first = (char *)malloc(LIMIT * sizeof(char));
    fgets(first, LIMIT, stdin);
    print_digit(first);
    free(first);
    return 0;
}

void print_digit(char s[])
{
    int freq[10] = {0};
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        if (s[i] < '0' || s[i] > '9')
        {
            i++;
            continue;
        }
        int nubmer = s[i] - '0';
        freq[nubmer]++;
        i++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d %d\n", i, freq[i]);
        }
    }
}
