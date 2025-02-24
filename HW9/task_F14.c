#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

int sum_between_ab(int from, int to, int size, int a[]);

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(LIMIT * sizeof(int));
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    change_max_min(LIMIT, numbers);
    for (int i = 0; i < LIMIT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

int sum_between_ab(int from, int to, int size, int a[])
{
    int counter = 0;
    if (from > to)
    {
        from ^= to;
        to = from ^ to;
        from ^= to;
    }
    for (int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
        {
            counter += a[i];
        }
    }
    return counter;
}
