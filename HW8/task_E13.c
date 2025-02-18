#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10


int main(int argc, char **argv)
{
    int *numbers = (int*) malloc(LIMIT * sizeof(int));
    int *zero_numbers = (int*) malloc(LIMIT * sizeof(int));
    for(int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
        zero_numbers[i] = -1;
    }

    int y = 0;
    for(int i = 0; i < LIMIT; i++)
    {
        if(numbers[i] / 10 % 10 ==0 || numbers[i] < 10)
        {
            zero_numbers[y] = numbers[i];
            y++;
        }
    }
    y = 0;
    while (zero_numbers[y] != -1 && y < 10)
    {
        printf("%d ", zero_numbers[y]);
        y++;
    }
    free(numbers);
    free(zero_numbers);
    return 0;
}
