#include <stdio.h>
#include <limits.h>

#define LIMIT 5

int main(int argc, char **argv)
{
    int numbers[LIMIT] = { -1 };
    int accum = INT_MAX;
    for(int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for(int i = 0; i < LIMIT; i++)
    {
        if(accum > numbers[i]) accum = numbers[i];
    }

    printf("%d", accum);
    return 0;
}
