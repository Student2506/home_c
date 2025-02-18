#include <stdio.h>
#include <limits.h>

int grow_up(int);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    if (grow_up(first) == 1) printf("YES");
    else printf("NO");
    return 0;
}

int grow_up(int input)
{
    int accum = INT_MAX;
    if (input < 10) return 1;
    while(input)
    {
        if(input % 10 < accum && input >= 10) {
            accum = input % 10;
            input /= 10;
            continue;
        } else if (input < 10 && input < accum)
        {
            return 1;
        } else {
            return 0;
        }
    }
}
