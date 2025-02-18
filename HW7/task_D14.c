#include <stdio.h>

int module(int number);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    while (first != 0)
    {
        if(module(first) % 2 == 1)
        {
            printf("%d ", first);
        }
        scanf("%d", &first);
    }
    return 0;
}

int module(int number)
{
    if (number >= 0) return number;
    return -number;
}
