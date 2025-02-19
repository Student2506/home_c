#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int medium(int a[ROW][COL]);

int main(int argc, char **argv)
{
    char col;
    int matrix[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            scanf("%d", &matrix[i][j]);
    }
    int med = medium(matrix);
    int accum = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (matrix[i][j] > med)
                accum++;
        }
    }

    printf("%d", accum);
    return 0;
}

int medium(int a[ROW][COL])
{
    int accum = 0;
    for (int i = 0; i < ROW; i++)
    {
        accum += a[i][i];
    }
    return accum / 5;
}
