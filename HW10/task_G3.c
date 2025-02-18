#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char word[LIMIT];
    fscanf(fp, "%[^\n]%*c", word);
    int length = strlen(word);
    for(int i = 0; i < length-1; i++)
    {
        if(word[i] == word[length-1]) fprintf(fp_out, "%d ", i);
    }
    fclose(fp_out);
    fclose(fp);
}
