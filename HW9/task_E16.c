#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10000
#define INPUT 10


int main(int argc, char **argv)
{
    int *numbers = (int*) malloc(INPUT * sizeof(int));
    for(int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int *freq = (int*) malloc(LIMIT * sizeof(int));
    for(int i = 0; i < LIMIT; i++)
    {
        freq[i] = 0;
    }
    for(int i = 0; i < INPUT; i++)
    {
        freq[numbers[i]]++;
    }
    int max_count = INT_MIN;
    int max_number = INT_MIN;
    for(int i = 0; i < LIMIT; i++)
    {
        if(max_count < freq[i])
        {
            max_count = freq[i];
            max_number = i;
        }
    }
    printf("%d", max_number);
    free(numbers);
    free(freq);
    return 0;

}
