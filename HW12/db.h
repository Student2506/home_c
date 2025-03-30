#include "temp_api.h"
#include <inttypes.h>

#ifndef __DB_H__
#define __DB_H__

void add_record(TempDate[], int *, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, int8_t);
void remove_record(TempDate[], int *, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t);
TempDate *create_array(int);
void sort_array(TempDate *, int, int, int);
void print_array(TempDate *, int);
void drop_array(TempDate *);

#endif /* __DB_H__ */
