#include <stdio.h>


#define LIMIT 12

int main(int argc, char **argv)
{
    int numbers[LIMIT] = { -1 };
    int temp;
    for(int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for(int i = 0; i < LIMIT; i++)
    {
        if(i < 2)
        {
            temp = numbers[i];
            numbers[i] = numbers[3-i];
            numbers[3-i] = temp;
        }
        else if (i >= 4 && i < 6)
        {
            temp = numbers[i];
            numbers[i] = numbers[7-i+4];
            numbers[7-i+4] = temp;
        }
        else if (i >= 8 && i < 10)
        {
            temp = numbers[i];
            numbers[i] = numbers[11-i+8];
            numbers[11-i+8] = temp;
        }
        printf("%d ", numbers[i]);
    }
    return 0;
}
