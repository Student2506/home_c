#include <stdio.h>

void print_next(int, int);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    print_next(1, first);
    return 0;
}

void print_next(int current, int maximum)
{
    printf("%d ", current++);
    if (current > maximum) return;
    print_next(current, maximum);
}
