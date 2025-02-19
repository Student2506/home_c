#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 1000

void numbers(char *);

int main(int argc, char **argv)
{
    char *first = (char *)malloc(LIMIT * sizeof(char));
    scanf("%s", first);
    numbers(first);
    return 0;
}

void numbers(char *array)
{
    int *freq = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        freq[i] = 0;
    }
    int max = 0, min = 0;
    for (int i = 0; i < LIMIT; i++)
    {

        int nubmer = array[i] - '0';
        freq[nubmer]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d %d\n", i, freq[i]);
        }
    }
    free(array);
    free(freq);
}
