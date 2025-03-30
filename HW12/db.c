#include "db.h"
#include "libintl.h"
#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>

#define _(STRING) gettext(STRING)

static uint64_t convert_date_to_int(TempDate);

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

static int partition(TempDate *array, int left, int right, int by_date) {
  TempDate pivot = array[(left + right) / 2];
  while (1) {
    uint64_t pivot_value = pivot.temperature;
    uint64_t left_value = array[left].temperature;
    uint64_t right_value = array[right].temperature;
    if (by_date == 1) {
      pivot_value = convert_date_to_int(pivot);
      left_value = convert_date_to_int(array[left]);
      right_value = convert_date_to_int(array[right]);
    }

    while (left_value < pivot_value) {
      left++;
      pivot_value = pivot.temperature;
      left_value = array[left].temperature;
      if (by_date == 1) {
        pivot_value = convert_date_to_int(pivot);
        left_value = convert_date_to_int(array[left]);
      }
    }

    while (pivot_value < right_value) {
      right--;
      pivot_value = pivot.temperature;
      right_value = array[right].temperature;
      if (by_date == 1) {
        pivot_value = convert_date_to_int(pivot);
        right_value = convert_date_to_int(array[right]);
      }
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

void sort_array(TempDate *array, int start, int end, int by_date) {
  if (start >= 0 && end >= 0 && start < end) {
    int length = end - start;
    uint64_t start_value = array[start].temperature;
    uint64_t end_value = array[end].temperature;
    if (by_date == 1) {
      start_value = convert_date_to_int(array[start]);
      end_value = convert_date_to_int(array[end]);
    }
    if (start_value > end_value) {
      TempDate temp = array[start];
      array[start] = array[end];
      array[end] = temp;
    }
    if (length < 1)
      return;
    int pivot = partition(array, start, end, by_date);
    sort_array(array, start, pivot, by_date);
    sort_array(array, pivot + 1, end, by_date);
  }
}

static uint64_t convert_date_to_int(TempDate value) {
  uint64_t new_value = value.year << 8;
  new_value = (new_value | value.MM) << 8;
  new_value = (new_value | value.dd) << 8;
  new_value = (new_value | value.hh) << 8;
  new_value |= value.mm;
  return new_value;
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