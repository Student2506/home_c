#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 101


int main(int argc, char **argv)
{
    // int *freq = (int*) malloc(LIMIT * sizeof(int));
    char freq[26] = { 0 };
    char freq_second[26] = { 0 };
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char first_word[LIMIT];
    char second_word[LIMIT];
    fscanf(fp, "%s %s", first_word, second_word);

    for(int i = 0; i < strlen(first_word); i++)
    {
        freq[first_word[i] - 'a']++;
    }
    for(int i = 0; i < strlen(second_word); i++)
    {
        freq_second[second_word[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] == 1 && freq_second[i] == 1)
        {
            fprintf(fp_out, "%c ", 'a' + i);
        }
    }
    fclose(fp_out);
    fclose(fp);
    return 0;
}
