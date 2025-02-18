#include <stdio.h>

int middle(int, int);

int main(int argc, char **argv)
{
    int left, right;

    scanf("%d %d", &left, &right);
    printf("%d", middle(left, right));
    return 0;
}

int middle(int left, int right)
{
    return (left + right) / 2;
}