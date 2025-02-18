#include <stdio.h>

int main(int argc, char **argv)
{
    int num;

    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("NO");
    } else {
        printf("YES");
    }
    return 0;
}