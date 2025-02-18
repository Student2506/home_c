#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum_of_numbers(int x);
int multiple_of_numbers(int x);


int main(int argc, char **argv)
{
    int first;

    scanf("%d", &first);
    for (int i = 10; i <= first; i++)
    {
        if(sum_of_numbers(i) == multiple_of_numbers(i)) printf("%d ", i);
    }

    return 0;
}

int sum_of_numbers(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int multiple_of_numbers(int x)
{
    int mul = 1;
    while(x > 0)
    {
        mul *= x % 10;
        x /= 10;
    }
    return mul;
}