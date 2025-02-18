#include <stdio.h>

int digits_sum(int);

int main(int argc, char **argv)
{
    int first = 0;
    scanf("%d", &first);
    printf("%d", digits_sum(first));
    return 0;
}

int digits_sum(int number)
{
    if(number < 10) return number;
    return number % 10 + digits_sum(number / 10);
}
