#include <stdio.h>

#define LIMIT 10

int main(int argc, char **argv)
{
    int numbers[LIMIT] = {-1};
    int temp;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < LIMIT; i++)
    {
        if (i < 2)
        {
            temp = numbers[i];
            numbers[i] = numbers[4 - i];
            numbers[4 - i] = temp;
        }
        else if (i >= 5 && i < 7)
        {
            temp = numbers[i];
            numbers[i] = numbers[9 - i + 5];
            numbers[9 - i + 5] = temp;
        }
        printf("%d ", numbers[i]);
    }
    return 0;
}
