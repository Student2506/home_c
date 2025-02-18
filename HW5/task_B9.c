#include <stdio.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);
    int i = 0;
    while(num[i] != '\0')
    {
        if ((num[i] - '0') % 2 == 1) {
            printf("NO");
            return 0;
        }
        i++;
    }
    printf("YES");
    return 0;
}