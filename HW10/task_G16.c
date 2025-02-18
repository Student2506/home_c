#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char word[LIMIT];
    fscanf(fp, "%[^\n]%*c", word);
    int length = strlen(word);
    int i = 0;
    while(i < length)
    {
        if(word[i] == 'L' && (i+3) < length && word[i+1] == 'i' && word[i+2] == 'n' && word[i+3] == 'g')
        {
            fprintf(fp_out, "Cao");
            i += 4;
        }
        else
        {
            fprintf(fp_out, "%c", word[i]);
            i++;
        }
    }
    fclose(fp_out);
    fclose(fp);
    return 0;
}
