#include <stdio.h>

#define LIMIT 12

int main(int argc, char **argv)
{
    int numbers[LIMIT] = {-1};
    float accum = 0.;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < LIMIT; i++)
    {
        accum += numbers[i];
    }

    printf("%.2f", accum / LIMIT);
    return 0;
}
