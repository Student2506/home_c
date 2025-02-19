#include <stdio.h>
#include <limits.h>

#define LIMIT 10

int main(int argc, char **argv)
{
    int numbers[LIMIT] = {-1};
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int max_idx = -1, min_idx = -1;

    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < LIMIT; i++)
    {
        if (minimum > numbers[i])
        {
            minimum = numbers[i];
            min_idx = i + 1;
        }
        if (maximum < numbers[i])
        {
            maximum = numbers[i];
            max_idx = i + 1;
        }
    }

    printf("%d %d %d %d", max_idx, maximum, min_idx, minimum);
    return 0;
}
