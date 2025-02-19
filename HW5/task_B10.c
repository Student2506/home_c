#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);

    if (strlen(num) == 1)
    {
        printf("YES");
        return 0;
    }
    int i = 1;
    while (num[i] != '\0')
    {
        if (num[i] <= num[i - 1])
        {
            printf("NO");
            return 0;
        }
        i++;
    }
    printf("YES");
    return 0;
}