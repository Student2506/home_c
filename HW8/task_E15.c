#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10

int main(int argc, char **argv)
{
    int *positive_numbers = (int *)malloc(LIMIT * sizeof(int));
    int *negative_numbers = (int *)malloc(LIMIT * sizeof(int));
    int pos_idx = 0, neg_idx = 0;
    for (int i = 0; i < LIMIT; i++)
    {
        positive_numbers[i] = INT_MIN;
        negative_numbers[i] = INT_MAX;
    }
    int number;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &number);
        if (number > 0)
        {
            positive_numbers[pos_idx] = number;
            pos_idx++;
        }
        else if (number < 0)
        {
            negative_numbers[neg_idx] = number;
            neg_idx++;
        }
    }
    for (int i = 0; i < pos_idx; i++)
    {
        printf("%d ", positive_numbers[i]);
    }
    for (int i = 0; i < neg_idx; i++)
    {
        printf("%d ", negative_numbers[i]);
    }

    free(positive_numbers);
    free(negative_numbers);
    return 0;
}
