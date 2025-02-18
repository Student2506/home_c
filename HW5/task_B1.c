#include <stdio.h>

int main(int argc, char **argv)
{
    int input;

    scanf("%d", &input);
    for (int i = 1; i <= input; i++)
    {
        printf("%d %d %d\n", i, i*i, i*i*i);
    }
    return 0;
}
