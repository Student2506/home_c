#include <stdio.h>

void sequence(int, int, int, int);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    sequence(1, 0, first, 0);
    return 0;
}

void sequence(int current, int count, int limit, int print)
{
    if(print == limit) return;
    if(current == count) {
        sequence(current+1, 0, limit, print);
        return;
    }
    printf("%d ", current);
    print++;
    sequence(current, count+1, limit, print);
}
