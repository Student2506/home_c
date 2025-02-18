#include <stdio.h>

void print(unsigned long long);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    print(first);
    return 0;
}

void print(unsigned long long current)
{
    if (current == 0) return;
    printf("%d ", current);
    print(current-1);
}
