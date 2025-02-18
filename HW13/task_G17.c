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
    if(word[length-1] == '\n') length--;
    int first, second;
    int i = 0;
    while(i < length)
    {
        while(word[i]==' ') i++;
        first = i;
        i++;
        if(i == length) break;
        while(word[i]==' ') i++;
        second = i;
        word[first] ^= word[second];
        word[second] = word[first] ^ word[second];
        word[first] ^= word[second];
        i++;
    }
    fprintf(fp_out, "%s", word);
    // i++;
    // if(length % 2 == 1) fprintf(fp_out, "%c", word[i]);
    fclose(fp_out);
    fclose(fp);
    return 0;
}
