#include <stdio.h>

int main(int argc, char **argv)
{
    int low, high;
    int accum = 0;

    scanf("%d %d", &low, &high);

    for (int i = low; i <= high; i++)
    {
        accum += i*i;
    }
    printf("%d\n", accum);
    return 0;
}