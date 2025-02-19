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
    if (num > max)
        max_find(num);
    else
        max_find(max);
}
