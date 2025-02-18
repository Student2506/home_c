#include <stdio.h>

int is2pow(int n);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    if (first == 1) {
        printf("YES");
        return 0;
    }
    if (is2pow(first) == 1) printf("YES");
    else printf("NO");
    return 0;
}

int is2pow(int n)
{
    if (n == 1 || n == 2) return 1;
    if (n % 2 == 1) return 0;

    return is2pow(n / 2);
}