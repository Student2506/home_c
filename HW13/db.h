#ifndef __DB_H__
#define __DB_H__
#include "sqlite3.h"
#include "temp_api.h"
#include <inttypes.h>

// void add_record(TempDate[], int *, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, int8_t);
// void remove_record(TempDate[], int *, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t);
// TempDate *create_array(int);
// void sort_array(TempDate *array, int start, int end, int64_t (*comparator)(const void *, const void *));
void print_array(sqlite3 *, int);
// void drop_array(TempDate *);
// int64_t comparatorTemp(const void *left, const void *right);
// int64_t comparatorDate(const void *left, const void *right);
void open_database(char *, sqlite3 **);
void clear_database(sqlite3 *);
void close_database(sqlite3 *);

#endif /* __DB_H__ */
