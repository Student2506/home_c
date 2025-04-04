#ifndef __PARSER_H__
#define __PARSER_H__
#define PATH_LIMIT 256
#include "temp_api.h"

int count_rows(char *);
void read_file(char *filename, TempDate array[], uint32_t *current_length);

#endif /* __PARSER_H__ */