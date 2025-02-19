#include <stdio.h>

int acounter(void);

int main(int argc, char **argv)
{
    printf("%d", acounter());
    return 0;
}

int acounter(void)
{
    char ch;
    int i = 0;
    scanf("%c", &ch);
    if (ch == '.')
        return 0;
    else if (ch == 'a')
    {
        i++;
    }
    return i + acounter();
}