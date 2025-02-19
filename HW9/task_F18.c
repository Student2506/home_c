#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int max_element_per_row(int[]);

int main(int argc, char **argv)
{
    char col;
    int matrix[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            scanf("%d", &matrix[i][j]);
    }
    int accum = 0;
    for (int i = 0; i < ROW; i++)
    {
        accum += max_element_per_row(matrix[i]);
    }
    printf("%d", accum);
    return 0;
}

int max_element_per_row(int a[])
{
    int max = -10000;
    for (int i = 0; i < COL; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    return max;
}
