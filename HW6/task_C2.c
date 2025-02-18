#include <stdio.h>

int power(int, int);

int main(int argc, char **argv)
{
    int n, p;

    scanf("%d %d", &n, &p);
    printf("%d", power(n, p));
    return 0;
}

int power(int n, int p)
{
    int counter = 1;
    for(int i = 0; i < p; i++) {
        counter *= n;
    }
    return counter;
}
