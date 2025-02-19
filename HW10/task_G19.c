#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1001

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char freq[26] = {0};
    char word[LIMIT];
    fgets(word, LIMIT, fp);
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        freq[word[i] - 'a']++;
    }
    char center = '0';
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 1)
        {
            center = 'a' + i;
            break;
        }
    }
    int available_letters = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] >= 2)
            available_letters += freq[i] / 2;
    }
    int new_length = available_letters * 2;
    if (center != '0')
        new_length = available_letters * 2 + 1;
    char *new_string = (char *)malloc((new_length + 1) * sizeof(char));

    int j = 0;
    int i = 0;
    while (j < available_letters)
    {
        while (freq[i] < 2)
            i++;
        new_string[j] = 'a' + i;
        new_string[new_length - j - 1] = 'a' + i;
        freq[i] -= 2;
        j++;
    }
    if (center != '0')
        new_string[new_length / 2] = center;
    new_string[new_length] = '\0';
    fprintf(fp_out, "%s", new_string);
    free(new_string);
    fclose(fp_out);
    fclose(fp);
    return 0;
}
