#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

int is_palindrom(char *);

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char first_word[LIMIT];
    fscanf(fp, "%s", first_word);
    if (is_palindrom(first_word)) fprintf(fp_out, "YES");
    else fprintf(fp_out, "NO");
    fclose(fp_out);
    fclose(fp);
    return 0;
}

int is_palindrom(char *str)
{
    int length = strlen(str);
    int isPalindrome = 1;
    for(int i = 0; i < length / 2; i++)
    {
        if(str[i] != str[length-1-i])
        {
            isPalindrome = 0;
            break;
        }
    }
    return isPalindrome;
}