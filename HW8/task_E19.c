#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char input[40];
    fgets(input, 40, stdin);
    int length = strlen(input) - 1;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", input[i] - '0');
    }
}
