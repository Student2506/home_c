#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 1001

int find_max_array(int size, int a[]);

int main(int argc, char **argv)
{
    // char* first = (char*) malloc(LIMIT * sizeof(char));;
    // fgets(first, LIMIT, stdin);
    // print_digit(first);
    // free(first);
    return 0;
}

int find_max_array(int size, int a[])
{
    int max = -1000;
    for (int i = 0; i < size; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    return max;
}
