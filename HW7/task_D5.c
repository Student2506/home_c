#include <stdio.h>

void bin_converter(int number);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    bin_converter(first);
    return 0;
}

void bin_converter(int number)
{
    if (number == 0 || number == 1)
    {
        printf("%d", number);
        return;
    }
    bin_converter(number / 2);
    printf("%d", number % 2);
}
