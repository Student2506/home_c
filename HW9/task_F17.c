#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int main(int argc, char **argv)
{
    char col;
    int matrix[ROW][COL];
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        scanf("%d", &matrix[i][j]);
    }
    int accum = 0;
    for(int i = 0; i < ROW; i++)
    {
        accum += matrix[i][i];
    }
    printf("%d", accum);
    return 0;
}

