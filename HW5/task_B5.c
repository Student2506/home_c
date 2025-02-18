#include <stdio.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);
    int i = 0;
    int accum = 0;
    while(num[i] != '\0')
    {
        accum += (int) num[i] - '0';
        i++;
    }
    printf("%d", accum);
    return 0;
}