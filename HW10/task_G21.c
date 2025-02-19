#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

void print_star(int, int, FILE *);
int read_file_at_once(FILE *fp);

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    int star_count = read_file_at_once(fp);
    int accum = 0;
    int row = -1;
    for (int i = 1;; i++)
    {
        accum += i;
        if (star_count <= accum)
        {
            row = i;
            break;
        }
    }
    if (star_count < accum)
        fprintf(fp_out, "NO");
    else
    {
        for (int i = 1; i <= row; i++)
        {
            print_star((row - 1) * 2 + 1, i, fp_out);
        }
    }
    fclose(fp_out);
    fclose(fp);
    return 0;
}

void print_star(int row_length, int star_quantity, FILE *fp_out)
{
    int star_length = star_quantity * 2 - 1;
    for (int j = 0; j < (row_length - star_length) / 2; j++)
        fprintf(fp_out, " ");
    for (int j = 0; j < star_quantity; j++)
        fprintf(fp_out, "* ");
    fprintf(fp_out, "\n");
}

int read_file_at_once(FILE *fp)
{
    char *word;
    // fgets(word, LIMIT, fp);
    fseek(fp, 0L, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    word = malloc(length + 1);
    size_t size = fread(word, 1, length, fp);
    word[size] = '\0';
    int star_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (word[i] == '*')
            star_count++;
    }
    free(word);
    return star_count;
}
