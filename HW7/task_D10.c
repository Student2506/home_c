#include <stdio.h>

int is_prime(int n, int delitel);

int main(int argc, char **argv)
{
    int first = 0;
    scanf("%d", &first);
    if (is_prime(first, 2) == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}

int is_prime(int n, int delitel)
{
    if (n <= 1)
        return 0;
    if (delitel * delitel > n)
        return 1;
    if (n % delitel == 0)
        return 0;
    else
        return is_prime(n, delitel + 1);
}
