#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000
#define INPUT 10

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(INPUT * sizeof(int));
    int *freq = (int *)malloc(LIMIT * sizeof(int));

    for (int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < LIMIT; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < INPUT; i++)
    {
        freq[numbers[i]]++;
    }
    for (int i = 0; i < INPUT; i++)
    {
        if (freq[numbers[i]] > 1)
        {
            printf("%d ", numbers[i]);
            freq[numbers[i]] = 0;
        }
    }
    free(freq);
    free(numbers);
    return 0;
}
