#include "db.h"
#include "temp_api.h"
#include <stdlib.h>

void add_record(TempDate array[], int *current_length, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature)
{
    TempDate new_element;
    new_element.year = year;
    new_element.MM = month;
    new_element.dd = day;
    new_element.hh = hour;
    new_element.temperature = temperature;
    array[*current_length] = new_element;
    *current_length++;
}

void remove_record(TempDate array[], int *current_length, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute)
{
    int record_to_delete = -1;
    for (int i = 0; i < *current_length; i++)
    {
        if (array[i].year == year && array[i].MM == month && array[i].dd == day && array[i].hh == hour && array[i].mm == minute)
        {
            record_to_delete = i;
        }
        if (record_to_delete != -1)
        {
            // Если текущая запись для удаления последняя, просто уменьшаем размер, иначе смещаемся вверх
            if (i == current_length - 1)
                break;
            array[i] = array[i + 1];
        }
    }
    *current_length--;
}

TempDate *create_array(int intial_size)
{
    TempDate *new_array = malloc(intial_size * sizeof(TempDate));
    return new_array;
}

int partition(TempDate *array, int left, int right)
{
    TempDate pivot = array[(left + right) / 2];
    while (1)
    {
        int pivot_date = convert_date_to_int(pivot);
        int current_value = convert_date_to_int(array[left]);
        while (current_value < pivot_date)
        {
            left++;
        }
        int current_value = convert_date_to_int(array[right]);
        while (pivot_date < current_value)
        {
            right--;
        }
        if (right <= left)
        {
            return right;
        }
        TempDate temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
}

void sort_array(TempDate *array, int start, int end)
{
    if (start >= 0 && end >= 0 && start < end)
    {
        int length = end - start;
        int start_date = convert_date_to_int(array[start]);
        int end_date = convert_date_to_int(array[end]);
        if (start_date > end_date)
        {
            TempDate temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
        if (length < 1)
            return;
        int pivot = partition(array, start, end);
        quicksort(array, start, pivot);
        quicksort(array, pivot + 1, end);
    }
}

int convert_date_to_int(TempDate value)
{
    return (((value.year * 100 + value.MM) * 100 + value.dd) * 100 + value.hh) * 100 + value.mm;
}