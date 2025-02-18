#include <stdio.h>

int main(int argc, char **argv)
{
    char num[40];
    int numbers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    scanf("%s", &num);
    int i = 0;
    int result = 0;
    while(num[i] != '\0')
    {
        numbers[num[i] - '0'] += 1;
        i++;
    }
    for (int i=0; i<10; i++)
    {
        if (numbers[i] > 1)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}