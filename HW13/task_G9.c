#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1001

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char *first_word = (char *) malloc(LIMIT * sizeof(char));
    char *freq = (char *) malloc(26 * 2 * sizeof(char));
    fgets(first_word, LIMIT-1, fp);
    int length = strlen(first_word);
    for (int i = 0; i < 52; i++) freq[i] = 0
        ;
    for(int i = 0; i < LIMIT; i++)
    {
        if(first_word[i] >= 'a' && first_word[i] <= 'z'){
            freq[first_word[i] - 'a']++;
        }
        if(first_word[i] >= 'A' && first_word[i] <= 'Z'){
            freq[first_word[i] - 'A' + 26]++;
        }
    }
    for(int i = 0; i < LIMIT; i++)
    {
        if(first_word[i] == ' ') continue;
        if (first_word[i] >= 'a' && first_word[i] <= 'z') {
            if(freq[first_word[i] - 'a'] > 0)
            {
                freq[first_word[i] - 'a'] = 0;
                fprintf(fp_out, "%c", first_word[i]);
            }
        }
        if (first_word[i] >= 'A' && first_word[i] <= 'Z') {
            if(freq[first_word[i] - 'A' + 26] > 0)
            {
                freq[first_word[i] - 'A' + 26] = 0;
                fprintf(fp_out, "%c", first_word[i]);
            }
        }
    }
    fclose(fp_out);
    fclose(fp);
    free(first_word);
    return 0;
}
