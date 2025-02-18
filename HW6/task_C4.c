#include <stdio.h>
#include <limits.h>

int summation(int);

int main(int argc, char **argv)
{
    int maximum = INT_MIN;
    int input;
    while (scanf("%d", &input) == 1 && input != 0)
    {
        int temp = summation(input);
        if (maximum < temp) maximum = temp;
    }

    printf("%d", maximum);
    return 0;
}

int summation(int number)
{
    if (number >= 2)
    {
        return number * number + 4 * number + 5;
    }
    else if (number < -2)
    {
        return 4;
    }
    else
    {
        return number * number;
    }
}