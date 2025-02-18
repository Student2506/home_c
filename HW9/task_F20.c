#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

int main(int argc, char **argv)
{
    int *numbers = (int*) malloc(LIMIT * sizeof(int));
    int odd = 0, even = 0;
    for(int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
        if (numbers[i] %2 == 0) even++;
        else odd++;
    }
    if(even > odd)
    {
        for(int i = 0; i < LIMIT; i++)
        {
            if(numbers[i] % 2 == 1)
            {
                int temp = numbers[i];
                int accum = 1;
                while(temp > 10)
                {
                    int rest = temp % 10;
                    temp /= 10;
                    if(rest % 2 == 1) accum *= rest;
                }
                if(temp % 2 == 1) accum *= temp;
                numbers[i] = accum;
            }
        }
    } else {
        for(int i = 0; i < LIMIT; i++)
        {
            if(numbers[i] % 2 == 0)
            {
                int temp = numbers[i];
                int accum = 1;
                while(temp > 10)
                {
                    int rest = temp % 10;
                    temp /= 10;
                    if(rest % 2 == 0) accum *= rest;
                }
                if(temp % 2 == 0) accum *= temp;
                numbers[i] = accum;
            }
        }
    }
    for(int i = 0; i < LIMIT; i++)
    {
        printf("%d ", numbers[i]);
    }

    free(numbers);
    return 0;
}
