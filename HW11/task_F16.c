#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    char col;
    int row;
    scanf("%c%d", &col, &row);
    col = col > 90 ? col : col + 32;
    if(row % 2 == 1)        //odd row
    {
        if ((col - 'a') % 2 == 1) printf("WHITE");
        else printf("BLACK");
    }
    else    //even row
    {
        if ((col - 'a') % 2 == 1) printf("BLACK");
        else printf("WHITE");
    }

    return 0;
}

