#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10

void quicksort(int *number_list, int start, int end);

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(LIMIT * sizeof(int));
    int temp;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }

    quicksort(numbers, 0, LIMIT - 1);
    for (int i = 0; i < LIMIT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

int partition(int *number_list, int left, int right)
{
    int pivot = number_list[(left + right) / 2];
    while (1)
    {
        while ((number_list[left] % 10) < (pivot % 10))
        {
            left++;
        }
        while ((pivot % 10) < (number_list[right] % 10))
        {
            right--;
        }
        if (right <= left)
            return right;
        number_list[left] ^= number_list[right];
        number_list[right] = number_list[left] ^ number_list[right];
        number_list[left] ^= number_list[right];
        left++;
        right--;
    }
}

void quicksort(int *number_list, int start, int end)
{
    if (start >= 0 && end >= 0 && start < end)
    {
        int length = end - start;
        if ((number_list[start] % 10) < (number_list[end] % 10))
        {
            number_list[start] ^= number_list[end];
            number_list[end] = number_list[start] ^ number_list[end];
            number_list[start] ^= number_list[end];
        }
        if ((number_list[start] % 10) == (number_list[end] % 10))
        {
            if (number_list[start] < number_list[end])
            {
                number_list[start] ^= number_list[end];
                number_list[end] = number_list[start] ^ number_list[end];
                number_list[start] ^= number_list[end];
            }
        }
        if (length < 1)
            return;
        int pivot = partition(number_list, start, end);
        quicksort(number_list, start, pivot);
        quicksort(number_list, pivot + 1, end);
    }
}