#ifndef __PARSER_H__
#define __PARSER_H__
#define PATH_LIMIT 256
#include "sqlite3.h"
#include "temp_api.h"
int count_rows(char *);
void read_file(char *, sqlite3 *, uint32_t *);

#endif /* __PARSER_H__ */