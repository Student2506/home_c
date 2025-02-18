#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char *first_word = (char *) malloc(LIMIT * sizeof(char));
    int *spaces = (int *) malloc(LIMIT * sizeof(int));
    fgets(first_word, LIMIT-1, fp);
    int length = strlen(first_word);
    spaces[0] = 0;
    int j = 1;
    for(int i = 0; i < length; i++)
    {
        if(first_word[i] == ' ')
        {
            spaces[j] = i;
            j++;
        }
    }
    spaces[j] = length;
    int max = -1;
    int best_start = 0, best_finish = 0;
    for(int i = 1; i <= j; i++)
    {
        if(max < (spaces[i] - spaces[i-1]))
        {
            max = spaces[i] - spaces[i-1];
            best_start = spaces[i-1];
            best_finish = spaces[i]-1;
        }
    }
    for(int i = best_start; i <= best_finish; i++)
    {
        if(first_word[i] != ' ' && first_word[i] != EOF)
            fprintf(fp_out, "%c", first_word[i]);
    }
    fclose(fp_out);
    fclose(fp);
    free(first_word);
    return 0;
}
