#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1001

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char word[LIMIT];
    fgets(word, LIMIT, fp);
    int length = strlen(word);
    if (word[length - 1] == '\n')
        length--;
    int i = 0;
    char is_space = 0;
    while (i < length && word[i] == ' ')
    {
        i++;
    }
    while (i < length)
    {
        while (word[i] == ' ')
        {
            i++;
            is_space = 1;
        }
        if (is_space)
        {
            is_space = 0;
            fprintf(fp_out, " %c", word[i]);
        }
        else
        {
            fprintf(fp_out, "%c", word[i]);
        }
        i++;
    }
    fclose(fp_out);
    fclose(fp);
    return 0;
}
