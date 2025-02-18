#include <stdio.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);

    int i = 0;
    int odd = 0, even = 0;
    while (num[i] != '\0')
    {
        if ((num[i] - '0') % 2 == 0) even++;
        else odd++;
        i++;
    }
    printf("%d %d", even, odd);
    return 0;
}