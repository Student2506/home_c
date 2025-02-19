#include <stdio.h>

char *num_sum(int);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    printf("%s", num_sum(first));
    return 0;
}

char *num_sum(int first)
{
    int accum = 0;
    while (first >= 10)
    {
        accum += first % 10;
        first /= 10;
    }
    accum += first;
    if (accum % 2 == 0)
        return "YES";
    else
        return "NO";
}
