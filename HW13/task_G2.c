#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    int first;
    fscanf(fp, "%d", &first);
    int accum = 2;
    char letter = 'A';
    for(int i = 0; i < first; i+=2)
    {
        fprintf(fp_out, "%c%d", letter, accum);
        if(accum == 8) accum = 2;
        else accum += 2;
        letter += 1;
    }
    fclose(fp_out);
    fclose(fp);
}
