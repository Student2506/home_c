#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10000
#define INPUT 30

void sort_sum(int size, int *a);

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(INPUT * sizeof(int));
    for (int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    int *source = (int *)malloc(INPUT * sizeof(int));
    for (int i = 0; i < INPUT; i++)
    {
        source[i] = numbers[i];
    }
    sort_sum(INPUT, numbers);
    int a, b;
    int skip_a = 0;
    for (int i = 0; i < INPUT; i++)
    {
        if (source[i] == numbers[0] && !skip_a)
        {
            a = i;
            skip_a = 1;
            continue;
        }
        if (source[i] == numbers[1])
            b = i;
    }
    if (a < b)
        printf("%d %d", a, b);
    else
        printf("%d %d", b, a);
    free(source);
    free(numbers);
    return 0;
}

void sort_sum(int size, int *a)
{
    for (int i = 1; i < size; i++)
    {
        int item_to_insert = a[i];
        int j = i;
        while (j > 0 && item_to_insert < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = item_to_insert;
    }
}
