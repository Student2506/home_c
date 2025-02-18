#include <stdio.h>

int nod(int, int);

int main(int argc, char **argv)
{
    int first, second;
    scanf("%d%d", &first, &second);
    printf("%d", nod(first, second));
    return 0;
}

int nod(int first, int second)
{
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
    if (first == 0) return second;
    else return first;
}
