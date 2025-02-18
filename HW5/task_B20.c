#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_prime(int x);


int main(int argc, char **argv)
{
    int first;

    scanf("%d", &first);
    if (first == 1) {
        printf("NO");
        return 0;
    }
    if (is_prime(first) == 0) {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return 0;
}

int is_prime(int x)
{
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