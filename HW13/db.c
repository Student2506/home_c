#include "db.h"
#include "libintl.h"

#include "temp_api.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void open_database(char *path, sqlite3 **db) {

  int rc = sqlite3_open_v2(path, db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
  if (rc) {
    fprintf(stderr, _("Can't open database at %s\n%s\n"), path, sqlite3_errmsg(*db));
    return;
  }
}

void clear_database(sqlite3 *db) {
  char *stmt = "DELETE FROM TempDate;";
  sqlite3_exec(db, stmt, NULL, NULL, NULL);
}

void print_array(sqlite3 *db, int type) {
  char *query;
  if (type == 1)
    query = "SELECT * FROM TempDate ORDER BY TEMPERATURE;";
  else if (type == 2)
    query = "SELECT * FROM TempDate ORDER BY YEAR, MONTH, DAY, HOUR, MINUTE;";
  else
    query = "SELECT * FROM TempDate;";
  int rc;
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    printf("Error print_array\n");
    return;
  }
  while (sqlite3_step(stmt) != SQLITE_DONE) {
    int i;
    int num_cols = sqlite3_column_count(stmt);
    for (i = 0; i < num_cols; i++) {
      switch (sqlite3_column_type(stmt, i)) {
      case (SQLITE3_TEXT):
        printf("%s ", sqlite3_column_text(stmt, i));
        break;
      case (SQLITE_INTEGER):
        printf("%4d ", sqlite3_column_int(stmt, i));
        break;
      case (SQLITE_FLOAT):
        printf("%.2f ", sqlite3_column_double(stmt, i));
        break;

      default:
        break;
      }
    }
    printf("\n");
  }
}

void close_database(sqlite3 *db) { sqlite3_close_v2(db); }