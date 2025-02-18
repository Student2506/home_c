#include <stdio.h>
#include <string.h>



int main(int argc, char **argv)
{
    int limit;

    scanf("%d", &limit);
    if (limit == 0) return 0;
    if (limit == 1) {
        printf("1");
        return 0;
    }
    if (limit == 2) {
        printf("1 1");
        return 0;
    }
    int temp;
    int left = 1, right = 1;
    printf("1 1 ");
    for(int i = 2; i < limit; i++)
    {
        temp = right;
        right = left + right;
        left = temp;
        printf("%d ", right);
    }

    return 0;
}
