#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compartor(const void* a, const void* b);

int main(int argc, char **argv)
{
    char input[40];
    fgets(input, 40, stdin);
    int length = strlen(input) - 1;
    int* numbers = (int*) malloc(length * sizeof(int));
    for(int i = 0; i < length; i++)
    {
        numbers[i] = input[i] - '0';
    }
    qsort(numbers, length, sizeof(int), compartor);
    for(int i = 0; i < length; i++)
    {
        printf("%d", numbers[i]);
    }
    free(numbers);
    return 0;
}

int compartor(const void* a, const void* b)
{
    return (*(int*) b * 10 + *(int*) a) - (*(int*) a * 10 + *(int*) b);
}
