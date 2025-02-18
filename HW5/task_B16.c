#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    int first, second;

    scanf("%d %d", &first, &second);
    while (first != 0 && second != 0)
    {
        if (first > second)
        {
            first %= second;
        }
        else
        {
            second %= first;
        }
    }
    int result;
    if (first == 0) result = second;
    else result = first;
    printf("%d", result);

    return 0;
}