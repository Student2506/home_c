#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000


int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if(ch == 'a') fputc('b', fp_out);
        else if(ch == 'b') fputc('a', fp_out);
        else if(ch == 'A') fputc('B', fp_out);
        else if(ch == 'B') fputc('A', fp_out);
        else fputc(ch, fp_out);
    }

    fclose(fp_out);
    fclose(fp);
    return 0;
}
