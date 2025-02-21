#include <stdio.h>
#include <limits.h>

int max_find(int);

int main(int argc, char **argv)
{
    printf("%d", max_find(INT_MIN));
    return 0;
}

int max_find(int max)
{
    int num;
    scanf("%d", &num);
    if (num == 0)
        return max;
    max = max_find(max);
    if (max < num)
        max = num;
    return max;
}
