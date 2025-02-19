#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INPUT 1000

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(INPUT * sizeof(int));
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
        if (numbers[i] == 0)
            break;
        if (max < numbers[i])
            max = numbers[i];
        if (min > numbers[i])
            min = numbers[i];
    }
    int *freq = (int *)malloc((max - min + 1) * sizeof(int));
    for (int i = 0; i <= (max - min); i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < (max - min); i++)
    {
        freq[numbers[i] - min]++;
    }
    for (int i = 0; i < (max - min); i++)
    {
        if (freq[i] == 0)
        {
            printf("%d\n", min + i);
            break;
        }
    }
    free(freq);
    free(numbers);
    return 0;
}
