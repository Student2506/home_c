#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000
#define INPUT 10


int main(int argc, char **argv)
{
    int *numbers = (int*) malloc(INPUT * sizeof(int));
    int *positive_numbers = (int*) malloc(LIMIT * sizeof(int));
    int *negative_numbers = (int*) malloc(LIMIT * sizeof(int));
    for(int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for(int i = 0; i < LIMIT; i++)
    {
        positive_numbers[i] = 0;
        negative_numbers[i] = 0;
    }
    for(int i = 0; i < INPUT; i++)
    {
        if(numbers[i] >= 0)
        {
            positive_numbers[numbers[i]]++;
        }
        else
        {
            negative_numbers[-numbers[i]]++;
        }
    }
    for(int i = 0; i < INPUT; i++)
    {
        if(positive_numbers[numbers[i]] == 1)
        {
            printf("%d ", numbers[i]);
        }
        if(negative_numbers[-numbers[i]] == 1)
        {
            printf("%d ", numbers[i]);
        }
    }
    free(numbers);
    free(positive_numbers);
    free(negative_numbers);
    return 0;
}
