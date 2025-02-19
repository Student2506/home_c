#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);
    int length = strlen(num);

    for (int i = length - 1; i >= 0; i--)
    {
        printf("%d", num[i] - '0');
    }
    return 0;
}