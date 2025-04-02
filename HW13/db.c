#include "db.h"
#include "libintl.h"
#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>

static int64_t convert_date_to_int(TempDate);

void add_record(TempDate array[], int *current_length, uint16_t year, uint8_t month, uint8_t day, uint8_t hour,
                uint8_t minute, int8_t temperature) {
  TempDate new_element;
  new_element.year = year;
  new_element.MM = month;
  new_element.dd = day;
  new_element.hh = hour;
  new_element.mm = minute;
  new_element.temperature = temperature;
  array[*current_length] = new_element;
  (*current_length)++;
}

void remove_record(TempDate array[], int *current_length, uint16_t year, uint8_t month, uint8_t day, uint8_t hour,
                   uint8_t minute) {
  int record_to_delete = -1;
  for (int i = 0; i < *current_length; i++) {
    if (array[i].year == year && array[i].MM == month && array[i].dd == day && array[i].hh == hour &&
        array[i].mm == minute) {
      record_to_delete = i;
    }
    if (record_to_delete != -1) {
      // Если текущая запись для удаления последняя, просто уменьшаем размер,
      // иначе смещаемся вверх
      if (i == *current_length - 1)
        break;
      array[i] = array[i + 1];
    }
  }
  (*current_length)--;
}

TempDate *create_array(int intial_size) {
  TempDate *new_array = malloc(intial_size * sizeof(TempDate));
  return new_array;
}

static int partition(TempDate *array, int left, int right, int64_t (*comparator)(const void *, const void *)) {
  TempDate pivot = array[(left + right) / 2];
  while (1) {
    while (comparator(&array[left], &pivot) < 0) { // while array[left] less than pivot
      left++;
    }

    while (comparator(&pivot, &array[right]) < 0) { // while pivot less than array[right]
      right--;
    }
    if (right <= left) {
      return right;
    }
    TempDate temp = array[left];
    array[left] = array[right];
    array[right] = temp;
    left++;
    right--;
  }
}

void sort_array(TempDate *array, int start, int end, int64_t (*comparator)(const void *, const void *)) {
  if (start >= 0 && end >= 0 && start < end) {
    int length = end - start + 1;
    if (comparator(&array[start], &array[end]) > 0) {
      TempDate temp = array[start];
      array[start] = array[end];
      array[end] = temp;
    }
    if (length < 1)
      return;
    int pivot = partition(array, start, end, comparator);
    sort_array(array, start, pivot, comparator);
    sort_array(array, pivot + 1, end, comparator);
  }
}

int64_t comparatorTemp(const void *left, const void *right) {
  return ((TempDate *)left)->temperature - ((TempDate *)right)->temperature;
}

int64_t comparatorDate(const void *left, const void *right) {
  return convert_date_to_int(*(TempDate *)left) - convert_date_to_int(*(TempDate *)right);
}

static int64_t convert_date_to_int(TempDate value) {
  return (((((uint64_t)value.year << 8 | value.MM) << 8 | value.dd) << 8 | value.hh) << 8) | value.mm;
}

void print_array(TempDate *array, int length) {
  printf(_("============ Current stats ==========\n"));
  printf(_("Year  Month  Day  Hour  Minute  Temperature\n"));
  for (int i = 0; i < length; i++) {
    printf("%-5d %-6d %-4d %-5d %-7d %d\n", array[i].year, array[i].MM, array[i].dd, array[i].hh, array[i].mm,
           array[i].temperature);
  }
}

void drop_array(TempDate *array) { free(array); }