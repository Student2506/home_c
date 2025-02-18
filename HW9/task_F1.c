#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10000
#define INPUT 20

void sort_array(int size, int a[]);

int main(int argc, char **argv)
{
    int *numbers = (int*) malloc(INPUT * sizeof(int));
    for(int i = 0; i < INPUT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    sort_array(INPUT, numbers);
    for (int i = 0; i < INPUT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;

}

void sort_array(int size, int a[])
{
    for(int i = 1; i < size; i++)
    {
        int item_to_insert = a[i];
        int j = i;
        while (j > 0 && item_to_insert < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = item_to_insert;
    }
}
