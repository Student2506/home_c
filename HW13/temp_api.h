#include "sqlite3.h"
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

double average_temp_per_month(sqlite3 *, int, int);
int min_per_month(sqlite3 *, int, int);
int max_per_month(sqlite3 *, int, int);
void print_stat_by_year(TempDate[], int);
void print_stats_per_month(sqlite3 *, int, int);
#endif /* __TEMP_API_H__ */
