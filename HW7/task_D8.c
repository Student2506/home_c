#include <stdio.h>

void print(int, int);

int main(int argc, char **argv)
{
    int first = 0ll;
    int second = 0ll;
    scanf("%d%d", &first, &second);
    print(first, second);
    return 0;
}

void print(int left, int right)
{
    if (left == right) {
        printf("%d ", left);
        return;
    }
    printf("%d ", left);
    if (left > right) {
        print(left-1, right);
    } else {
        print(left+1, right);
    }
}
