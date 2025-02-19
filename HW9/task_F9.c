#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10000
#define INPUT 10

void swap_negmax_last(int size, int a[]);

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(INPUT * sizeof(int));
    for (int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    swap_negmax_last(INPUT, numbers);
    for (int i = 0; i < INPUT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

void swap_negmax_last(int size, int a[])
{
    int minmax = -10000;
    int min_idx = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            if (-minmax > -a[i])
            {
                minmax = a[i];
                min_idx = i;
            }
        }
    }
    if (minmax == -10000)
        return;
    a[size - 1] ^= a[min_idx];
    a[min_idx] = a[size - 1] ^ a[min_idx];
    a[size - 1] ^= a[min_idx];
}
