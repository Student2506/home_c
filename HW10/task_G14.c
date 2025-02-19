#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char *first_word = (char *)malloc(LIMIT * sizeof(char));
    int *spaces = (int *)malloc(LIMIT * sizeof(int));
    fgets(first_word, LIMIT - 1, fp);
    int length = strlen(first_word);

    int j = 1;
    int skip_space = 0;
    while (first_word[skip_space] == ' ')
    {
        skip_space++;
    }
    if (skip_space > 0)
        spaces[0] = skip_space - 1;
    else
        spaces[0] = 0;
    for (int i = skip_space + 1; i < length; i++)
    {
        if (first_word[i] == ' ')
        {
            if (first_word[i + 1] == ' ')
                continue;
            spaces[j] = i;
            j++;
        }
    }
    spaces[j] = length;
    fprintf(fp_out, "Hello, ");
    for (int i = spaces[1] + 1; i < spaces[2]; i++)
    {
        fprintf(fp_out, "%c", first_word[i]);
    }
    fprintf(fp_out, " ");
    for (int i = spaces[0]; i < spaces[1]; i++)
    {
        fprintf(fp_out, "%c", first_word[i]);
    }
    fprintf(fp_out, "!");
    fclose(fp_out);
    fclose(fp);
    free(first_word);
    free(spaces);
    return 0;
}
