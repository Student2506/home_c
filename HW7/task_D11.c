#include <stdio.h>

int bin_converter(int number);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    printf("%d", bin_converter(first));
    return 0;
}

int bin_converter(int number)
{
    if (number == 0 || number == 1)
    {
        // printf("%d", number);
        return number;
    }
    return number % 2 + bin_converter(number / 2);
}
