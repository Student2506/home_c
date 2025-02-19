#include <stdio.h>

#define LIMIT 5

int main(int argc, char **argv)
{
    int numbers[LIMIT] = {-1};
    float accum = 0.;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
        accum += numbers[i];
    }

    printf("%.3f", accum / LIMIT);
    return 0;
}
