#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

int count_bigger_abs(int n, int a[]);
;

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(LIMIT * sizeof(int));
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("%d", count_bigger_abs(LIMIT, numbers));
    free(numbers);
    return 0;
}

int count_bigger_abs(int n, int a[])
{
    int max_value = -10000;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (max_value < a[i])
        {
            max_value = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int temp = a[i] >= 0 ? a[i] : -a[i];
        if (temp > max_value)
            counter++;
    }
    return counter;
}
