#include <stdio.h>

int is_prime(int);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    if (is_prime(first) == 1) printf("YES");
    else printf("NO");
    return 0;
}

int is_prime(int x)
{
    if (x <= 1) return 0;
    int i = 2;
    while(i * i <= x)
    {
        if (x % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}