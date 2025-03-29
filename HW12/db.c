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

int partition(TempDate *array, int left, int right, int by_date)
{
    TempDate pivot = array[(left + right) / 2];
    while (1)
    {
        int pivot_value = pivot.temperature;
        int left_value = array[left].temperature;
        int right_value = array[right].temperature;
        if (by_date == 1)
        {
            pivot_value = convert_date_to_int(pivot);
            left_value = convert_date_to_int(array[left]);
            right_value = convert_date_to_int(array[right]);
        }
        while (left_value < pivot_value)
        {
            left++;
        }

        while (pivot_value < right_value)
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

void sort_array(TempDate *array, int start, int end, int by_date)
{
    if (start >= 0 && end >= 0 && start < end)
    {
        int length = end - start;
        int start_value = array[start].temperature;
        int end_value = array[end].temperature;
        if (by_date == 1)
        {
            start_value = convert_date_to_int(array[start]);
            end_value = convert_date_to_int(array[end]);
        }
        if (start_value > end_value)
        {
            TempDate temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
        if (length < 1)
            return;
        int pivot = partition(array, start, end, by_date);
        quicksort(array, start, pivot, by_date);
        quicksort(array, pivot + 1, end, by_date);
    }
}

int convert_date_to_int(TempDate value)
{
    return value.year << 16 | value.MM << 8 | value.dd << 8 | value.hh << 8 | value.mm;
}

void print_array(TempDate *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(
            "%d %d %d %d %d %d\n",
            array[i].year,
            array[i].MM,
            array[i].dd,
            array[i].hh,
            array[i].mm,
            array[i].temperature);
    }
}