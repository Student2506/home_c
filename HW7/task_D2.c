#include <stdio.h>

unsigned long long sum(unsigned long long);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    printf("%llu", sum(first));
    return 0;
}

unsigned long long sum(unsigned long long current)
{
    if (current == 0) return 0;
    current = current + sum(current-1);
    return current;
}
