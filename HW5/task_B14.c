#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 10000000

int main(int argc, char **argv)
{
    int num[LIMIT] = {0};
    char numbers[LIMIT];

    int i = 0;
    fgets(numbers, LIMIT, stdin);
    char *pch = strtok(numbers, " ");
    while (pch != NULL)
    {
        num[i] = atoi(pch);
        pch = strtok(NULL, " ");
        i++;
    }

    i = 0;
    while (num[i] != 0)
    {
        i++;
    }
    printf("%d", i);
    return 0;
}