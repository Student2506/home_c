#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define LIMIT 10000
#define INPUT 10

int compression(int a[], int b[], int N);

int main(int argc, char **argv)
{
    char str[LIMIT];
    scanf("%[^\n]", str);

    // printf("%d", strlen(str));
    int length = strlen(str) / 2 + 1;
    int *arr = (int *)malloc(length * sizeof(int));
    int *arr2 = (int *)malloc(length * sizeof(int));
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '1')
        {
            arr[j] = 1;
            j++;
        }
        if (str[i] == '0')
        {
            arr[j] = 0;
            j++;
        }
    }
    int n = compression(arr, arr2, length);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    free(arr);
    free(arr2);
    return 0;
}

int compression(int a[], int b[], int N)
{
    int ch = 0;
    int b_idx = 0;
    int accum = 0;

    for (int i = 0; i < N; i++)
    {
        if (ch == a[i])
        {
            accum++;
        }
        else
        {
            b[b_idx] = accum;
            accum = 1;
            ch = ch == 0 ? 1 : 0;
            b_idx++;
        }
    }
    b[b_idx] = accum;
    return b_idx + 1;
}
