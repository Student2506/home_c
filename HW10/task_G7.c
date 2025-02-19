#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10001

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char first_word[LIMIT];
    fgets(first_word, LIMIT - 1, fp);
    int length = strlen(first_word);
    int lowercase = 0, uppercase = 0;
    for (int i = 0; i < length; i++)
    {
        if (first_word[i] >= 'a' && first_word[i] <= 'z')
            lowercase++;
        if (first_word[i] >= 'A' && first_word[i] <= 'Z')
            uppercase++;
    }
    fprintf(fp_out, "%d %d", lowercase, uppercase);
    fclose(fp_out);
    fclose(fp);
    return 0;
}
