#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 10000000

int main(int argc, char **argv)
{
    int num[LIMIT] = {0};
    char numbers[LIMIT];

    int count_total = 0;
    fgets(numbers, LIMIT, stdin);
    char *pch = strtok(numbers, " ");
    while (pch != NULL)
    {
        num[count_total] = atoi(pch);
        pch = strtok(NULL, " ");
        count_total++;
    }
    count_total--;
    int count_even = 0;
    for (int i = 0; i < count_total; i++)
    {
        if ((num[i] % 2) == 0)
            count_even++;
    }
    printf("%d", count_even);
    return 0;
}