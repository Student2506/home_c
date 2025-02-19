#include <stdio.h>

#define LIMIT 1001

int main(int argc, char **argv)
{
    char input[LIMIT];
    fgets(input, LIMIT, stdin);
    int accum = 0;
    int left_brace = 0;
    for (int i = 0; input[i] != '.'; i++)
    {
        if (input[i] == '(')
            left_brace++;
        else
            left_brace--;

        if (left_brace == -1)
        {
            printf("NO");
            return 0;
        }
    }
    if (left_brace != 0)
        printf("NO");
    else
        printf("YES");
    return 0;
}
