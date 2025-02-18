#include <stdio.h>

void simple_multi(int);

int main(int argc, char **argv)
{
    int input;
    scanf("%d", &input);
    simple_multi(input);
    return 0;
}

void simple_multi(int input)
{
    for (int i = 2; i <= input;)
    {
        if (input % i == 0) {
            printf("%d ", i);
            input /= i;
            i = 2;
            continue;
        }
        i++;
    }
}
