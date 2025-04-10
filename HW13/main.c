#include "db.h"
#include "libintl.h"
#include "parser.h"
#include "sqlite3.h"
#include "temp_api.h"
#include <getopt.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 256
#define DATABASE_FILENAME "sensor.db"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  bindtextdomain("sensor_reader", "./");
  textdomain("sensor_reader");
  char verbose = 0;

  char filename[LIMIT] = {'\0'};
  int month = -1;
  char sort_order[LIMIT] = {'\0'};

  int result = 0;
  while ((result = getopt(argc, argv, "hf:m:s:v")) != -1) {
    opterr = 0;
    switch (result) {
    case 'h':
      printf(_("Usage: %s [options]\n"), argv[0]);
      printf(_("-h This help text\n"));
      printf(_("-f Input csv file for processing (mandatory)\n"));
      printf(_("-m Month to show stats about\n"));
      printf(_("-s {date|temp} Sorts data accordinglly\n"));
      printf(_("-v Show file content, with optional sorting.\n"));
      return 0;
    case 'f':
      strcpy(filename, optarg);
      break;
    case 'm':
      month = atoi(optarg);
      break;
    case 's':
      strcpy(sort_order, optarg);
      break;
    case 'v':
      verbose = 1;
      break;
    case '?':
      printf(_("Unknown argument: %s Try -h for help\n"), argv[optind - 1]);
      return 1;
    }
  }
  if (strlen(filename) == 0) {
    printf(_("Filename is mandatory\nTry -h for help\n"));
    return 1;
  }
  printf(_("Processing %s\n"), filename);
  int rows_count = count_rows(filename);
  if (rows_count == -1)
    return 1;
  printf(ngettext("File contains %d row\n", "File contains %d rows\n", rows_count), rows_count);
  // TempDate *array = create_array(rows_count);
  sqlite3 *db = NULL;
  open_database(DATABASE_FILENAME, &db);
  if (db == NULL)
    return 1;
  // clear_database(db);
  uint32_t current_qty = 0;
  read_file(filename, db, &current_qty);
  printf(ngettext("We have read %d line in total\n", "We have read %d lines in total\n", current_qty), current_qty);
  printf("\n\n");
  if (month >= 0) {
    print_stats_per_month(db, 2021, month);
    return 0;
  }
  // if (strcmp(sort_order, "date") == 0)
  //   // sort_array(array, 0, current_qty - 1, comparatorDate); // sort by date
  // if (strcmp(sort_order, "temp") == 0)
  //   sort_array(array, 0, current_qty - 1, comparatorTemp); // sort by temperature

  if (verbose == 1) {
    // print_array(array, current_qty);
    printf("\n\n");
  }
  print_stat_per_year(db);
  // drop_array(array);
  close_database(db);
  return 0;
}