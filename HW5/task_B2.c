#include <stdio.h>

int main(int argc, char **argv)
{
    int low, high;

    scanf("%d %d", &low, &high);
    for (int i = low; i < high; i++)
    {
        printf("%d ", i * i);
    }
    printf("%d\n", high * high);
    return 0;
}