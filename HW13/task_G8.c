#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

void quicksort(int*, int, int);

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");
    int numbers[1000] = { -1 };
    int isNumber = 0;
    int ch = 0;
    int temp = 0;
    int index = 0;
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch >= '0' && ch <= '9' && isNumber == 0) {
            temp = ch - '0';
            isNumber = 1;
        } else if(ch >= '0' && ch <= '9' && isNumber == 1) {
            temp *= 10;
            temp += ch - '0';
            isNumber = 1;
        } else if (isNumber == 1)
        {
            isNumber = 0;
            numbers[index++] = temp;
            temp = 0;
        }

    }
    quicksort(numbers, 0, index-1);
    for(int i = 0; i < index; i++) fprintf(fp_out, "%d ", numbers[i]);
    fclose(fp_out);
    fclose(fp);
    return 0;
}


int partition(int* number_list, int left, int right)
{
    int pivot = number_list[(left + right) / 2];
    while(1)
    {
        while (number_list[left] < pivot)
        {
            left++;
        }
        while (pivot < number_list[right])
        {
            right--;
        }
        if(right <= left) return right;
        number_list[left] ^= number_list[right];
        number_list[right] = number_list[left] ^ number_list[right];
        number_list[left] ^= number_list[right];
        left++;
        right--;
    }

}

void quicksort(int* number_list, int start, int end)
{
    if(start >= 0 && end >= 0 && start < end)
    {
        int length = end - start;
        if (number_list[start] > number_list[end])
        {
            number_list[start] ^= number_list[end];
            number_list[end] = number_list[start] ^ number_list[end];
            number_list[start] ^= number_list[end];
        }
        if (length < 1) return;
        int pivot = partition(number_list, start, end);
        quicksort(number_list, start, pivot);
        quicksort(number_list, pivot+1, end);
    }
}