#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 21

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char word[LIMIT] = {0};
    fgets(word, LIMIT, fp);
    int length = strlen(word);
    char new_word[LIMIT] = {'\0'};
    int i = 1, j = 1;
    new_word[0] = word[0];
    while (i < length)
    {
        if (word[i] != 'a' && word[i] != 'e' && word[i] != 'h' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u' && word[i] != 'w' && word[i] != 'y')
        {
            switch (word[i])
            {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                new_word[j] = '1';
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                new_word[j] = '2';
                break;
            case 'd':
            case 't':
                new_word[j] = '3';
                break;
            case 'l':
                new_word[j] = '4';
                break;
            case 'm':
            case 'n':
                new_word[j] = '5';
                break;
            case 'r':
                new_word[j] = '6';
                break;
            }
            j++;
        }
        i++;
    }
    int total_length = strlen(new_word);
    char result[5] = {0};
    for (int i = 0; i < 4; i++)
        result[i] = '0';
    i = 1;
    j = 1;
    result[0] = new_word[0];
    char current = new_word[0];
    while (i <= total_length && j < 4)
    {
        if (new_word[i] != current && new_word[i] != '\0')
        {
            current = new_word[i];
            result[j] = new_word[i];
            j++;
        }
        i++;
    }
    fprintf(fp_out, "%s", result);
    fclose(fp_out);
    fclose(fp);
    return 0;
}
