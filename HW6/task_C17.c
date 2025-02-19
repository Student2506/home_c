#include <stdio.h>

int sum_of_numbers(int);
int multiple_of_numbers(int);
int is_happy_number(int n);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    if (is_happy_number(first))
        printf("YES");
    else
        printf("NO");
    return 0;
}

int is_happy_number(int n)
{
    if (sum_of_numbers(n) == multiple_of_numbers(n))
        return 1;
    else
        return 0;
}
int sum_of_numbers(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int multiple_of_numbers(int x)
{
    int mul = 1;
    while (x > 0)
    {
        mul *= x % 10;
        x /= 10;
    }
    return mul;
}