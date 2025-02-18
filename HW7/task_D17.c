#include <stdio.h>

int akkerman(int, int);

int main(int argc, char **argv)
{
    int left, right;

    scanf("%d %d", &left, &right);
    printf("%d", akkerman(left, right));
    return 0;
}

int akkerman(int n, int m)
{
    if(n == 0) return m + 1;
    if(m == 0) return akkerman(n - 1, 1);
    return akkerman(n-1, akkerman(n, m-1));
}