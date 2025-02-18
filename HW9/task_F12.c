#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

void change_max_min(int size, int a[]);

int main(int argc, char **argv)
{
    int *numbers = (int*) malloc(LIMIT * sizeof(int));
    for(int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    change_max_min(LIMIT, numbers);
    for(int i = 0; i < LIMIT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

void change_max_min(int size, int a[])
{
    int max = -10000;
    int min = 10000;
    int max_idx = 0; int min_idx = 0;
    for(int i = 0; i < size; i++)
    {
        if(max < a[i])
        {
            max = a[i];
            max_idx = i;
        }
        if(min > a[i])
        {
            min = a[i];
            min_idx = i;
        }
    }
    a[min_idx] ^= a[max_idx];
    a[max_idx] = a[min_idx] ^ a[max_idx];
    a[min_idx] ^= a[max_idx];
}
