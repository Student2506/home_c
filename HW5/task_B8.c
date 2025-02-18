#include <stdio.h>

int main(int argc, char **argv)
{
    char num[40];

    scanf("%s", &num);
    int nine_qty = 0;
    int i = 0;
    while(num[i] != '\0')
    {
        if(num[i] == '9') nine_qty++;
        if(nine_qty > 1)
        {
            printf("NO");
            return 0;
        }
        i++;
    }
    if (nine_qty == 0)
    {
        printf("NO");
    } else
    {
        printf("YES");
    }
    return 0;
}