#include <stdio.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);
    int i = 1;
    int result = 0;
    int previous = num[0];
    while (num[i] != '\0')
    {
        if (previous == num[i])
        {
            printf("YES");
            return 0;
        }
        previous = num[i];
        i++;
    }
    printf("NO");
    return 0;
}