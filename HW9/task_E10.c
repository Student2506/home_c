#include <stdio.h>


#define LIMIT 12

int main(int argc, char **argv)
{
    int numbers[LIMIT] = { -1 };
    int temp;
    for(int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for(int y = 0; y < 4; y++)
    {
        temp = numbers[LIMIT-1];
        for(int i = LIMIT-1; i > 0; i--)
        {
            numbers[i] = numbers[i-1];
        }
        numbers[0] = temp;
    }

    for(int i = 0; i < LIMIT; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}
