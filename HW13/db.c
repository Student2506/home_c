#include "db.h"
#include "libintl.h"

#include "temp_api.h"
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

void close_database(sqlite3 *db) { sqlite3_close_v2(db); }