#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int i = 0;
    while (num[i] != '\0')
    {
        if (minimum > num[i])
            minimum = num[i];
        if (maximum < num[i])
            maximum = num[i];
        i++;
    }
    printf("%d %d", minimum - '0', maximum - '0');
    return 0;
}