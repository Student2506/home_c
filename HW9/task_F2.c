#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10000
#define INPUT 20

void sort_sum(int size, int a[]);

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(INPUT * sizeof(int));
    for (int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    sort_sum(INPUT, numbers);
    for (int i = 0; i < INPUT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

int comparator(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a % 2 == 0 && b % 2 == 1)
        return 0; // move
    return 1;     // leave as it is
}

void sort_sum(int size, int a[])
{
    for (int i = 1; i < size; i++)
    {
        int item_to_insert = a[i];
        int j = i;
        while (j > 0 && comparator(item_to_insert, a[j - 1]) == 0)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = item_to_insert;
    }
}
