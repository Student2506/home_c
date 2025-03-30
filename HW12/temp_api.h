#include <inttypes.h>

#ifndef __TEMP_API_H__
#define __TEMP_API_H__
typedef struct {
  uint16_t year;
  uint8_t MM;
  uint8_t dd;
  uint8_t hh;
  uint8_t mm;
  int8_t temperature;
} TempDate;

float average_temp_per_month(TempDate[], int, int, int);
int min_per_month(TempDate[], int, int, int);
int max_per_month(TempDate[], int, int, int);
void print_stat_by_year(TempDate[], int);
void print_stats_per_month(TempDate[], int, int, int);
#endif /* __TEMP_API_H__ */