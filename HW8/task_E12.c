#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10

void quicksort(int *, int, int, int);

int main(int argc, char **argv)
{
    int *numbers = (int *)malloc(LIMIT * sizeof(int));
    int temp;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }

    quicksort(numbers, 0, LIMIT / 2 - 1, 1);
    quicksort(numbers, LIMIT / 2, LIMIT - 1, -1);
    for (int i = 0; i < LIMIT; i++)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}

void swap(int *number_list, int left, int right)
{
    int temp = number_list[left];
    number_list[left] = number_list[right];
    number_list[right] = temp;
}

int partition(int *number_list, int left, int right)
{
    int pivot = number_list[(left + right) / 2];
    while (1)
    {
        while (number_list[left] < pivot)
        {
            left++;
        }
        while (pivot < number_list[right])
        {
            right--;
        }
        if (right <= left)
            return right;
        swap(number_list, left, right);
        left++;
        right--;
    }
}

int partition_reverse(int *number_list, int left, int right)
{
    int pivot = number_list[(left + right) / 2];
    while (1)
    {
        while (number_list[left] > pivot)
        {
            left++;
        }
        while (pivot > number_list[right])
        {
            right--;
        }
        if (right <= left)
            return right;
        swap(number_list, left, right);
        left++;
        right--;
    }
}

void quicksort(int *number_list, int start, int end, int reverse)
{
    if (start >= 0 && end >= 0 && start < end)
    {
        int length = end - start;
        if (number_list[start] > number_list[end])
        {
            swap(number_list, start, end);
        }
        if (length < 1)
            return;
        int pivot;
        if (reverse == -1)
        {
            pivot = partition_reverse(number_list, start, end);
        }
        else
        {
            pivot = partition(number_list, start, end);
        }
        quicksort(number_list, start, pivot, reverse);
        quicksort(number_list, pivot + 1, end, reverse);
    }
}