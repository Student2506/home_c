#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    int accum = 0;
    char word[LIMIT];
    fgets(word, LIMIT, fp);
    if (word[strlen(word) - 1] == '\n')
        word[strlen(word) - 1] = '\0';
    for (int i = 0; i < 2; i++)
    {
        fprintf(fp_out, "%s, ", word);
    }
    fprintf(fp_out, "%s %d", word, strlen(word));
    fclose(fp);
    fclose(fp_out);
}
