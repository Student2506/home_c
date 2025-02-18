#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char *first_word = (char *) malloc(LIMIT * sizeof(char));
    fgets(first_word, LIMIT-1, fp);
    int length = strlen(first_word);
    if(first_word[length-1] == '\n') length--;
    int accum = 0;
    for(int i = 0; i < length; i++)
    {
        if(i > 1 && first_word[i] == ' ' && first_word[i-1] == 'a')
        {
            accum++;
        }
    }
    if(first_word[length-1] == 'a') accum++;
    fprintf(fp_out, "%d", accum);
    fclose(fp_out);
    fclose(fp);
    free(first_word);
    return 0;
}
