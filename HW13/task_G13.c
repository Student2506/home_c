#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    char *file_path = (char *) malloc(LIMIT * sizeof(char));
    int *spaces = (int *) malloc(LIMIT * sizeof(int));
    fgets(file_path, LIMIT-1, fp);
    int length = strlen(file_path);
    int file_end = length;
    for(int i = length; file_path[i] != '/'; i--)
    {
        file_end = i;
    }
    for(int i = 0; i < file_end; i++)
    {
        fprintf(fp_out, "%c", file_path[i]);
    }
    int cursor = file_end;
    while(file_path[cursor] != EOF && file_path[cursor] != '.' && file_path[cursor] != '\n')
    {
        fprintf(fp_out, "%c", file_path[cursor]);
        cursor++;
    }
    fprintf(fp_out, ".html");
    fclose(fp);
    free(file_path);
    return 0;
}
